#include<stdio.h>

int main(){
	int a;
	
	scanf("%d",&a);
	
	if(a%10==9 || a/10==9){
		printf("Yes\n");
	}
	else printf("No\n");
	
	return 0;
}