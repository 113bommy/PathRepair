#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const long long MOD = 1e9 + 7;
long long Mul(long long a, long long b) { return a * b % MOD; }
void Add(long long &a, long long b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long t = binpow(a, b >> 1);
  t = Mul(t, t);
  if (b % 2) return Mul(a, t);
  return t;
}
long long fact[N], inv[N], powN[N];
void Init(int n) {
  fact[0] = 1;
  for (int i = 1; i < N; ++i) fact[i] = Mul(fact[i - 1], i);
  inv[N - 1] = binpow(fact[N - 1], MOD - 2);
  for (int i = N - 2; i >= 0; --i) inv[i] = Mul(inv[i + 1], i + 1);
  powN[0] = 1;
  for (int i = 1; i <= n; ++i) powN[i] = Mul(powN[i - 1], n);
}
long long C(int k, int n) {
  if (k > n) return 0;
  return Mul(fact[n], Mul(inv[k], inv[n - k]));
}
long long A(int k, int n) {
  if (k > n) return 0;
  return Mul(fact[n], inv[n - k]);
}
long long F(int n, int k) {
  if (n <= k) return 1;
  return Mul(k, powN[k]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  Init(n);
  long long ans = 0;
  for (int x = 2; x <= n; ++x) {
    long long now = Mul(C(x - 2, m - 1), A(x - 2, n - 2));
    now = Mul(now, Mul(1, binpow(m, n - x)));
    now = Mul(now, F(n, x));
    ans = (ans + now) % MOD;
  }
  cout << ans;
}
