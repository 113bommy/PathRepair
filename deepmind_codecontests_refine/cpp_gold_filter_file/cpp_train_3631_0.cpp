#include<stdio.h>
int main(void)
{
	int n,a;
	scanf("%d",&n);
	while(n!=0){
		a=0;
		while(n!=1){
			if(n%2==0)  n=n/2;
			else  n=n*3+1;
			a++;
		}
		printf("%d\n",a);
		scanf("%d",&n);
	}
	return 0;
}