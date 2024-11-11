#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int (i)=0;i<(int)(n);i++)
#define all(hoge) (hoge).begin(),(hoge).end()
typedef vector<int> Array;

int l[20][202020];
int r[20][202020];
int dp1[20][202020];
int dp2[20][202020];

int main() {
	int n, k;
	cin >> n >> k;
	Array x(n);
	REP(i, n)cin >> x[i];
	REP(i, n)dp1[0][i] = l[0][i] = lower_bound(all(x), x[i] + k) - x.begin();
	REP(i, n)dp2[0][i] = r[0][i] = upper_bound(all(x), x[i] - k) - x.begin() - 1;
	REP(i, 19)REP(j, n)l[i + 1][j] = l[i][min(n - 1, l[i][j])];
	REP(i, 19)REP(j, n)r[i + 1][j] = r[i][max(0, r[i][j])];
	REP(i, 19)REP(j, n)dp1[i + 1][j] = dp1[i][j] + dp1[i][l[i][j]];
	REP(i, 19)REP(j, n)dp2[i + 1][j] = dp2[i][j] + dp2[i][r[i][j]];
	int q;
	cin >> q;
	while (q--) {
		int L, R;
		cin >> L >> R;
		L--;
		int ans = R - L;
		int x = L, y = R - 1;
		for (int i = 19; i >= 0; i--) {
			if (l[i][x] < R)ans += (1 << i) - dp1[i][x], x = l[i][x];
			if (r[i][y] >= L)ans += dp2[i][y], y = r[i][y];
		}
		cout << ans << "\n";
	}
	return 0;
}
