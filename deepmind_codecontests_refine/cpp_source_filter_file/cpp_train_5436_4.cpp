#include <bits/stdc++.h>
using namespace std;
long long expo(long long base, long long exponent, long long mod) {
  long long ans = 1;
  while (exponent != 0) {
    if (exponent & 1) ans = (ans * base) % mod;
    base = (base * base) % mod;
    exponent >>= 1;
  }
  return ans % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) {
    long long fact[1005];
    fact[0] = 1;
    long long n, k;
    cin >> n >> k;
    for (long long int i = 1; i < 1005; i++) {
      fact[i] = (fact[i - 1] * i) % 1000000007;
    }
    long long ans =
        (fact[n + 2 * k - 1] * expo(fact[2 * k], 1000000007 - 2, 1000000007)) %
        1000000007;
    ans = (ans * expo(fact[n - 1], 1000000007 - 2, 1000000007)) % 1000000007;
    cout << ans << '\n';
  }
  return 0;
}
