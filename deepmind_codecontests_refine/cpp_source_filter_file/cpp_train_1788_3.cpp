#include <bits/stdc++.h>
const int N = 1e3 + 10;
int ri() {
  char c = getchar();
  int x = 0, f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) - '0' + c;
  return x * f;
}
int n, m, q, s[N][N][2], bin[31];
long long c[31][2];
char g[N][N];
void Calc(long long cnt1, long long cnt0) {
  c[0][0] = cnt0;
  c[0][1] = cnt1;
  for (int i = 1; i <= 30; ++i) c[i][1] = c[i][0] = c[i - 1][0] + c[i - 1][1];
}
long long San(int nw, int x, int y) {
  long long ans = 0;
  int ax = x / n;
  Calc(s[n][y][1], s[n][y][0]);
  for (int i = 30; ~i; --i)
    if (ax >= bin[i]) {
      ax -= bin[i];
      ans += c[i][nw];
      nw ^= 1;
    }
  ans += s[x % n][y][nw];
  return ans;
}
long long Solve(int x, int y) {
  long long ans = 0;
  int ax = x / n, ay = y / m, nw = 1;
  Calc(s[n][m][1], s[n][m][0]);
  for (int i = 30; ~i; --i)
    if (ax >= bin[i]) {
      ax -= bin[i];
      ans += c[i][nw];
      nw ^= 1;
    }
  ans += s[x % n][m][nw];
  nw = 1;
  Calc(ans, m * x - ans);
  ans = 0;
  for (int i = 30; ~i; --i)
    if (ay >= bin[i]) {
      ay -= bin[i];
      ans += c[i][nw];
      nw ^= 1;
    }
  ans += San(nw, x, y % m);
  return ans;
}
int main() {
  bin[0] = 1;
  for (int i = 1; i <= 30; ++i) bin[i] = bin[i - 1] << 1;
  n = ri();
  m = ri();
  q = ri();
  for (int i = 1; i <= n; ++i) scanf("%s", g[i] + 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      s[i][j][0] = s[i - 1][j][0] + (g[i][j] == '0'),
      s[i][j][1] = s[i - 1][j][1] + (g[i][j] == '1');
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      s[i][j][0] += s[i][j - 1][0], s[i][j][1] += s[i][j - 1][1];
  for (; q--;) {
    int x1 = ri(), y1 = ri(), x2 = ri(), y2 = ri();
    printf("%lld\n", Solve(x2, y2) - Solve(x2, y1 - 1) - Solve(x1 - 1, y2) +
                         Solve(x1 - 1, y1 - 1));
  }
  return 0;
}
