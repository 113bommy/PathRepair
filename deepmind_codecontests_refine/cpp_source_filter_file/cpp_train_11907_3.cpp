#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const int MN = 1e3 + 100;
const int MM = 1e3 + 100;
const ld EPS = 1e-12;
bool equ(const ld& a, const ld& b) { return fabs(a - b) < EPS; }
int N, M;
int a[MN];
ld dp[MN][MN];
int x, y;
void qry(void) {
  scanf("%d%d", &x, &y);
  x--, y--;
  for (int i = 0; i < N; i++) {
    if (i == x || i == y) continue;
    dp[i][x] = dp[i][y] = (dp[i][y] + dp[i][x]) / 2;
    dp[x][i] = dp[y][i] = (dp[y][i] + dp[x][i]) / 2;
  }
  dp[x][y] = dp[y][x] = 0.5;
}
ld f;
int main(void) {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) scanf("%d", a + i);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (i != j) dp[i][j] = a[i] > a[j] ? 1.0 : 0.0;
  for (; M--;) qry();
  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++) f += dp[j][i];
  printf("%.12f\n", static_cast<double>(f));
  return 0;
}
