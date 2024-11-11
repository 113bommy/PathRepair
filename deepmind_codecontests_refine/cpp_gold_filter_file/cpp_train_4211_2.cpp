#include <bits/stdc++.h>
using namespace std;
long long d[2001][2001];
long long ans;
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) d[1][i] = 1;
  for (int j = 2; j <= k; ++j) {
    d[j][1] += d[j - 1][1];
    d[j][1] %= 1000000007;
    for (int i = 2; i <= n; ++i) {
      d[j][i] += d[j - 1][i];
      d[j][i] += d[j - 1][1];
      d[j][i] %= 1000000007;
      for (int v = 2; v * v <= i; ++v)
        if (i % v == 0) {
          if (v * v == i) {
            d[j][i] += d[j - 1][v];
          } else {
            d[j][i] += d[j - 1][v];
            d[j][i] += d[j - 1][i / v];
          }
          d[j][i] %= 1000000007;
        }
    }
  }
  for (int i = 1; i <= n; ++i) {
    ans += d[k][i];
    ans %= 1000000007;
  }
  cout << ans;
  return 0;
}
