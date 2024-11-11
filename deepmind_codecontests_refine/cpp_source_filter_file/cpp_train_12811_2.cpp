#include<cstdio>

int main(){
	int x;
	int n = 1;
	while(){
		scanf("%d", &x);
		if(x == 0) break;
		printf("Case %d: %d", n, x);
		n++;
	}

	return 0;
}