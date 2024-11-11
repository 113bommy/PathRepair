#include<stdio.h>
char s[4];
int t=0;
int main(){
	scanf("%a",&s);
  	for(int k=0;k<4;k++){
    	if(s[k]=="+")t++;
    	else if(s[k]=="-")t--;
    }
  	printtf("%d",t);
  	return 0;
}
