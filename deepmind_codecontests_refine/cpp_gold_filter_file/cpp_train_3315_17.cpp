#include<cstdio>
#include<cstring>
int main() {
	int a,b;
	while(~scanf("%d%d",&a,&b)) {
		if(a%3==0||b%3==0||(a+b)%3==0) puts("Possible");
		else puts("Impossible");
	}
	return 0;
}