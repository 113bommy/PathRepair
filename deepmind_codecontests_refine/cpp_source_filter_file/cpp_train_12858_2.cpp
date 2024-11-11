#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, inv2 = 500000004;
long long n, m, ans;
long long inline fix(long long a) { return a >= mod ? a % mod : a; }
long long inline mul(long long a, long long b) { return fix(a) * fix(b) % mod; }
long long inline add(long long a, long long b) {
  return (fix(a) + fix(b)) % mod;
}
int main() {
  cin >> n >> m;
  for (long long d = 1, l, r; d < min(n, m); d = r + 1) {
    l = min(d, m), r = min(n / (n / d), m);
    ans = add(ans, mul(n / d, mul(mul(r - l + 1, l + r), inv2)));
  }
  ans = mul(n, m) - ans;
  ans = (ans % mod + mod) % mod;
  cout << ans << '\n';
}
