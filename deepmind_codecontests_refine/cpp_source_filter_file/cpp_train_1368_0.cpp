#include <bits/stdc++.h>
using namespace std;
int n, m;
int b[1000005] = {0};
int f[15][15] = {0};
int g[15][15] = {0};
int ans = 0;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int o;
    cin >> o;
    b[o]++;
  }
  for (int i = 1; i <= m; i++) {
    if (b[i] >= 10) {
      int tu = (b[i] - 7) / 3;
      ans += tu, b[i] = tu * 3;
    }
  }
  for (int i = 1; i <= m + 1; i++) {
    if (!b[i])
      ans += g[b[i - 2]][b[i - 1]];
    else {
      for (int j = 0; j <= b[i - 1]; j++) {
        for (int k = 0; k <= b[i]; k++) {
          int M = min(j, min(k, b[i - 2]));
          for (int l = 0; l <= M; l++) {
            f[j][k] = max(f[j][k], g[b[i - 2] - l][j - l] + l + (k - l) / 3);
          }
        }
      }
    }
    for (int j = 0; j <= b[i - 1]; j++) {
      for (int k = 0; k <= b[i]; k++) g[j][k] = f[j][k];
    }
    memset(f, 0, sizeof(f));
  }
  cout << ans << endl;
  return 0;
}
