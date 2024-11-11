#include<iostream>
#include<algorithm>
using namespace std;

main(){
  char S[10];
  scanf("%s",S);
  
  sort(S,S+4);
  printf((S[0]==S[1] && S[1]!=S[2] && S[2]==S[3]) ? "Yes\n" : "No\n")
} 