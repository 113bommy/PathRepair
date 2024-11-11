#include <bits/stdc++.h>
using namespace std;
long long dp[100005];
long long mod = 1e9 + 7;
long long f, w, h, p, q, max_w;
long long powe(long long z, long long x) {
  if (x == 0) return 1;
  long long res = powe(z, x / 2);
  if (x % 2 == 1) return (((res * res) % mod) * z) % mod;
  return (res * res) % mod;
}
long long C(long long k, long long n) {
  return ((dp[n] * powe(dp[k], mod - 2)) % mod * powe(dp[n - k], mod - 2)) %
         mod;
}
int main() {
  dp[0] = 1;
  for (long long i = 1; i <= 100000; i++) dp[i] = (dp[i - 1] * i) % mod;
  cin >> f >> w >> h;
  if (w == 0) {
    cout << 1;
    return 0;
  }
  h++;
  max_w = w / h;
  for (long long i = 1; i <= max_w; i++) {
    if (f < i - 1) break;
    p += C(w - i * h, w - i * h + i - 1) * C(f - i + 1, f - i + 1 + i + 1 - 1);
    p %= mod;
  }
  for (long long i = 1; i <= w; i++) {
    if (f < i - 1) break;
    q += C(w - i, w - i + i - 1) * C(f - i + 1, f - i + 1 + i + 1 - 1);
    q %= mod;
  }
  cout << (p * powe(q, mod - 2)) % mod;
}
