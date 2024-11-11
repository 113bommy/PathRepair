#include <bits/stdc++.h>
using namespace std;
int L[30][30], U[30][30], a[30][30], f[30];
int n, ans, mf, mc;
void go(int u, int cost) {
  if (u == n) {
    if (cost > mc) {
      mc = cost;
      mf = ans;
    }
    return;
  }
  int k1, k2, k3, k4, k5;
  for (k1 = L[u][u + 1]; k1 <= U[u][u + 1] && k1 <= f[u]; ++k1)
    for (k2 = L[u][u + 2]; k2 <= U[u][u + 2] && k1 + k2 <= f[u]; ++k2)
      for (k3 = L[u][u + 3]; k3 <= U[u][u + 3] && k1 + k2 + k3 <= f[u]; ++k3)
        for (k4 = L[u][u + 4]; k4 <= U[u][u + 4] && k1 + k2 + k3 + k4 <= f[u];
             ++k4) {
          k5 = f[u] - k1 - k2 - k3 - k4;
          if (k5 < L[u][u + 5] || k5 > U[u][u + 5]) continue;
          f[u + 1] += k1;
          f[u + 2] += k2;
          f[u + 3] += k3;
          f[u + 4] += k4;
          f[u + 5] += k5;
          go(u + 1, cost + k1 * k1 + (k1 > 0) * a[u][u + 1] + k2 * k2 +
                        (k2 > 0) * a[u][u + 2] + k3 * k3 +
                        (k3 > 0) * a[u][u + 3] + k4 * k4 +
                        (k4 > 0) * a[u][u + 4] + k5 * k5 +
                        (k5 > 0) * a[u][u + 5]);
          f[u + 1] -= k1;
          f[u + 2] -= k2;
          f[u + 3] -= k3;
          f[u + 4] -= k4;
          f[u + 5] -= k5;
        }
}
int main() {
  cin >> n;
  for (int i = 0; i < n * (n - 1) / 2; ++i) {
    int u, v;
    cin >> u >> v;
    cin >> L[u][v] >> U[u][v] >> a[u][v];
  }
  mf = mc = -1;
  for (ans = 0; ans <= (n - 1) * 5; ++ans) {
    f[1] = ans;
    go(1, 0);
    if (mf != -1) {
      break;
    }
  }
  cout << mf << " " << mc << endl;
}
