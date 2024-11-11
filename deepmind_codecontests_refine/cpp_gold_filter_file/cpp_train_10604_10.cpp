#include<stdio.h>
#include<string.h>
int main(){
char s[20];
char s2[20]="CODEFESTIVAL2016";
int ans=0;
scanf("%s",s);
for (int i=0;i<16;i++)
   if (s[i]!=s2[i]) ans++;
printf("%d",ans);
return 0;
}