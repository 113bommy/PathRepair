#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f;
long long sum[4000010], f[4000010];
signed main() {
  long long n, m;
  sum[1] = 1;
  f[1] = 1;
  cin >> n >> m;
  f[n] = sum[n] = 1;
  for (long long i = n - 1; i >= 1; i--) {
    f[i] = sum[i + 1];
    for (long long j = 2; i * j <= n; j++) {
      long long l = i * j, r = min(n, (i + 1) * j - 1);
      if (l <= r) f[i] = ((f[i] + sum[l]) % m - sum[r + 1]) % m;
    }
    sum[i] = (sum[i + 1] + f[i]) % m;
  }
  cout << (f[1] + m) % m << '\n';
}
