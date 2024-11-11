#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1 << 18, N = 1e6 + 10, MOD = 998244353;
long long n;
long long silnia[N];
long long odsilnia[N];
long long pot3[N], pot1[N];
long long qpow(long long a, long long b) {
  if (b == 0)
    return 1;
  else if (b % 2 == 1)
    return (a * qpow(a, b - 1)) % MOD;
  else {
    long long ret = qpow(a, b / 2);
    return (ret * ret) % MOD;
  }
}
long long D(long long a, long long b) { return ((a + b) % MOD + MOD) % MOD; }
long long M(long long a, long long b) { return ((a * b) % MOD + MOD) % MOD; }
long long O(long long a, long long b) { return ((a - b) % MOD + MOD) % MOD; }
long long dwumian(long long a, long long b) {
  return M(silnia[b], M(odsilnia[a], odsilnia[b - a]));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  long long res = 0;
  silnia[0] = 1;
  for (long long i = 1; i < N; i++) silnia[i] = M(silnia[i - 1], i);
  odsilnia[N - 1] = qpow(silnia[N - 1], MOD - 2);
  for (long long i = N - 2; i >= 0; i--)
    odsilnia[i] = M(odsilnia[i + 1], i + 1);
  pot3[0] = 1;
  for (long long i = 1; i < N; i++) pot3[i] = M(3, pot3[i - 1]);
  pot1[0] = 1;
  for (long long i = 1; i < N; i++) pot1[i] = -1 * pot1[i - 1];
  for (long long i = 1; i <= n; i++)
    res = D(res, M(pot1[i + 1], M(dwumian(i, n), qpow(3, n * (n - i) + i))));
  res = M(res, 2);
  for (long long i = 0; i <= n - 1; i++) {
    long long ans = pot1[i + 1];
    ans = M(ans, 3);
    ans = M(ans, dwumian(i, n));
    long long pom = D(1, -pot3[i]);
    pom = qpow(pom, n);
    ans = M(ans, pom - qpow(-pot3[i], n));
    res = D(res, ans);
  }
  cout << res;
}
