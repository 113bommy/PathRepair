#include<cstdio>

using namespace std;

int main(){
	int n;
	while (1){
		int A = 0, B = 0;
		scanf_s("%d", &n);
		if (n == 0)return 0;
		for (int i = 0; i < n; i++){
			int a, b;
			scanf_s("%d %d", &a, &b);
			if (a > b){
				a += b;
				b = 0;
			}
			if (a < b){
				b += a;
				a = 0;
			}
			A += a;
			B += b;
		}
		printf("%d %d\n", A, B);
	}
}