#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double eps = 1e-11;
const long double pi = acos(-1);
const long long oo = 1 << 30;
const long long loo = 1ll << 62;
const long long mods = 1e9 + 7;
const long long MAXN = 2005;
const long long INF = 0x3f3f3f3f;
inline long long read() {
  long long f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
char st[MAXN];
long long s[MAXN][MAXN], a[MAXN][MAXN], n, m, mxx, mxy;
long long get(long long x1, long long y1, long long x2, long long y2) {
  if (x1 > x2 || y1 > y2) return 0;
  return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}
signed main() {
  n = read(), m = read(), mxx = 0, mxy = 0;
  for (long long i = 1; i <= n; i++) {
    scanf("%s", st + 1);
    for (long long j = 1; j <= m; j++) {
      if (st[j] == 'w') upmax(mxx, i), upmax(mxy, j);
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (st[j] == 'w');
    }
  }
  pair<long long, long long> Ans;
  long long ans = INF;
  for (long long i = 1; i <= mxx; i++)
    for (long long j = 1; j <= mxy; j++) {
      long long t = max(mxx - i, mxy - j);
      if (t > ans || i + t > n || j + t > m) continue;
      if (get(i, j, i + t, j + t) - get(i + 1, j + 1, i + t - 1, j + t - 1) ==
          s[n][m])
        Ans = make_pair(i, j), ans = t;
    }
  if (ans == INF)
    puts("-1");
  else {
    for (long long i = Ans.first; i <= Ans.first + ans; i++)
      for (long long j = Ans.second; j <= Ans.second + ans; j++) a[i][j] = 1;
    for (long long i = Ans.first + 1; i <= Ans.first + ans - 1; i++)
      for (long long j = Ans.second + 1; j <= Ans.second + ans - 1; j++)
        a[i][j] = 0;
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= m; j++)
        if (get(i, j, i, j) == 1)
          putchar('w');
        else
          putchar(a[i][j] ? '+' : '.');
      puts("");
    }
  }
  return 0;
}
