#include <bits/stdc++.h>
using namespace std;
mt19937_64 rnd(time(NULL));
const long long mod = 1000000007;
const int N = 1010;
int a[N][N];
int cnt[N][N][2];
int ans = 0;
int n, m, q;
inline void calc(int i, int j) {
  if (i <= 0 || j <= 0 || i > n || j > m) return;
  ans -= cnt[i][j][0] + cnt[i][j][1];
  if (a[i][j])
    cnt[i][j][0] = cnt[i][j][1] = 0;
  else {
    cnt[i][j][0] = cnt[i - 1][j][1] + 1;
    cnt[i][j][1] = cnt[i][j - 1][0] + 1;
  }
  ans += cnt[i][j][0] + cnt[i][j][1];
}
void solve() {
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      calc(i, j);
      ans--;
    }
  }
  for (int it = 1; it <= q; it++) {
    int x, y;
    cin >> x >> y;
    ans += 1 - a[x][y];
    a[x][y] ^= 1;
    ans -= 1 - a[x][y];
    for (int i = 0; i <= min(n - x, n - y); i++) {
      calc(x + i, y + i);
      calc(x + i + 1, y + i);
      calc(x + i, y + i + 1);
    }
    cout << ans << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}
