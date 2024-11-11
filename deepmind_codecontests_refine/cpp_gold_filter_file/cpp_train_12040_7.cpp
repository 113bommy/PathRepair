#include <bits/stdc++.h>
using namespace std;
int Q;
int f[1000005], g[1000005];
int sum[1000005][10];
int main() {
  f[0] = 1;
  for (int i = 1; i <= 9; i++) f[i] = i;
  for (int i = 10; i <= 1000000; i++) {
    int p = i, wei = 1;
    while (p / 10) {
      p /= 10;
      wei *= 10;
    }
    if (p == 0) p = 1;
    f[i] = f[i % wei] * p;
  }
  sum[0][0] = 1;
  for (int i = 1; i <= 9; i++) {
    g[i] = i;
    for (int j = 0; j <= 9; j++) sum[i][j] = sum[i - 1][j];
    sum[i][i]++;
  }
  for (int i = 10; i <= 1000000; i++) {
    g[i] = g[f[i]];
    for (int j = 0; j <= 9; j++) sum[i][j] = sum[i - 1][j];
    sum[i][g[i]]++;
  }
  scanf("%d", &Q);
  while (Q--) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    printf("%d\n", sum[r][k] - sum[l - 1][k]);
  }
}
