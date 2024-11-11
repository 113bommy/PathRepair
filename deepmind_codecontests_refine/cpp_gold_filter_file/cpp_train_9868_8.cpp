#include<cstdio>
int a,b;
int main(){
	scanf("%d%d",&a,&b);
  	printf("%d\n",(a<10?100*(10-a):0)+b);
  	return 0;
}
