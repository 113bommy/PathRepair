#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int dp[N][101][2];
int pwk[N], pwm[N];
int n, k, md;
void add(int &a, int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}
int solve(int i, int y, bool gr) {
  if (i == n) return (y == 0 && gr);
  int &res = dp[i][y][gr];
  if (res != -1) return res;
  res = 0;
  if (y == 0 && gr) {
    int r = (n - i ? pwm[n - i - 1] : 1) * 9LL % md;
    add(res, r);
  } else {
    for (int d = 0; d < 10; ++d) {
      add(res, solve(i + 1, (pwk[i] * d + y) % k, gr || (d > 0)));
    }
  }
  return res;
}
int main() {
  scanf("%d %d %d", &n, &k, &md);
  pwk[0] = pwm[0] = 1;
  for (int i = 1; i < n; ++i) {
    pwk[i] = pwk[i - 1] * 10 % k;
    pwm[i] = pwm[i - 1] * 10 % md;
  }
  memset(dp, -1, sizeof dp);
  printf("%d\n", solve(0, 0, 0));
  return 0;
}
