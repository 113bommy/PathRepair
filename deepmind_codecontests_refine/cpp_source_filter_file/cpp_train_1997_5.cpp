#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 3;
const long long mod = 1e9 + 7;
long long t[maxn], fac[maxn], rev[maxn], pw[maxn];
long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long ret = power(a, b / 2);
  ret = 1ll * ret * ret % mod;
  if (b & 1) ret = 1ll * ret * a % mod;
  return ret;
}
long long Choose(long long n, long long r) {
  return 1ll * fac[n] * rev[r] % mod * rev[n - r] % mod;
}
long long get(long long a, long long b) {
  return 1ll * a * power(b, mod - 2) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long n;
  long long T;
  cin >> n >> T;
  pw[0] = 1;
  for (long long i = 1; i <= n; i++) pw[i] = pw[i - 1] * 2 % mod;
  fac[0] = 1;
  for (long long i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  rev[n] = power(fac[n], mod - 2);
  for (long long i = n - 1; i >= 0; i--)
    rev[i] = 1ll * rev[i + 1] * (i + 1) % mod;
  for (long long i = 1; i <= n; i++) cin >> t[i];
  long long idx = 0;
  for (long long i = 1; i <= n; i++) {
    T -= t[i];
    if (T < i) {
      T += t[i];
      idx = i;
      break;
    }
    idx = i;
    if (i == n) return cout << n << endl, 0;
  }
  long long answer = idx - 1;
  T -= t[idx];
  long long bin = 0;
  for (long long i = 0; i <= T; i++) bin = (bin + Choose(idx, i)) % mod;
  answer = (answer + get(bin, pw[idx])) % mod;
  for (long long i = idx + 1; i <= n; i++) {
    if (T - t[i] < 0) break;
    bin = (2ll * bin - Choose(i - 1, T) + 1 + mod) % mod;
    for (long long j = T; j > T - t[i]; j--)
      bin = (bin - Choose(i, j) + mod) % mod;
    answer = (answer + get(bin, pw[idx])) % mod;
    T -= t[i];
  }
  cout << answer << endl;
}
