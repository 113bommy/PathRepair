#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, a;
	cin >> N;
	int k = 1;

	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a == k) {
			k++;
		}
	}
	if (k == 1) {
		cout << -1 << endl;
	}
	else {
		cout << n - k + 1 << endl;
	}
}