#include<stdio.h>
int main(void)
{
	int i,x,w,n,flg;
	while(1)	{
	flg=0;
		scanf("%d",&n);
		if(n==0)	break;
		w=n;
		for(i=0;i<n;i++){
			scanf("%d",&x);
			if(x==0){
			w=w-1;
			}
			if(x>=2){
			flg=1;
			}
		}
		if(flg==1){
		printf("%d\n",x+1)
		}
		else{
			printf("NA\n");
			}
		}	
	return 0;
}