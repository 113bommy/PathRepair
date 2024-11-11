#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  T f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  x *= f;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
const int maxn = 105;
int r, s, p;
double dp[maxn][maxn][maxn], rwin, swin, pwin;
int main() {
  read(r);
  read(s);
  read(p);
  dp[r][s][p] = 1;
  for (int i = r; i >= 0; --i) {
    for (int j = s; j >= 0; --j) {
      for (int k = p; k >= 0; --k) {
        double tot = i * j + j * k + i * k;
        if (i && j) dp[i][j - 1][k] += dp[i][j][k] * (1.0 * i * j / tot);
        if (j && k) dp[i][j][k - 1] += dp[i][j][k] * (1.0 * j * k / tot);
        if (k && i) dp[i - 1][j][k] += dp[i][j][k] * (1.0 * i * k / tot);
        if (i && !j && !k) rwin += dp[i][j][k];
        if (!i && j && !k) swin += dp[i][j][k];
        if (!i && !j && k) pwin += dp[i][j][k];
      }
    }
  }
  printf("%.12lf %.12lf %.12lf\n", rwin, swin, pwin);
  return 0;
}
