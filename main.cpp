#include<iostream>
#include<vector>
#include "hangman_func.h"
using namespace std;

// HANGMAN GAME: need to guess a codeword by guessing letters within a limited amount of guesses
int main(){
    greet();

    string codeWord = "game";
    string answer = "____";

    int misses=0;
    vector<char> incorrect;
    bool guess = false;
    char letter;

    while(answer!=codeWord && misses<7){
        display_misses(misses);
        display_status(incorrect, answer);

        cout<<"\n\nEnter your guess: ";
        cin>>letter;
        for(int i=0;i<codeWord.length();i++){
            if(letter==codeWord[i]){
                answer[i]=letter;
                guess=true;
            }
        }
        if(guess){
            cout<<"\nCorrect!\n";
        }
        else{
            cout<<"\nIncorrect! You've lost a chance :(\n";
            incorrect.push_back(letter);
            misses++;
        }
        guess=false;
    }

    if(answer==codeWord){
        cout<<"\n YAY, YOU WON!!\n";
    }
    else{
        cout<<"\nBETTER LUCK NEXT TIME..\n";
    }

    return 0;
}