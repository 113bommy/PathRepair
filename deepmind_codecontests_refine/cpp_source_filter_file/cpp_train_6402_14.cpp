#include <bits/stdc++.h>
using namespace std;
long long i, j, n, k, k1, k2, k3, m, x, y, fldgjdflgjhrthrl, fldggfhfghjdflgjl,
    fldgjdflgrtyrtyjl, ffgfldgjdflgjl, x3, y3, h, z, l1, l2, l3;
string s1, s2, s3, s, t;
long long a[1000500], fact[1000500], inv[1000500];
long long binpow(long long x, long long y) {
  if (y == 0) return 1;
  long long tmp = binpow(x, y / 2);
  tmp *= tmp;
  tmp %= 1000000007;
  if (y % 2 == 0) return tmp;
  return (x * tmp) % 1000000007;
}
long long C(long long n, long long k) {
  return (((fact[n] * inv[k]) % 1000000007) * inv[n - k]) % 1000000007;
}
int main() {
  fact[0] = 1;
  for (i = 1; i <= 1000300; i++) {
    fact[i] = (fact[i - 1] * i) % 1000000007;
    inv[i] = binpow(fact[i], 1000000007 - 2);
  }
  cin >> n;
  long long ans = 0;
  for (i = 0; i <= n; i++) ans += C(n + i + 1, n);
  cout << ans % 1000000007 << endl;
  return 0;
}
