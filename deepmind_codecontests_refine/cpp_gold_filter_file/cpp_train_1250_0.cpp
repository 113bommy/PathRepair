#include <iostream>
#include <algorithm>
using namespace std;
int n, a[111111];
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	int x = a[n - 1], z = -1;
	for(int i = 0; i < n - 1; i++) {
		if(a[i] <= x) {
			swap(a[++z], a[i]);
		}
	}
	swap(a[++z], a[n - 1]);
	for(int i = 0; i < n; i++) {
		printf(i == z ? "[%d]" : "%d", a[i]);
		printf(i + 1 == n ? "\n" : " ");
	}
}