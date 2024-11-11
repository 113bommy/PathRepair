#include <bits/stdc++.h>
using namespace std;
int n;
int num[55];
struct md {
  int v;
  md(int _v = 0) { v = _v; }
  void operator+=(md n) { v = (0LL + v + n.v) % 1000000007; }
  void operator*=(md n) { v = (1LL * v * n.v) % 1000000007; }
};
md operator+(md a, md b) { return (0LL + a.v + b.v) % 1000000007; }
md operator*(md a, md b) { return (1LL * a.v * b.v) % 1000000007; }
md mixdp[55][55][55];
md mix[55][55];
md memo[51][51][51][51];
md dp(int i, int p1, int p2, int c1, int c2) {
  if (i > n) return mix[p1][p2] * mix[c1][c2];
  if (memo[i][p1][p2][c1 + c2].v != -1) return memo[i][p1][p2][c1 + c2];
  md v;
  if ((p1 || p2 || c1 || c2) && mix[p1][p2].v) {
    v += dp(i, c1, c2, 0, 0) * mix[p1][p2];
  }
  int nc1 = c1, nc2 = c2;
  if (num[i] == 2)
    ++nc1;
  else
    ++nc2;
  if (p1) v += dp(i + 1, p1 - 1, p2, nc1, nc2) * p1;
  if (p2) v += dp(i + 1, p1 + 1, p2 - 1, nc1, nc2) * p2;
  return memo[i][p1][p2][c1 + c2] = v;
}
int main() {
  scanf("%d", &n);
  int one = 0, two = 0;
  for (int i = (1); i <= (n); i++) {
    scanf("%d", &num[i]);
    if (num[i] == 2)
      ++one;
    else
      ++two;
  }
  for (int i = (0); i <= (one + two); i++) {
    memset(mixdp, 0, sizeof(mixdp));
    mixdp[0][0][0] = 1;
    for (int j = (1); j <= (min(i + two, one + two)); j++) {
      for (int k = (0); k <= (j); k++) {
        for (int l = (0); l <= (max(0, j - i)); l++) {
          if (j <= i) {
            if (k) mixdp[j][k][l] += mixdp[j - 1][k - 1][l];
            if (k) mixdp[j][k][l] += mixdp[j - 1][k - 1][l + 1] * (l + 1);
            mixdp[j][k][l] += mixdp[j - 1][k + 1][l] * (k + 1);
          } else {
            if (l) mixdp[j][k][l] += mixdp[j - 1][k][l - 1];
            if (k) mixdp[j][k][l] += mixdp[j - 1][k][l] * k;
            mixdp[j][k][l] += mixdp[j - 1][k + 2][l] * ((k + 2) * (k + 1) / 2);
            if (k >= 2) mixdp[j][k][l] += mixdp[j - 1][k - 2][l + 1] * (l + 1);
            if (k >= 2)
              mixdp[j][k][l] +=
                  mixdp[j - 1][k - 2][l + 2] * ((l + 2) * (l + 1) / 2);
            if (k) mixdp[j][k][l] += mixdp[j][k][l + 1] * (l + 1) * k;
          }
        }
      }
      if (j >= i) mix[i][j - i] = mixdp[j][0][0];
    }
  }
  mix[0][0] = 1;
  memset(memo, -1, sizeof(memo));
  md ans;
  if (num[1] == 2) {
    ans = dp(2, 0, 1, 0, 0);
  } else {
    if (num[2] == 2)
      ans = dp(3, 0, 1, 1, 0);
    else
      ans = dp(3, 0, 1, 0, 1);
  }
  printf("%d\n", ans);
  return 0;
}
