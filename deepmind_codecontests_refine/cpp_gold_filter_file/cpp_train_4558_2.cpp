#include "bits/stdc++.h"
using namespace std;
int main() {
	int N;
	cin >> N;
	long long V = 0;
	long long E = 0;
	for (int i = 1; i <= N; ++i) {
		V += (long long)i*(N - i + 1);
	}
	for (int n = 0; n < N - 1; ++n) {
		int a, b;
		cin >> a >> b;
		if (a>b) {
			swap(a, b);
		}
		E += (long long)a*(N - b + 1);
	}
	long long ans = V - E;
	cout << ans << endl;
	return 0;
}
