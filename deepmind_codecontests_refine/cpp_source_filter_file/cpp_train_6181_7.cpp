#include <bits/stdc++.h>
using namespace std;
bitset<100005> f[60 + 5], g[60 + 5];
int n, tot;
int ans[100005];
long long sum;
int p[60 + 5];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    long long x;
    scanf("%I64d", &x);
    sum ^= x;
    for (int j = 0; j <= 60; j++)
      if (x & (1 << j)) g[j][i] = 1;
  }
  for (int bit = 0; bit <= 1; bit++) {
    for (int i = 60; i >= 0; i--)
      if ((sum >> i & 1) == bit) {
        f[++tot] = g[i];
        if (bit == 0)
          f[tot][n + 1] = 1;
        else
          f[tot][n + 1] = 0;
        for (int j = 1; j <= tot - 1; j++)
          if (f[tot][p[j]]) f[tot] ^= f[j];
        p[tot] = n + 2;
        for (int j = 1; j <= n; j++)
          if (f[tot][j]) {
            p[tot] = j;
            break;
          }
        if (p[tot] > n) {
          tot--;
          continue;
        }
        for (int j = 1; j <= tot - 1; j++)
          if (f[j][p[tot]]) f[j] ^= f[tot];
      }
  }
  for (int i = 1; i <= tot; i++) ans[p[i]] = f[i][n + 1];
  for (int i = 1; i <= n; i++) printf("%d ", 2 - ans[i]);
  return 0;
}
