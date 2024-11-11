#include<stdio.h>
int main(void)
{
	int w,n,z,x,i,k,c;
	while(1){
		scanf("%d",&n);
		 if(n==0) break;
	c=0;
	k=0;	 
	for(i=0;i<12;i++){
			scanf("%d %d",&z,&x);
			k+=z-x;
			if(k>=n){
				c++
			}
	}
	if(k<n){
		printf("NA\n");
	}
	else{
		printf("%d\n",12-c+1);
	}
    }	
	return 0;
}