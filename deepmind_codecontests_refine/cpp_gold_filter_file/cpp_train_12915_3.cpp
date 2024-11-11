#include<iostream>
#include<cstdio>
#include<cctype>
using namespace std;
int main(){
    char ch;
    int count[26]= {};
    while(cin >> ch){
        ch = tolower(ch);
        if(isalpha(ch)){
            count[ch-'a']++;
        }
    }
    for(int i=0;i<26;i++){
        printf("%c : %d\n",i+'a',count[i]);
    }
}
