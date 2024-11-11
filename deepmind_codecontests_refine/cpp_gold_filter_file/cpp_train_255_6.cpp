#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
inline int add(int a, int b) {
  if ((a += b) >= P) a -= P;
  return a;
}
inline int sub(int a, int b) {
  if ((a -= b) < 0) a += P;
  return a;
}
inline int mul(int a, int b) { return 1ll * a * b % P; }
inline int kpow(int a, int b) {
  int r = 1;
  for (; b; b >>= 1, a = mul(a, a)) {
    if (b & 1) r = mul(r, a);
  }
  return r;
}
const int N = 21, M = 1 << N;
int n, m;
char s[N][N];
int LOG[M];
int same[N][N], cost[N][M];
int f[M];
int val[N][N];
int main() {
  for (int i = (2); i < (M); i++) LOG[i] = LOG[i >> 1] + 1;
  scanf("%d%d", &n, &m);
  for (int i = (0); i < (n); i++) scanf("%s", s[i]);
  for (int i = (0); i < (n); i++)
    for (int j = (0); j < (m); j++) scanf("%d", val[i] + j);
  for (int i = (0); i < (n); i++)
    for (int j = (0); j < (m); j++) {
      int mx = 0;
      for (int k = (0); k < (n); k++)
        if (s[i][j] == s[k][j]) {
          same[i][j] |= 1 << k;
          cost[i][j] += val[k][j];
          mx = max(mx, val[k][j]);
        }
      cost[i][j] -= mx;
    }
  for (int i = (0); i < (M); i++) f[i] = 1e9;
  f[0] = 0;
  int up = 1 << n;
  for (int msk = (1); msk < (up); msk++) {
    int lb = LOG[msk & -msk];
    for (int i = (0); i < (m); i++) {
      f[msk] = min(f[msk], f[msk & (msk ^ same[lb][i])] + cost[lb][i]);
      f[msk] = min(f[msk], f[msk ^ (1 << lb)] + val[lb][i]);
    }
  }
  printf("%d\n", f[up - 1]);
  return 0;
}
