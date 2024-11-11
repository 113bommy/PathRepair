#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkmax(T &a, const T &b) {
  a = a > b ? a : b;
}
template <typename T>
void chkmin(T &a, const T &b) {
  a = a < b ? a : b;
}
const int MAXN = 1 << 17 | 5, cnt[4] = {0, 1, 1, 2};
int f[2][MAXN][4], tr[4][4][4], vis[MAXN], n, K;
int main() {
  scanf("%d%d", &n, &K);
  --n;
  if (!K) return puts("0") * 0;
  memset(tr, -1, sizeof(tr));
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < 4; k++) {
        if (((i & 1) || (j & 1)) && !(k & 1)) continue;
        if ((i || j) != (k > 0)) continue;
        if (k == 0)
          tr[i][j][k] = 0;
        else if (k == 1)
          tr[i][j][k] = (i > 0) + (j > 0) + 1;
        else if (k == 2)
          tr[i][j][k] = 1;
        else if (cnt[i] + cnt[j] >= 2 && ((i & 2) || (j & 2)))
          tr[i][j][k] = 3 + (cnt[i] + cnt[j] > 2);
      }
  for (int i = 1; i <= K; i++) {
    int t;
    scanf("%d", &t);
    --t;
    ++vis[t >> 1];
  }
  memset(f, -1, sizeof(f));
  for (int i = 0; i < 1 << n; i += 2) {
    int p = vis[i] + vis[i + 1], q = p > 1 ? 3 : (p == 1 ? 2 : 0);
    f[0][i >> 1][q] = cnt[q] + (vis[i] > 0) + (vis[i + 1] > 0);
  }
  --n;
  for (int i = 0; i < n; i++) {
    int cur = i & 1, nxt = !cur;
    memset(f[nxt], -1, sizeof(int) << (n - i) << 2);
    for (int j = 0; j < 1 << (n - i); j += 2) {
      for (int a = 0; a < 4; a++)
        if (~f[cur][j][a])
          for (int b = 0; b < 4; b++)
            if (~f[cur][j + 1][b])
              for (int c = 0; c < 4; c++)
                if (~tr[a][b][c])
                  chkmax(f[nxt][j >> 1][c],
                         f[cur][j][a] + f[cur][j + 1][b] + tr[a][b][c]);
    }
  }
  printf("%d\n", max(f[n & 1][0][1], max(f[n & 1][0][2], f[n & 1][0][3])) + 2);
  return 0;
}
