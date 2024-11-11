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
const int oo = 1 << 30;
const long long loo = 1ll << 62;
const int mods = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int MAXN = 200005;
inline int read() {
  int f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  return x * f;
}
char s[2][MAXN];
int Log[MAXN], f[MAXN][18][2][2];
signed main() {
  int n = read(), m = read();
  scanf("%s", s[0] + 1);
  scanf("%s", s[1] + 1);
  Log[1] = 0;
  for (int i = 2; i <= n; i++) Log[i] = Log[i >> 1] + 1;
  memset(f, INF, sizeof f);
  for (int i = 1; i < n; i++)
    for (int x = 0; x < 2; x++) {
      if (s[x][i] == '.' && s[x ^ 1][i] == '.' && s[x ^ 1][i + 1] == '.' &&
          s[x][i + 1])
        f[i][0][x][x] = 3;
      if (s[x][i] == '.' && s[x ^ 1][i] == '.' && s[x ^ 1][i + 1] == '.')
        f[i][0][x][x ^ 1] = 2;
      if (s[x][i] == '.' && s[x][i + 1] == '.' && s[x ^ 1][i + 1] == '.')
        f[i][0][x][x ^ 1] = 2;
      if (s[x][i] == '.' && s[x][i + 1] == '.') f[i][0][x][x] = 1;
    }
  for (int i = 1; i <= Log[n]; i++)
    for (int j = 1; j <= n - (1 << i) + 1; j++)
      for (int x = 0; x < 2; x++)
        for (int y = 0; y < 2; y++)
          for (int k = 0; k < 2; k++)
            upmin(f[j][i][x][y],
                  f[j][i - 1][x][k] + f[j + (1 << (i - 1))][i - 1][k][y]);
  while (m--) {
    pair<int, int> x = make_pair(0, 0), y = make_pair(0, 0);
    x.first = read(), y.first = read();
    if (x.first > n) x.first -= n, x.second++;
    if (y.first > n) y.first -= n, y.second++;
    if (x.first > y.first) swap(x, y);
    int nw = x.first, ans[2];
    ans[x.second] = 0;
    ans[x.second ^ 1] = (s[x.second ^ 1][x.first] == 'X' ? INF : 1);
    for (int i = Log[n]; i >= 0; i--)
      if (((y.first - x.first) >> i) & 1) {
        int Ans[2];
        Ans[0] = Ans[1] = INF;
        upmin(Ans[0], ans[0] + f[nw][i][0][0]);
        upmin(Ans[0], ans[1] + f[nw][i][1][0]);
        upmin(Ans[1], ans[0] + f[nw][i][0][1]);
        upmin(Ans[1], ans[1] + f[nw][i][1][1]);
        nw += (1 << i), ans[0] = Ans[0], ans[1] = Ans[1];
      }
    if (ans[y.second] == INF)
      puts("-1");
    else
      printf("%d\n", ans[y.second]);
  }
  return 0;
}
