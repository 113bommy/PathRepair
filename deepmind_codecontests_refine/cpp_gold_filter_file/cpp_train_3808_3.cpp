#include <bits/stdc++.h>
using namespace std;
long long n, m, l, ans, c, cc, mx, a[55][5005], b[250005], best_prefix[55],
    best_suffix[55], best_mid[55], sum[55], mem[250005][3];
bool flag;
long long solve(long long p = 0, bool token = 0) {
  if (p == m) return -1e18;
  if (mem[p][token] > -1e18) return mem[p][token];
  if (token)
    mem[p][token] = max(best_prefix[b[p]], sum[b[p]] + solve(p + 1, 1));
  else
    mem[p][token] =
        max(best_mid[b[p]],
            max(solve(p + 1, 0), best_suffix[b[p]] + solve(p + 1, 1)));
  return mem[p][token];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    cin >> l;
    c = cc = 0;
    flag = 0;
    mx = -1e18;
    for (long long j = 0; j < l; j++) {
      cin >> a[i][j];
      mx = max(mx, a[i][j]);
      c += a[i][j];
      if (c > -1)
        flag = 1;
      else
        c = 0;
      cc = max(cc, c);
    }
    if (!flag) cc = mx;
    best_mid[i] = cc;
    c = 0;
    best_prefix[i] = 0;
    flag = 0;
    for (long long j = 0; j < l; j++) {
      c += a[i][j];
      if (c >= best_prefix[i]) {
        best_prefix[i] = c;
        flag = 1;
      }
    }
    sum[i] = c;
    if (!flag) best_prefix[i] = -1e14;
    c = 0;
    best_suffix[i] = 0;
    flag = 0;
    for (long long j = l - 1; ~j; j--) {
      c += a[i][j];
      if (c >= best_suffix[i]) {
        best_suffix[i] = c;
        flag = 1;
      }
    }
    if (!flag) best_suffix[i] = -1e14;
  }
  for (long long i = 0; i < m; i++) {
    cin >> b[i];
    b[i]--;
  }
  for (long long i = 0; i < 250005; i++)
    for (long long j = 0; j < 3; j++) mem[i][j] = -1e18;
  cout << solve();
  return 0;
}
