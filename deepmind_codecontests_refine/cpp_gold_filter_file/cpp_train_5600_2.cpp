#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> A, B;
int memo[1<<18][51];
bool visited[1<<18][51];
const int INF = 1<<29;
vector<int> aa;
int f(int p, int n, int m) {
	if (p == N) {
		return 0;
	}
	if (visited[n][m]) return memo[n][m];
	visited[n][m] = true;
	int r = INF;
	for (int i = 0; i < N; ++ i) if (((n>>i)&1)==0) {
		int qq = abs(p-i) % 2;
		int x = (qq == 0) ? A[i] : B[i];
		if (x < m) continue;
		int k = 0;
		for (int j = i+1; j < N; ++ j) if ((n>>j)&1) ++ k;
		aa.push_back(i);
		r = min(r, f(p+1, n | (1<<i), x) + k);
		aa.pop_back();
	}
	return memo[n][m] = r;
}
int main() {
	cin >> N;
	A.resize(N);
	B.resize(N);
	for (auto& x : A) cin >> x;
	for (auto& x : B) cin >> x;
	int r = f(0, 0, 0);
	if (r >= INF) cout << -1 << endl;
	else cout << r << endl;
}
