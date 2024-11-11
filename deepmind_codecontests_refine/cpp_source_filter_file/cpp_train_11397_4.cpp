#include <bits/stdc++.h>
using namespace std;
int n, k, m;
long long mi10[1001];
int f[1001][101][2];
int main() {
  scanf("%d%d%d", &n, &k, &m);
  for (int i = mi10[0] = 1; i <= n; i++) mi10[i] = mi10[i - 1] * 10 % m;
  f[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < k; j++) {
      for (int t = 0; t <= 9; t++) {
        if (i == n && !t) continue;
        int tp = (t * mi10[i - 1] + j) % k;
        (f[i][tp][1] += f[i - 1][j][1]) %= m;
        if (tp == 0 && t != 0)
          (f[i][tp][1] += f[i - 1][j][0]) %= m;
        else
          (f[i][tp][0] += f[i - 1][j][0]) %= m;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < k; i++) (ans += f[n][i][1]) %= m;
  cout << ans << endl;
  return 0;
}
