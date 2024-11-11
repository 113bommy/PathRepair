#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
int w[maxn][10000 + 5];
int f[maxn][maxn][1 << 17];
int row[maxn][maxn];
int n, m;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) scanf("%d", &w[i][j]);
  }
  memset(row, 127, sizeof(row));
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = 0; k < m; k++)
        row[i][j] = min(row[i][j], abs(w[i][k] - w[j][k]));
      row[j][i] = row[i][j];
    }
  }
  memset(f, -1, sizeof(f));
  int ans = -1;
  for (int i = 0; i < n; i++) {
    f[i][i][1 << i] = 2147483647;
    for (int k = 0; k < (1 << n); k++)
      if (k & (1 << i)) {
        for (int now = 0; now < n; now++)
          if (k & (1 << now))
            if (f[i][now][k] != -1) {
              if (k == (1 << n) - 1) {
                int temp = f[i][now][k];
                for (int j = 0; j + 1 < m; j++) {
                  temp = min(temp, abs(w[now][j] - w[i][j + 1]));
                }
                ans = max(ans, temp);
                continue;
              }
              for (int nex = 0; nex < n; nex++)
                if ((k & (1 << nex)) == 0) {
                  if (f[i][nex][k | (1 << nex)] == -1)
                    f[i][nex][k | (1 << nex)] =
                        min(f[i][now][k], row[now][nex]);
                  else
                    f[i][nex][k | (1 << nex)] =
                        max(f[i][nex][k | (1 << nex)],
                            min(f[i][now][k], row[now][nex]));
                }
            }
      }
  }
  printf("%d\n", ans);
  return 0;
}
