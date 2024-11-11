#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
inline void write(int x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const int N = 160;
const long long INF = 1ll << 62;
long long a[N], b[N], id[N], n, m;
inline bool upd(long long &x, long long v) {
  if (v <= x) return 0;
  x = v;
  return 1;
}
long long dp[N][N], lst[N][N];
int ans[N], lans;
int a2[N << 1], l2;
int tp[N];
inline void solve() {
  int i, j;
  read(n), read(m);
  for (i = 1; i <= n; ++i) tp[i] = 0, read(a[i]), read(b[i]), id[i] = i;
  for (i = 1; i <= n; ++i)
    for (j = i + 1; j <= n; ++j)
      if (b[i] < b[j]) swap(a[i], a[j]), swap(b[i], b[j]), swap(id[i], id[j]);
  for (i = 0; i <= n; ++i)
    for (j = 0; j <= n; ++j) dp[i][j] = -INF;
  dp[0][0] = 0;
  for (i = 1; i <= n; ++i)
    for (j = 0; j <= m; ++j) {
      if (dp[i - 1][j] >= 0 && upd(dp[i][j], dp[i - 1][j] + b[i] * (m - 1)))
        lst[i][j] = 0;
      if (j && dp[i - 1][j - 1] >= 0 &&
          upd(dp[i][j], dp[i - 1][j - 1] + b[i] * (m - j) + a[i]))
        lst[i][j] = 1;
    }
  lans = 0;
  int nown = n, nowm = m;
  while (nown) {
    if (lst[nown][nowm]) ans[++lans] = nown, --nowm, tp[nown] = 1;
    --nown;
  }
  l2 = 0;
  for (i = 1; i < lans; ++i) a2[++l2] = id[ans[i]];
  for (i = 1; i <= n; ++i)
    if (!tp[i]) {
      a2[++l2] = id[i];
      a2[++l2] = -id[i];
    }
  a2[++l2] = id[ans[lans]];
  cout << l2 << '\n';
  for (i = 1; i <= l2; ++i) cout << a2[i] << (i < l2 ? ' ' : '\n');
}
int main() {
  int T;
  read(T);
  while (T--) solve();
  return 0;
}
