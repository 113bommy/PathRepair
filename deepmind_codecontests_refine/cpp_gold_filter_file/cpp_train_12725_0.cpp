#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
long long MOD = 998244353;
long long exp(long long n, long long e) {
  if (e == 0) return 1;
  long long temp = exp((n * n) % MOD, e / 2);
  return e % 2 == 0 ? temp : (temp * n) % MOD;
}
long long inverse(long long n) { return exp(n, MOD - 2); }
void frac(long long p, long long q) {
  cout << (p * inverse(q)) % MOD << endl;
  ;
}
long long gp_sum(long long a, long long n, long long r) {
  if (r == 1) {
    return (a * n) % MOD;
  }
  long long ans = exp(r, n + 1);
  ans = (ans - 1 + MOD) % MOD;
  ans = (ans * a) % MOD;
  ans = ans * inverse((r - 1 + MOD) % MOD);
  ans %= MOD;
  return ans;
}
long long norm(long long n) {
  n %= MOD;
  n += MOD;
  n %= MOD;
  return n;
}
void solve() {
  long long n, m, l, r;
  cin >> n >> m >> l >> r;
  long long total = exp(r - l + 1, n * m);
  if (n % 2 == 1 && m % 2 == 1) {
    cout << total << endl;
    return;
  }
  long long e = r / 2 - (l - 1) / 2;
  long long o = r - l + 1 - e;
  long long ans = exp(e, (n * m));
  long long x = (o * inverse(e)) % MOD;
  long long temp = exp((1 + x) % MOD, n * m);
  temp = temp - exp((((1 - x) % MOD + MOD) % MOD), n * m);
  temp %= MOD;
  temp += MOD;
  temp %= MOD;
  temp = (temp * inverse(2)) % MOD;
  ans = (ans * temp) % MOD;
  long long fans = total - ans;
  fans = norm(fans);
  cout << fans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
