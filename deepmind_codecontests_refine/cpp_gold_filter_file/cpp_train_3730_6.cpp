#include<stdio.h>
char a[3];
int i=0;
int main(){
	scanf("%s",&a);
  	for(int k=0;k<3;k++){
      	if(a[k]=='o')i++;
    }
  	printf("%d",i*100+700);
  	return 0;
}
