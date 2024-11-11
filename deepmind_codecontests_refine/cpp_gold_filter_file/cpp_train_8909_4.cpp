#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long n, m, i, j, t, a[1000000], f[1000000], po[1000000], ans;
int main() {
  cin >> n;
  for (po[0] = i = 1; i <= n; i++) po[i] = po[i - 1] * 2 % mod;
  while (n--) cin >> i, a[i]++, m = i > m ? i : m;
  for (i = 1; i <= m; i++) {
    for (t = 0, j = i; j <= m; j += i) t += a[j];
    f[i] = po[t] - 1;
  }
  for (i = m; i; i--)
    for (j = i + i; j <= m; j += i) f[i] = (f[i] - f[j] + mod) % mod;
  cout << f[1];
  return 0;
}
