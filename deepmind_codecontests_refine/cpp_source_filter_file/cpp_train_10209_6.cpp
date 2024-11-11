#include<stdio.h>
int main(void){

int H,W,i,t;

for(;;){
scanf("%d %d",&H,&W);

if(H==0&&W==0){
break;
}


	for(i=1;i<=H;i++){
		
		for(t=1;t<=W;t++){
			printf("#");
		}

		printf("\n");
	}
	print("\n");
}

 return 0;
}