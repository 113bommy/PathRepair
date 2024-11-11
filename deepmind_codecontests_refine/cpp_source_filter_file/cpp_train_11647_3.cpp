#include<stdio.h>
int main(){
char s[111111];
int i,a=-1,b=-1;
for(i=0;i<111111;i++)
s[i]='\0';
scanf("%s",s);
if(s[0]==s[1]){
a=1;
b=2;
for(i=2;s[i]!='\0';i++){
if(s[i]==s[i-1]){
a=i;
b=i+1;
}
if(s[i]==s[i-2]){
a=i-1;
b=i+1;
}
}
printf("%d %d\n",a,b);
return 0;
}