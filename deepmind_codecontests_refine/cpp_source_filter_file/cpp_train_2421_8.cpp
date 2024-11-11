#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, q, ans = 1e9, f[N][2];
char u[N], d[N], l[N], r[N];
void solve(int n, int m, char *u, char *d, char *l, char *r) {
  f[1][0] = f[1][1] = 0;
  for (int i = 1; i <= n; i++) ++f[1][l[i] == 'R'];
  ++f[1][u[1] == 'R'];
  ++f[1][d[1] == 'R'];
  for (int i = 2; i <= m; i++) {
    f[i][0] = min(f[i - 1][0], f[i - 1][1] + n) + (u[i] != 'R') + (d[i] != 'R');
    f[i][1] = min(f[i - 1][0] + n, f[i - 1][1]) + (u[i] != 'B') + (d[i] != 'B');
  }
  int cnt[2];
  cnt[0] = cnt[1] = 0;
  for (int i = 1; i <= n; i++) ++cnt[r[i] == 'B'];
  ans = min(ans, min(f[n][0] + cnt[1], f[n][1] + cnt[0]));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q >> (l + 1) >> (r + 1) >> (u + 1) >> (d + 1);
  solve(n, m, u, d, l, r);
  solve(m, n, l, r, u, d);
  cout << ans;
  return 0;
}
