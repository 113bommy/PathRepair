#include<stdio.h>
char a[100010];
int main(){
	int s=0
	scanf("%s",a);
	for(i=0;a[i]!='\0';i++){
		if(a[i]=='g')s++;
	}
	printf("%d",s-(i+1)/2);
}