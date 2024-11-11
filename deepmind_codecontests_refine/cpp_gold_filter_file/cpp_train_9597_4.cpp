#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
const long long mod = 1e9 + 7;
const int MAXN = 2010;
int n, m;
char s[MAXN][MAXN];
int sumr[MAXN][MAXN], sumd[MAXN][MAXN];
long long r[MAXN][MAXN], d[MAXN][MAXN];
void check(int a[MAXN][MAXN]) {
  for (int i = (1); i <= (n); i += (1))
    for (int j = (1); j <= (m); j += (1))
      printf("%d%c", a[i][j], j == m ? '\n' : ' ');
}
int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  n = read(), m = read();
  for (int i = (1); i <= (n); i += (1)) scanf("%s", s[i] + 1);
  if (n == 1 && m == 1) return puts(s[1][1] == '.' ? "1" : "0") & 0;
  for (int i = (1); i <= (n); i += (1)) {
    sumr[i][m + 1] = 0;
    for (int j = (m); j >= (1); j -= (1))
      sumr[i][j] = s[i][j] == 'R' ? sumr[i][j + 1] + 1 : sumr[i][j + 1];
  }
  for (int j = (1); j <= (m); j += (1)) {
    sumd[n + 1][j] = 0;
    for (int i = (n); i >= (1); i -= (1))
      sumd[i][j] = s[i][j] == 'R' ? sumd[i + 1][j] + 1 : sumd[i + 1][j];
  }
  for (int i = (1); i <= (n); i += (1))
    if (sumd[i][m] == 0) d[i][m] = 1;
  for (int j = (1); j <= (m); j += (1))
    if (sumr[n][j] == 0) r[n][j] = 1;
  for (int i = (n - 1); i >= (1); i -= (1))
    for (int j = (m - 1); j >= (1); j -= (1)) {
      r[i][j] = r[i][j + 1] + d[i][j + 1];
      if (s[i][j + 1] == 'R') r[i][j] -= d[i][m - sumr[i][j + 1] + 1];
      d[i][j] = d[i + 1][j] + r[i + 1][j];
      if (s[i + 1][j] == 'R') d[i][j] -= r[n - sumd[i + 1][j] + 1][j];
      r[i][j] %= mod, d[i][j] %= mod;
    }
  printf("%lld\n", ((r[1][1] + d[1][1]) % mod + mod) % mod);
  return 0;
}
