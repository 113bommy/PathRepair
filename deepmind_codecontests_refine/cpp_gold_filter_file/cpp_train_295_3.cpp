#include <cstdio>
using namespace std;

int main(){
	int a, b, c, ans1=0, ans2=0;

	while( scanf("%d,%d,%d", &a,&b,&c) != EOF ){
		if( a*a + b*b == c*c ) ans1++;
		else if( a == b ) ans2++;
	}
	printf("%d\n%d\n", ans1, ans2);
}