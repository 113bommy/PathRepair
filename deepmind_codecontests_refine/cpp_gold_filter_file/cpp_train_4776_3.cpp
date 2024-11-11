#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
	char ss[101];
	int i,c;
	c=0;
	while(0<=scanf("%s",ss)){
		for(i=0;i<=strlen(ss)-1;i++){
			if(ss[i]!=ss[strlen(ss)-i-1])break;
		}
		
		if(i==strlen(ss))++c;
	}
	printf("%d\n",c);
	return 0;
}