#include <bits/stdc++.h>
using namespace std;
int n, k, g[1000005], f[1000005];
int main() {
  int i, n, k, s = 0, ans, c;
  cin >> n >> k;
  g[0] = c = 1;
  ans = n;
  for (i = 1; i <= n; i++) {
    f[i] = (-1ll * (1000000007 / i) * f[1000000007 % i] % 1000000007 +
            1000000007 + (i == 1)) %
           1000000007;
    s = (s + g[i - 1]) % 1000000007;
    if (i > k) s = (s - g[i - k - 1] + 1000000007) % 1000000007;
    g[i] = 1ll * s * f[i] % 1000000007;
    ans = (ans - g[i - 1] + 1000000007) % 1000000007;
    if (i != 1) c = 1ll * c * (i - 1) % 1000000007;
  }
  cout << c * ans % 1000000007 << endl;
  return 0;
}
