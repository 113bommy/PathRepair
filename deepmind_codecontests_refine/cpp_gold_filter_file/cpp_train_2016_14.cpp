#include <bits/stdc++.h>
using namespace std;
inline long long getint() {
  register long long res = 0, p = 1;
  register char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') p = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
  return res * p;
}
const int INF = 0x3f3f3f3f;
const int N = 33, M = 50050, LIM = 32;
int LN, n, P, a[N], b[N], ans[N];
int f[N][N][M];
int main() {
  LN = getint();
  P = getint();
  int i, j, k, l, w;
  for (i = 1; i <= LN; i++) {
    j = getint();
    if (j < LIM) a[++n] = j, b[n] = i;
  }
  memset(f, -1, sizeof(f));
  for (i = 1; i <= n; i++) {
    f[i][a[i]][a[i] % P] = 0;
    for (j = 0; j < LIM; j++)
      for (k = 0; k < P; k++)
        if (f[i - 1][j][k] >= 0) {
          w = a[i] < 10 ? 10 : 100;
          f[i][j][k] = P;
          f[i][j ^ a[i]][(k * w + a[i]) % P] = k;
        }
  }
  for (i = 1; i <= n; i++)
    if (f[i][0][0] >= 0) {
      printf("Yes\n");
      for (l = i, j = 0, k = 0; l >= 1; l--) {
        w = f[l][j][k];
        if (0 <= w && w < P) ans[++ans[0]] = b[l], j ^= a[l], k = w;
        if (!j && !k) break;
      }
      printf("%d\n", ans[0]);
      for (i = ans[0]; i >= 1; i--) printf("%d ", ans[i]);
      return 0;
    }
  printf("No\n");
  return 0;
}
