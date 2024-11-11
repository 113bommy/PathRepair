#include <bits/stdc++.h>
using namespace std;

int main() {
	int D, N;
	cin >> D >> N;
	int ans = pow(100, D) * (N + (N == 100));

	cout << ans << "\n";
}
