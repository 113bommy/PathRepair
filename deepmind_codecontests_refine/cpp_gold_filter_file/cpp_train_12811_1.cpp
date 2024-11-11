#include <stdio.h>

int main(){
	int i=0;
	int x;
	while(1){
		i++;
		scanf("%d ",&x);
		if(x==0){break;}
		
		printf("Case %d: %d\n",i,x);
	}
	return 0;
}