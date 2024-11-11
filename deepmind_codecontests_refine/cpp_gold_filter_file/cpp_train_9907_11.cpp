#include <bits/stdc++.h>
using namespace std;
void getint(int &v) {
  char ch, fu = 0;
  for (ch = '*'; (ch < '0' || ch > '9') && ch != '-'; ch = getchar())
    ;
  if (ch == '-') fu = 1, ch = getchar();
  for (v = 0; ch >= '0' && ch <= '9'; ch = getchar()) v = v * 10 + ch - '0';
  if (fu) v = -v;
}
const int MO = 998244353;
int n, m, MN[2222][2222], l[2222], r[2222], a[1000010], mn[2222][2222];
long long f[2222][2222], g[2222][2222], ans;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) getint(a[i]);
  for (int i = 1; i <= n; ++i) l[i] = m + 1, r[i] = 0;
  for (int i = 1; i <= m; ++i) {
    l[a[i]] = min(l[a[i]], i);
    r[a[i]] = max(r[a[i]], i);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (l[i] < l[j]) {
        if (r[i] < r[j] && r[i] > l[j]) return puts("0"), 0;
      }
  m = unique(a + 1, a + m + 1) - a - 1;
  for (int i = 0; i <= m; ++i) {
    mn[i][i] = MN[i][i] = i;
    for (int j = i + 1; j <= m; ++j) {
      mn[i][j] = (a[j] < a[mn[i][j - 1]]) ? j : mn[i][j - 1];
      MN[i][j] = (a[j] <= a[MN[i][j - 1]]) ? j : MN[i][j - 1];
    }
  }
  for (int i = 1; i <= n; ++i) l[i] = m + 1, r[i] = 0;
  for (int i = 1; i <= m; ++i) {
    l[a[i]] = min(l[a[i]], i);
    r[a[i]] = max(r[a[i]], i);
  }
  for (int i = 1; i <= n; ++i)
    if (a[mn[l[i]][r[i]]] < i) return puts("0"), 0;
  for (int i = 1; i <= m + 1; ++i) g[i][i - 1] = 1;
  for (int len = 1; len <= m; ++len) {
    for (int i = 1; i <= m - len + 1; ++i) {
      int j = i + len - 1;
      int c = a[mn[i][j]];
      if (i > l[c] || j < r[c]) continue;
      f[i][j] = 1;
      int las = i - 1;
      for (int k = i; k <= j; ++k)
        if (a[k] == c) {
          f[i][j] = f[i][j] * g[las + 1][k - 1] % MO;
          las = k;
        }
      f[i][j] = f[i][j] * g[las + 1][j] % MO;
    }
    for (int i = 1; i <= m - len + 1; ++i) {
      int j = i + len - 1;
      for (int k = i - 1; k <= j - 1; ++k)
        (g[i][j] += g[i][k] * f[k + 1][j]) %= MO;
    }
  }
  ans = (g[1][m] % MO + MO) % MO;
  cout << ans << endl;
  return 0;
}
