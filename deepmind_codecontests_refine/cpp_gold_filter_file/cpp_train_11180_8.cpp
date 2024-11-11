#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000000;
int main() {
  int n, m;
  long long f[105];
  f[0] = f[1] = 1;
  for (int i = 2; i < 105; i++) {
    f[i] = (f[i - 1] + f[i - 2]) % MOD;
  }
  long long a[105];
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int type, l, r;
  for (int i = 0; i < m; i++) {
    cin >> type >> l >> r;
    if (type == 1)
      a[l] = r;
    else {
      long long ans = 0;
      for (int x = 0; x <= r - l; x++) {
        ans += a[l + x] * f[x];
        ans %= MOD;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
