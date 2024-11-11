#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n, m;
int cnt[maxn], w[maxn][maxn], v[maxn][maxn];
int f[10010], per[maxn][maxn];
int main() {
  int x;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &cnt[i]);
    for (int j = 1; j <= cnt[i]; j++) {
      scanf("%d", &x);
      per[i][j] = per[i][j - 1] + x;
    }
    for (int j = 1; j <= cnt[i]; j++) {
      v[i][j] = j;
      for (int k = 0; k <= j; k++) {
        int t = j - k;
        w[i][j] = max(w[i][j], per[i][k] + per[i][cnt[i]] - per[i][cnt[i] - t]);
      }
    }
  }
  memset(f, 0xcf, sizeof(f));
  f[0] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 0; j--)
      for (int k = 1; k <= cnt[i]; k++) {
        if (j >= v[i][k]) f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
      }
  printf("%d\n", f[m]);
}
