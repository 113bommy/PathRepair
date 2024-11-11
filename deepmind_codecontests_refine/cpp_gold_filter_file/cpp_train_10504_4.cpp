#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	printf("%d\n",a-max((b+d-1)/d,(c+e-1)/e));
}