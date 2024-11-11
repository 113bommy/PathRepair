#include <bits/stdc++.h>
using namespace std;
double dp[2002][2002];
int a[10000], b[10000];
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  int k = 0, f = 1;
  char ch = getchar();
  while (ch < 48 || ch > 57) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= 48 && ch <= 57) {
    k = (k << 1) + (k << 3) + (ch ^ 48);
    ch = getchar();
  }
  return k * f;
}
int main() {
  int n, m;
  cin >> n >> m;
  int l = n;
  int r = n;
  for (int i = 1; i <= m; i++) {
    int x, y;
    x = read();
    y = read();
    if (!a[x]) l--;
    if (!b[y]) r--;
    a[x] = 1;
    b[y] = 1;
  }
  for (int i = 1; i <= l; i++) dp[i][0] = dp[i - 1][0] + double(n / i);
  for (int i = 1; i <= r; i++) dp[0][i] = dp[0][i - 1] + double(n / i);
  for (int i = 1; i <= l; i++)
    for (int j = 1; j <= r; j++)
      dp[i][j] = (dp[i - 1][j] * i * (n - j) + n * n +
                  dp[i][j - 1] * j * (n - i) + dp[i - 1][j - 1] * i * j) /
                 (n * n - (n - i) * (n - j));
  printf("%.8lf\n", dp[l][r]);
}
