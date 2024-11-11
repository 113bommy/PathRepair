#include<stdio.h>
int main(void)
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a==1&&b==1&&c==0){
		printf("Open\n");
		return 0;
	}
	if(a==0&&b==0&&c==1){
		printf("Open\n");
		return 0;
	}
	printf("Close\n");
	return 0;
}