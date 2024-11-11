#include<cstdio>
#include<cmath>

int main(){
	int a,b;
	while(scanf("%d %d",&a,&b) != EOF)
		printf("%d\n",(int)log10((double)a+b)+1);
}