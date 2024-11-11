#include<stdio.h>
int main(){
	int  a,b,c;
	int flag = 0;
	scanf("%d %d %d",&a,&b,&c);
	for(i=a;i<=b;i++){
		if((c%i)==0)flag++;
	}
	printf("%d\n",flag);
	return 0;	
}