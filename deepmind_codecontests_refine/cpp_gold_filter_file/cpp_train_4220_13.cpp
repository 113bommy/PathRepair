#include <bits/stdc++.h>
using namespace std;
const int M = 100010, N = 33;
int n, m;
int v[M][N], h[M][N];
long long f[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < m; i++)
    for (int j = 0; j < n; j++) scanf("%d", &h[i][j]);
  for (int i = 1; i <= m; i++)
    for (int j = 0; j < n; j++) scanf("%d", &v[i][j]);
  memset(f, 127, sizeof(f));
  f[(1 << n) - 1] = 0;
  for (int i = 1; i < m; i++) {
    for (int j = (1 << n) - 1; j >= 0; j--)
      for (int k = 0; k < n; k++)
        if (j >> k & 1) f[j ^ (1 << k)] = min(f[j ^ (1 << k)], f[j] + h[i][k]);
    for (int j = 0; j < 1 << n; j++)
      for (int k = 0; k < n; k++)
        if ((j >> k & 1) ^ (j >> (k + 1) % n & 1)) f[j] += v[i + 1][k];
  }
  printf("%lld\n", f[0]);
  return 0;
}
