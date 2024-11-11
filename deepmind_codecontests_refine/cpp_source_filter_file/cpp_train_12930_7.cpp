#include <bits/stdc++.h>
using namespace std;
int n, k, v[200002];
const int mod = 998244353;
int nxt(int poz) {
  if (poz == n) return 1;
  return poz + 1;
}
long long pw(long long b, long long e) {
  long long ans = 1;
  while (e) {
    if (e & 1) ans = (ans * b) % mod;
    b = (b * b) % mod;
    e >>= 1;
  }
  return ans;
}
long long fact[200002], inv[200002];
long long C(long long n, long long k) {
  long long ans = (fact[n] * inv[k]) % mod;
  ans = (ans * inv[n - k]) % mod;
  return ans;
}
int main() {
  if (1) ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> v[i];
  fact[0] = inv[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = (fact[i - 1] * i) % mod;
    inv[i] = pw(fact[i], mod - 2);
  }
  int eq = 0;
  for (int i = 1; i <= n; ++i)
    if (v[i] == v[nxt(i)]) ++eq;
  long long ans = 1;
  for (int i = 1; i <= eq; ++i) ans = (ans * k) % mod;
  n -= eq;
  long long ans2 = 0;
  for (int i = 1; i <= n; ++i) {
    long long total = (pw(k - 2, n - i) * C(n, n - i)) % mod;
    long long totalcomb = pw(2, i);
    long long comb2 = 0;
    if (i % 2 == 0) comb2 = C(i, i / 2);
    totalcomb = totalcomb - comb2 + mod;
    totalcomb %= mod;
    totalcomb = totalcomb * pw(2, mod - 2);
    total *= totalcomb;
    total %= mod;
    ans2 = (ans2 + total) % mod;
  }
  cout << (ans * ans2) % mod;
  return 0;
}
