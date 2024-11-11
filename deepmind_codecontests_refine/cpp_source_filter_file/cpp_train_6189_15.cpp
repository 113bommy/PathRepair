#include <bits/stdc++.h>
using namespace std;
const int maxn = 211;
double P, opt[2][2][maxn][1 << 9];
int x, k, p, t, mask;
int main() {
  scanf("%d%d%d", &x, &k, &p);
  P = (double)p / 100;
  mask = (1 << 9) - 1;
  t = (x ^ (x & mask)) >> 9;
  int sum0 = 0, sum1 = 0, sum, st = 0;
  while (t > 0 && (t & 1) == 0) {
    sum0++;
    t >>= 1;
  }
  t = (x ^ (x & mask)) >> 9;
  while (t > 0 && (t & 1) == 1) {
    sum1++;
    t >>= 1;
  }
  for (int i = 0; i <= k; i++)
    for (int u = 0; u < (1 << 9); u++)
      for (int j = 0; j < maxn; j++) opt[0][0][j][u] = opt[0][1][j][u] = 0.0;
  if (sum0 > 0) {
    opt[0][0][sum0][x & mask] = 1.0;
  } else {
    opt[0][1][sum1][x & mask] = 1.0;
  }
  for (int i = 0; i < k; i++) {
    for (int u = 0; u < (1 << 9); u++)
      for (int j = 0; j < maxn; j++)
        opt[1 - st][0][j][u] = opt[1 - st][1][j][u] = 0.0;
    for (int u = 0; u < (1 << 9); u++)
      for (int j = 0; j < maxn; j++) {
        if (opt[st][0][j][u] > 0) {
          if (((u + 1) & mask) == (u + 1)) {
            opt[1 - st][0][j][u + 1] += opt[st][0][j][u] * (1 - P);
          } else {
            opt[1 - st][1][1][(u + 1) & mask] += opt[st][0][j][u] * (1 - P);
          }
          if (((u << 1) & mask) == (u << 1)) {
            opt[1 - st][0][j + 1][u << 1] += opt[st][0][j][u] * P;
          } else {
            opt[1 - st][1][1][(u << 1) & mask] += opt[st][0][j][u] * P;
          }
        }
        if (opt[st][1][j][u] > 0) {
          if (((u + 1) & mask) == (u + 1)) {
            opt[1 - st][1][j][u + 1] += opt[st][1][j][u] * (1 - P);
          } else {
            opt[1 - st][0][j][(u + 1) & mask] += opt[st][1][j][u] * (1 - P);
          }
          if (((u << 1) & mask) == (u << 1)) {
            opt[1 - st][0][1][u << 1] += opt[st][1][j][u] * P;
          } else {
            opt[1 - st][1][j + 1][(u << 1) & mask] += opt[st][1][j][u] * P;
          }
        }
      }
    st = 1 - st;
  }
  double ans = 0.0;
  for (int j = 0; j < maxn; j++) {
    ans += opt[st][0][j][0] * (j + 9) + opt[st][1][j][0] * 9;
    for (int u = 1; u < (1 << 9); u++) {
      for (t = u, sum = 0; t > 0 && (t & 1) == 0; t >>= 1, sum++)
        ;
      ans += (opt[st][1][j][u] + opt[st][0][j][u]) * sum;
    }
  }
  printf("%lf\n", ans);
}
