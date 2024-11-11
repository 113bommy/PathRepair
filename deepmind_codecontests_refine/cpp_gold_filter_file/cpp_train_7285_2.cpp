#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
	cin >> n >> m;
	int l = (n - 1) / 2;
	for(int i = 0; i < l; i++) printf(i ? " %d" : "%d", 0);
	for(int i = l; i < n; i++) printf(i ? " %d" : "%d", m);
	printf("\n");
	return 0;
}