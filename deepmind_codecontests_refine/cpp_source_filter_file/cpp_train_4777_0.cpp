#include<stdio.h>
#include<string.h>
int main(void)
{
	int a[5],b[5],d,i,j;
	char c[5]="ABCDE";
	scanf("%d %d",&a[0],&b[0]);
	while(a[0]!=0 || b[0]!=0){
		j=0; d=a[0]+b[0];
		for(i=1;i<5;i++){
			scanf("%d %d",&a[i],&b[i]);
			if(a[i]+b[i]>d){
				d=a[i]+b[i]; j=i;
			}
		}
		printf("%c %d\n",c[j],d);
		scanf("% %d",&a[0],&b[0]);
	}
	return 0;
}