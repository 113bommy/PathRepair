#include <bits/stdc++.h>
using namespace std;
double p[205];
int b[205];
double f[205][205][205 * 2];
int main() {
  int n, l, k, K;
  while (cin >> n >> l >> K) {
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      p[i] /= 100;
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    f[0][0][200 + K] = 1;
    for (int i = 0; i < n + 1; i++) {
      for (int j = 0; j < n + 1; j++) {
        for (int k = 0; k < 400; k++) {
          if (f[i][j][k] > -0.0000001) {
            if (i == n) continue;
            f[i + 1][j + 1][min(400, k + b[i])] += f[i][j][k] * p[i];
            f[i + 1][j][k] += f[i][j][k] * (1 - p[i]);
          }
        }
      }
    }
    double ans = 0;
    for (int i = 200; i <= 400; i++) {
      for (int j = l; j <= n; j++) ans += f[n][j][i];
    }
    cout << ans << endl;
  }
}
