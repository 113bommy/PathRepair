#include<cstdio>
using namespace std;

int main() {
	int a, b,c;
	scanf("%d %d %d", &b, &a,&c);
	if (b >= c) printf("0\n");
	else if(a+b>=c) printf("%d\n", c-b);
	else printf("NA\n");
	return 0;
}