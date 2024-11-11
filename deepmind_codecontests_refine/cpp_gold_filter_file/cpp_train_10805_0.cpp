#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define rip(i,n,s) (int i=(s);i<(int)(n);i++)
int n;

void dfs(vector<int> &day, vector<int> &co, vector<vector<int>> &da, int gg) {
	if (co[gg] == n - 1) {
		return;
	}
	int x = da[gg][co[gg]];
	if (co[x] == n - 1) {
		return;
	}
	if (da[x][co[x]] == gg) {
		co[x]++;
		co[gg]++;
		day[x] = max(day[x], day[gg]) + 1;
		day[gg] = day[x];
		dfs(day, co, da, gg);
		dfs(day, co, da, x);
	}
}

int main() {
	cin >> n;
	vector<vector<int>> da(n, vector<int>(n - 1));
	for rip(i, n, 0) {
		for rip(j, n - 1, 0) {
			cin >> da[i][j];
			da[i][j]--;
		}
	}
	vector<int> day(n, 0), co(n, 0);
	int ma = n * (n - 1) / 2;
	for rip(i, n, 0) {
		dfs(day, co, da, i);
	}
	for rip(i, n, 0) {
		if (co[i] != n - 1) {
			cout << -1 << endl;
			return 0;
		}
	}
	int ans = 0;
	for rip(i, n, 0) {
		ans = max(ans, day[i]);
	}
	cout << ans << endl;
}
