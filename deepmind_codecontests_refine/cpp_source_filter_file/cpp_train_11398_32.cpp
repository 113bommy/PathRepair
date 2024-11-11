#include <bits/stdc++.h>
using namespace std;
long long f[1020][101] = {0};
int main() {
  int n, k, m;
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 1; i <= 9; i++) f[1][i % k]++;
  long long p10 = 1;
  for (int i = 2; i <= n; i++) {
    p10 *= 10;
    p10 %= k;
    for (int j = 0; j < k; j++) {
      for (int t = 0; t <= 9; t++) {
        long long d = p10 * t;
        d %= k;
        d = k - d;
        if ((j + d) % k) {
          f[i][j] += f[i - 1][(j + d) % k];
          f[i][j] %= m;
        }
      }
    }
    for (int t = 1; t <= 9; t++) {
      long long d = p10 * t;
      d %= k;
      f[i][d]++;
    }
  }
  p10 = 1;
  long long ans = f[n][0];
  for (int i = n - 1; i >= 1; i--) {
    long long tmp = p10 * 9;
    tmp %= m;
    tmp *= f[i][0];
    tmp %= m;
    ans += tmp;
    ans %= m;
    p10 *= 10;
    p10 %= m;
  }
  cout << ans << endl;
  return 0;
}
