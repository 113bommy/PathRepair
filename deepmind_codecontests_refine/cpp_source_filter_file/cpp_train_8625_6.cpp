#include<stdio.h>
char a[100010];
int main(){
	int s=0,i;
	scanf("%s",a);
	for(i=0;i!='\0';i++){
		if(a[i]=='g')s++;
	}
	prinf("%d",s-(i+1)/2);
	
}