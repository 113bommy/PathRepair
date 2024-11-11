#include<cstdio>
#include<cmath>

int main(){
	int a,b;
	while(scanf_s("%d %d",&a,&b) != EOF)
		printf_s("%d\n",(int)log10((double)a+b)+1);
}