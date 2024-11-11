#include<stdio.h>
int main()
{
	int n,d[50],i,j,x;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&d[i]);
	}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(d[i]*d[j])
				x+=d[i]*d[j];
			}
		}
	}
	printf("%d\n",x);
	return 0;
}
