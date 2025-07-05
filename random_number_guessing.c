#include<stdio.h>
#include<stdlib.h> //For random number generation
#include<time.h>
int main()
{
    int randomNumber=0;
    int guess=0; 
    int numberOfGuesses;
    time_t t;
    //Initialization of random number generator
    srand((unsigned) time(&t));
    // Get the random number
    randomNumber=rand() %21; //This ensures that the random number is between 0 and 20
    printf("This is a guessing game.\n");
    printf("I have chosen a number between 0 and 20, which you must guess.\n");
    for(numberOfGuesses=5;numberOfGuesses>0;numberOfGuesses--)
    {
        printf("You have %d tr%s left\n",numberOfGuesses,numberOfGuesses==1?"y":"ies");
        printf("\nEnter a guess:\t");
        scanf("%d",&guess);
        if(guess==randomNumber)
        {
            printf("Congratulations! You guessed it\n");
            break; 
        }
        else if(guess<0 || guess>20)
        {
            printf("%d is invalid. Please enter a number between 0 and 20\n",guess);
        }
        else if(randomNumber>guess)
        {
            printf("Sorry %d is wrong. My number is greater than that\n",guess);
        }
        else if(randomNumber<guess)
        {
            printf("Sorry %d is wrong. My number is less than that\n",guess);
        }
    }
    if(numberOfGuesses<1)
        printf("\nSorry, you ran out of chances. The number was %d\n",randomNumber);
    return 0;
}
           