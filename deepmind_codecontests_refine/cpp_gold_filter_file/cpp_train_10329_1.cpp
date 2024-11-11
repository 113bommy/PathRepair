#include <bits/stdc++.h>
using namespace std;
const long long ms = 3e5 + 100;
const long long sigma = 30;
long long n, m, k, t;
long long fac[ms];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  fac[1] = 1;
  for (long long i = 2; i <= n; i++) {
    fac[i] = (fac[i - 1] * i) % m;
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    ans = (ans + (((n - i + 1) * fac[n - i + 1]) % m) * fac[i]) % m;
  }
  cout << ans << '\n';
}
