#include <bits/stdc++.h>
using namespace std;
const int maxN = 200 * 1000 + 5;
const long long mod = 1000 * 1000 * 1000 + 7;
long long fact[maxN];
long long mul(long long x, long long y) { return (x * y) % mod; }
long long add(long long x, long long y) { return (x + y) % mod; }
long long pw(long long x, int k) {
  if (k == 0) return 1;
  long long res = pw(x, k / 2);
  res = mul(res, res);
  if (k % 2) return mul(res, x);
  return res;
}
long long C(int x, int y) {
  return mul(fact[x], mul(pw(fact[y], mod - 2), pw(fact[x - y], mod - 2)));
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m, g;
  cin >> n >> m >> g;
  if (m == 0) {
    cout << ((n % 2) ^ g) << endl;
    return 0;
  }
  fact[0] = 1;
  for (int i = 1; i <= n + m; i++) fact[i] = fact[i - 1] * i;
  long long ans = 0;
  if (g == 0) {
    if (m == 1 && n % 2 == 1) ans++;
    for (int i = 0; i <= n; i += 2) {
      if (n + m - i == 1) continue;
      ans += C(n + m - i - 1, m - 1);
      ans %= mod;
    }
  } else {
    if (m == 1 && n % 2 == 0) ans++;
    for (int i = 1; i <= n; i += 2) {
      if (n + m - i == 1) continue;
      ans += C(n + m - i - 1, m - 1);
      ans %= mod;
    }
  }
  cout << ans % mod << endl;
  return 0;
}
