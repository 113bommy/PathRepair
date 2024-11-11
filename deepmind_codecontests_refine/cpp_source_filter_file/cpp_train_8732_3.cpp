#include<stdio.h>
int main(){
int i,a,b,c,d,n,e;
	scanf("%d",&n);
	for(i=0;i<n;i++){
	scanf("%d %d %d %d",&a,&b,&c,&d);
	e=a*c+b*d;
	if(d<2&&c<5){
		if((a*5+b*2)*0.8<e) e=(a*5+b*2)*0.8; 
	}
	else if(c<5){
		if((a*5+b*d)*0.8<e) e=(a*5+b*d)*0.8; 
	}
	else if(d<2){
		if((a*c+b*2)*0.8<e) e=(a*c+b*2)*0.8; 
	}
	else
		e=(a*c+b*d)*0.8; 
	}
	printf("%d\n",e);
	}
	return 0;
}