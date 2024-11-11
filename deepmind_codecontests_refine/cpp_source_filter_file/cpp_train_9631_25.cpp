#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch - '0' < 0 || ch - '0' > 9) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch - '0' >= 0 && ch - '0' <= 9) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
char s[3][3010], t[3010];
long long has_pre[3][3010], has_suf[3][3010], has[3010], base[3010];
int n, m;
int f[3][3010][3010], g[3][3010][3010];
long long get_pre(int l, int r, int id) {
  return has_pre[id][r] - has_pre[id][l - 1] * base[r - l + 1];
}
long long get_suf(int l, int r, int id) {
  return has_suf[id][l] - has_suf[id][r + 1] * base[r - l + 1];
}
void add(int &x, int y) {
  x = x + y >= 1000000007 ? x + y - 1000000007 : x + y;
}
long long merge(long long h1, long long h2, int len) {
  return h2 + h1 * base[len];
}
int ans, res;
void solve() {
  memset(f, 0, sizeof(f));
  memset(g, 0, sizeof(g));
  for (int i = 1; i <= m; i++) has[i] = has[i - 1] * 31 + t[i] - 'a' + 1;
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = j; k >= 1; k--) {
        int len = 2 * (j - k + 1);
        if (len > m) continue;
        long long h1 = get_pre(k, j, i), h2 = get_suf(k, j, 3 - i),
                  hx = has[len];
        if (merge(h1, h2, j - k + 1) == hx) {
          if (len == m)
            res++;
          else
            g[i][j][len] = 1;
        }
      }
    }
  }
  for (int i = 1; i <= 2; i++)
    for (int j = 1; j <= n; j++)
      if (s[i][j] == t[1]) g[i][j][1] = 1;
  for (int i = m; i >= 1; i--) has[i] = has[i + 1] * 31 + t[i] - 'a' + 1;
  for (int k = 1; k < m; k++) {
    for (int j = 1; j <= n; j++) {
      for (int i = 1; i <= 2; i++) {
        if (g[i][j][k]) {
          if (j < n && s[i][j + 1] == t[k + 1])
            add(f[i][j + 1][k + 1], g[i][j][k]);
        }
        if (f[i][j][k]) {
          if (j < n && s[i][j + 1] == t[k + 1])
            add(f[i][j + 1][k + 1], f[i][j][k]);
          if (s[3 - i][j] == t[k + 1]) add(g[3 - i][j][k + 1], f[i][j][k]);
        }
      }
    }
  }
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= n; j++) {
      if (s[i][j] == t[m]) {
        if (m == 1) add(ans, 1);
        add(ans, f[i][j - 1][m - 1]);
        add(ans, g[i][j - 1][m - 1]);
      }
      for (int k = j; k <= n; k++) {
        int len = 2 * (k - j + 1);
        if (len > m) continue;
        long long h1 = get_pre(j, k, 3 - i), h2 = get_suf(j, k, i),
                  hx = has[m - len + 1];
        if (merge(h1, h2, k - j + 1) == hx) {
          if (len == m && m != 2)
            res++;
          else {
            add(ans, f[i][j - 1][m - len]);
            add(ans, g[i][j - 1][m - len]);
          }
        }
      }
    }
  }
}
int main() {
  scanf("%s", s[1] + 1);
  scanf("%s", s[2] + 1);
  n = strlen(s[1] + 1);
  scanf("%s", t + 1);
  m = strlen(t + 1);
  base[0] = 1;
  for (int i = 1; i <= max(n, m); i++) base[i] = base[i - 1] * 31;
  for (int i = 1; i <= 2; i++)
    for (int j = 1; j <= n; j++)
      has_pre[i][j] = has_pre[i][j - 1] * 31 + s[i][j] - 'a' + 1;
  for (int i = 1; i <= 2; i++)
    for (int j = n; j >= 1; j--)
      has_suf[i][j] = has_suf[i][j + 1] * 31 + s[i][j] - 'a' + 1;
  solve();
  reverse(t + 1, t + m + 1);
  solve();
  add(ans, res / 2);
  if (m == 1) ans /= 2;
  cout << ans << endl;
  return 0;
}
