#include <bits/stdc++.h>
using namespace std;
long long p[1 << 24], track[1 << 24];
long long cost[25][25];
int x[25], y[25], n, i, j, k, q;
int main() {
  cin >> x[0] >> y[0];
  cin >> n;
  for (i = 1; i <= n; i++) cin >> x[i] >> y[i];
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= n; j++) {
      cost[i][j] =
          (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
    }
  }
  for (i = 0; i < 1 << n; i++) p[i] = 1e9;
  p[0] = 0;
  for (i = 0; i < 1 << n; i++) {
    for (j = 0; j < n; j++)
      if (!(1 << j & i)) {
        for (k = j; k < n; k++) {
          if (!(1 << k & i)) {
            int nmask = i | (1 << j) | (1 << k);
            q = p[i] + cost[0][j + 1] + cost[j + 1][k + 1] + cost[k + 1][0];
            if (p[nmask] > q) {
              p[nmask] = q, track[nmask] = i;
            }
          }
        }
        break;
      }
  }
  cout << p[(1 << n) - 1] << endl;
  for (i = (1 << n) - 1; i > 0; i = track[i]) {
    cout << 0 << " ";
    for (int t = i ^ track[i]; t; t -= (t & -t)) {
      cout << (int)(log(t & -t) / log(2) + 1e-8 + 1) << " ";
    }
  }
  cout << 0 << endl;
}
