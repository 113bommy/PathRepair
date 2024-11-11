#include <bits/stdc++.h>
const int N = 1e5 + 7;
const long long mod = 1e9 + 7;
using namespace std;
int n;
int m;
long long mp[111][111], a[111], b[111], r[111], c[111];
long long ans[111][111];
int solve() {
  for (int i = 1; i <= m - 1; ++i) {
    if (c[i] == 0)
      for (int j = 1; j <= n; ++j) mp[j][i] = c[i];
    else {
      mp[1][i] = 1;
      for (int j = 2; j <= n; ++j) mp[j][i] = 0;
    }
  }
  for (int i = 1; i <= n; ++i) {
    long long x = 0;
    for (int j = 1; j <= m - 1; ++j) x ^= mp[i][j];
    if (x == r[i])
      mp[i][m] = 0;
    else
      mp[i][m] = 1;
  }
  long long x = 0;
  for (int i = 1; i <= n; ++i) x ^= mp[i][m];
  if (x == c[m]) return 1;
  for (int i = 1; i <= n - 1; ++i) {
    if (!r[i])
      for (int j = 1; j <= m; ++j) mp[i][j] = r[i];
    else {
      mp[i][1] = 1;
      for (int j = 2; j <= m; ++j) mp[i][j] = 0;
    }
  }
  for (int i = 1; i <= m; ++i) {
    long long x = 0;
    for (int j = 1; j <= n - 1; ++j) x ^= mp[j][i];
    if (x == c[i])
      mp[n][i] = 0;
    else
      mp[n][i] = 1;
  }
  x = 0;
  for (int i = 1; i <= m; ++i) x ^= mp[n][i];
  if (x == r[n]) return 1;
  return -1;
}
int tmp[111];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%I64d", &a[i]);
  for (int i = 1; i <= m; ++i) scanf("%I64d", &b[i]);
  for (int x = 0; x <= 4; ++x) {
    for (int i = 1; i <= n; ++i) r[i] = !!(a[i] & (1 << x));
    for (int i = 1; i <= m; ++i) c[i] = !!(b[i] & (1 << x));
    int t = solve();
    if (t == -1) {
      return puts("NO"), 0;
    }
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) {
        ans[i][j] += (mp[i][j] << x);
      }
  }
  puts("YES");
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) printf("%I64d ", ans[i][j]);
    puts("");
  }
  return 0;
}
