#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5 + 5, MM = 15;
int c[MN][MM], tot, N, K, Q, rk[MN], z;
bitset<4096> F[MN];
inline bool cmp(int i, int j) { return c[i][z] > c[j][z]; }
int main() {
  scanf("%d%d%d", &N, &K, &Q);
  tot = K;
  for (int i = 0; i < K; ++i)
    for (int j = 1; j <= N; ++j) scanf("%d", &c[i][j]);
  for (int i = 0; i < K; ++i)
    for (int mask = 0; mask < (1 << K); ++mask)
      if (mask >> i & 1) F[i + 1][mask] = 1;
  while (Q--) {
    int x, y;
    scanf("%d%d%d", &x, &y, &z);
    if (x == 1)
      F[++tot] = F[y] | F[z];
    else if (x == 2)
      F[++tot] = F[y] & F[z];
    else {
      for (int i = 0; i < K; ++i) rk[i] = i;
      sort(rk, rk + K, cmp);
      int cur = 0;
      for (int i = 0; i < K; ++i) {
        cur |= (1 << rk[i]);
        if (F[y][cur]) {
          printf("%d\n", c[rk[i]][z]);
          break;
        }
      }
    }
  }
  return 0;
}
