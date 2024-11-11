#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#define int long long
#define mod 1000000007
using namespace std;
int n, m;
int pt[123456], a[123456], ans;
set<int>s; vector<int>v[123456], v1;
void f() {
	for (int i = 0; i < n; i++)pt[i] = i;
	return;
}
int root(int i) {
	if (pt[i] == i)return i;
	else return pt[i] = root(pt[i]);
}
void unite(int a, int b) {
	pt[root(b)] = root(a);
	root(b);
	return;
}
signed main() {
	cin >> n >> m;
	if ((n - 1 - m) * 2 > n) {
		cout << "Impossible\n";
		return 0;
	}
	if (n - 1 == m) {
		cout << "0\n";
		return 0;
	}
	f();
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		unite(x, y);
	}
	for (int i = 0; i < n; i++) {
		s.insert(root(i));
		v[pt[i]].push_back(a[i]);
	}
	for (auto i = s.begin(); i != s.end(); i++) {
		sort(v[*i].begin(), v[*i].end());
		ans += v[*i][0];
		for (int j = 1; j < v[*i].size(); j++)v1.push_back(v[*i][j]);
	}
	sort(v1.begin(), v1.end());
	for (int i = 0; i < max((int)0, (n - 1 - m) * 2 - s.size()); i++)ans += v1[i];
	cout << ans << endl;
}