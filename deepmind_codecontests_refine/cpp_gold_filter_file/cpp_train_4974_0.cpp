#include<iostream>
#include<cstdio>
using namespace std;
int main(){
  int day;
  int cost[30];
  int satisfied[370][30];
  int i,j;
  
  scanf("%d",&day);
  
  for(i=0;i<26;i++){
    scanf("%d ",&cost[i]);
  }
  
  for(i=0;i<day;i++){
    for(j=0;j<26;j++){
      cin>>satisfied[i][j];
    }
  }
  
  for(i=0;i<day;i++){
    printf("%d\n",i%26+1);
  }
  return(0);
}