#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long n, m, a, b, c, d, p;
long long add(long long first, long long second) {
  return (first + second) % MOD;
}
long long sub(long long first, long long second) {
  return add(first, MOD - second);
}
long long mul(long long first, long long second) {
  return first * second % MOD;
}
long long binpow(long long first, long long second) {
  if (second == 0) return 1;
  if (second % 2) return mul(first, binpow(first, second - 1));
  long long z = binpow(first, second / 2);
  return mul(z, z);
}
long long inv(long long first) { return binpow(first, MOD - 2); }
long long divide(long long first, long long second) {
  return mul(first, inv(second));
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n >> m >> a >> b >> c >> d >> p;
    long long first = a, second = b;
    long long ans = 0, dr = 1, dc = 1;
    vector<long long> v;
    while (ans == 0 || first != a || second != b ||
           (first > 1 && first < n && dr != 1) ||
           (second > 1 && second < m && dc != 1)) {
      if (a == c || b == d) v.push_back(ans);
      if (a == n) dr = -1;
      if (a == 1) dr = 1;
      if (b == m) dc = -1;
      if (b == 1) dc = 1;
      a += dr;
      b += dc;
      ans++;
    }
    p = divide(p, 100);
    long long ans2 = 0;
    for (long long i = 0; i < v.size(); i++) {
      long long A = v[i];
      long long P = mul(p, binpow(sub(1, p), i));
      long long Q = binpow(sub(1, p), v.size());
      long long S = ans;
      ans2 = add(ans2, add(divide(mul(A, P), sub(1, Q)),
                           divide(mul(S, mul(P, Q)), binpow(sub(1, Q), 2))));
    }
    cout << ans2 << "\n";
  }
}
