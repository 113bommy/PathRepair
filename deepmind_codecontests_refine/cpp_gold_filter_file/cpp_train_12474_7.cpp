#include<stdio.h>
int main(){
int i,w;
char s[10001];
  scanf("%s",s);
  scanf("%d",&w);
  for(i=0;s[i]!='\0';i+=w){
   printf("%c",s[i]);
  }
  return 0;
}