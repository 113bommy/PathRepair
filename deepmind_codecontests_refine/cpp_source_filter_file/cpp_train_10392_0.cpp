#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, X[1000], Y[1000];
	cin >> N;
	for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
	for (int i = 0; i < N - 1; i++) {
		if (abs(X[i] + Y[i]) % 2 != abs(X[i + 1] + Y[i + 1]) % 2) {
			cout << -1 << endl;
			return 0;
		}
	}
	if (abs(X[0] + Y[0]) % 2 == 0) {
		cout << 32 << endl << 1;
		for (int i = 0; i < 31; i++) {
			cout << " " << (1 << i);
		}
		cout << endl;
	}
	else {
		cout << 31 << endl;
		for (int i = 0; i < 31; i++) {
			cout << (1 << i);
			if (i == 30) cout << endl;
			else cout << " ";
		}
	}
	for (int i = 0; i < N; i++) {
		long long U = X[i] + Y[i], V = X[i] - Y[i];
		if (U % 2 == 0) {
			cout << 'L';
			U--, V--;
		}
		U = ((1LL << 32 - 1) - U) / 2, V = ((1LL << 32 - 1) - V) / 2;
		for (int i = 0; i < 31; i++) {
			long long UB = U % 2, VB = V % 2;
			U /= 2, V /= 2;
			if (UB == 0 && VB == 0) cout << 'R';
			if (UB == 0 && VB == 1) cout << 'U';
			if (UB == 1 && VB == 0) cout << 'D';
			if (UB == 1 && VB == 1) cout << 'L';
		}
		cout << endl;
	}
