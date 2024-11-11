#include<stdio.h>
#include<string.h>
int main(){
  int l,c=0;
  char s[100];
  scanf("%s",s);
  l=strlen(s);
  if(s[0]=='A' && s[l-1]>='a' && s[l-1]<='z' && s[1]>='a' && s[1]<='z'){
    for(int i=2;i<=l-2;i++){
      if(s[i]=='C') c++;
    }
    if(c==1) puts("AC");
    else puts("WA");
  }
    else puts("WA");
    return 0;
}
