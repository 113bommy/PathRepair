#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long INF = 1e9, MOD = INF + 7;
long long gcd(long long a, long long b) { return (b ? gcd(b, a % b) : a); }
long long power(long long a, long long b) {
  return (!b ? 1 : power(a, b / 2) * power(a, b / 2) * (b % 2 ? a : 1));
}
long long mod(long long a) { return (a % MOD + MOD) % MOD; }
const long long N = 1e6 + 20;
long long l[N], r[N];
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n, ans = 0;
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> l[i] >> r[i];
  sort(l, l + n);
  sort(r, r + n);
  for (long long i = 0; i < n; i++) ans += max(l[i], r[i]) + 1;
  cout << ans << "\n";
  return 0;
}
