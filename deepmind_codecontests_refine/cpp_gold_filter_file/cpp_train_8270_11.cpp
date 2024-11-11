#include <bits/stdc++.h>
using namespace std;
long long h, dp[300000][2], r, g, mod = 1e9 + 7;
int main() {
  while (cin >> r >> g) {
    int tmp = 1, h = 0;
    while (tmp <= r + g) {
      h++;
      tmp = h * (h + 1) / 2;
    }
    h--;
    for (int i = h; i >= 0; i--) {
      for (int j = 0; j <= r; j++) {
        if (i * (i + 1) / 2 - j > g || i * (i + 1) / 2 - j < 0)
          dp[j][i % 2] = 0;
        else if (i == h)
          dp[j][i % 2] = 1;
        else
          dp[j][i % 2] =
              (dp[j + i + 1][(i + 1) % 2] + dp[j][(i + 1) % 2]) % mod;
      }
    }
    cout << dp[0][0] << endl;
  }
}
