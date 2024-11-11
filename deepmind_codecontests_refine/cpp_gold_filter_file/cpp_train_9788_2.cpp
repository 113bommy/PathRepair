#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long n, k, l, r, a[40], pos;
vector<long long>p[30], q[30];
int main() {
	cin >> n >> k >> l >> r; pos = n / 2;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < (1 << pos); i++) {
		long long R = 0; for (int j = 0; j < pos; j++) { if ((i / (1 << j)) % 2 == 1) { R += a[j]; } }
		p[__builtin_popcount(i)].push_back(R);
	}
	for (int i = 0; i < (1 << (n - pos)); i++) {
		long long R = 0; for (int j = 0; j < n - pos; j++) { if ((i / (1 << j)) % 2 == 1) { R += a[j + pos]; } }
		q[__builtin_popcount(i)].push_back(R);
	}
	for (int i = 0; i < 30; i++)sort(p[i].begin(), p[i].end());
	for (int i = 0; i < 30; i++)sort(q[i].begin(), q[i].end());
	long long cnts = 0;
	for (int i = 0; i <= pos; i++) {
		int V = k - i; if (V < 0)continue;
		for (int j = 0; j < p[i].size(); j++) {
			int pos1 = lower_bound(q[V].begin(), q[V].end(), l - p[i][j]) - q[V].begin();
			int pos2 = lower_bound(q[V].begin(), q[V].end(), r + 1 - p[i][j]) - q[V].begin();
			cnts += pos2 - pos1;
		}
	}
	cout << cnts << endl;
	return 0;
}