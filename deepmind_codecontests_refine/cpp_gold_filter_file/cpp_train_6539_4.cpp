#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		if (x & 1) {
			printf("first\n"); 
			return 0;
		}
	}
	printf("second\n");
}