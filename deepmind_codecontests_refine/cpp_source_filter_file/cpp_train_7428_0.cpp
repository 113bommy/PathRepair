#include <bits/stdc++.h>
using namespace std;
const int maxn = 3 * 1000 * 1000 + 10;
const long long mod = 1000 * 1000 * 1000 + 7;
const long long inf = 1LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 10;
long long pw(long long a, long long b) {
  return (b == 0 ? 1LL
                 : ((pw(a * a % mod, b / 2) * (b & 1 == 1 ? a : 1LL)) % mod));
}
long long comb(long long n, long long k) {
  long long _max = max(k, n - k), _min = min(k, n - k), f = 1, s = 1;
  for (int i = 0; i < n - _max; i++) {
    f *= n - i;
    f %= mod;
  }
  for (int i = 1; i <= _min; i++) {
    s *= i;
    s %= mod;
  }
  return ((f * pw(s, mod - 2)) % mod);
}
long long arr[maxn], fact[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> arr[i];
  if (k == 0) {
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) fact[i] = comb(k - 1 + i, i);
  reverse(fact, fact + n);
  for (int i = 0; i < n; i++) {
    long long a = 0;
    for (int j = 0; j <= i; j++) {
      a += (arr[j] * fact[n - j - 1]) % mod;
      a %= mod;
    }
    cout << a << ' ';
  }
  cout << endl;
  return 0;
}
