#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main(void) {
  long long n;
  cin >> n;
  vector<long long> f(n + 1);
  f[0] = 1;
  for (long long i = 1; i <= n; i++) f[i] = f[i - 1] * i % mod;
  long long ans = f[n], sub = 1;
  for (int i = 1; i <= n - 1; i++) sub = 2 * sub % mod;
  ans = (ans - sub) % mod;
  ans < 0 ? ans + mod : ans;
  cout << ans << endl;
  return 0;
}
