#include<stdio.h>

int main(void){
	
	while(1){
		int n;
		int p1,p2;
		scanf("%d",&n);
		if(n==0){
			break;
		}
		p1=p2=0;
		for(int i=0;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			if(a>b){
				p1+=a+b;
			}else if(a<b){
				p2+=a+b;
			}else{
				p1+=a;
				p2+=b;
			}
		}
		printf("%d %d\n",a,b);
	}
	return 0;
}