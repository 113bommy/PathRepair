#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long mod;
void multiply(long long F[2][2], long long M[2][2]) {
  long long x = ((F[0][0] * M[0][0]) % mod + (F[0][1] * M[1][0]) % mod) % mod;
  long long y = ((F[0][0] * M[0][1]) % mod + (F[0][1] * M[1][1]) % mod) % mod;
  long long z = ((F[1][0] * M[0][0]) % mod + (F[1][1] * M[1][0]) % mod) % mod;
  long long w = ((F[1][0] * M[0][1]) % mod + (F[1][1] * M[1][1]) % mod) % mod;
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
void power(long long F[2][2], long long n) {
  if (n == 0 || n == 1) return;
  long long M[2][2] = {{1, 1}, {1, 0}};
  power(F, n / 2);
  multiply(F, F);
  if (n % 2 != 0) multiply(F, M);
}
long long fib(long long n) {
  long long F[2][2] = {{1, 1}, {1, 0}};
  if (n == 0) return 0;
  power(F, n - 1);
  return F[0][0];
}
long long nthFib(long long n) { return fib(n); }
long long be(long long b, long long e) {
  if (e == 0) return 1;
  if (e % 2 == 0) {
    long long x = be(b, e / 2);
    return (x * x) % mod;
  } else
    return (be(b, e - 1) * b) % mod;
}
int main() {
  long long n, k, l;
  cin >> n >> k >> l >> mod;
  if (mod == 1 || (l < 63 && ((long long)1 << l) <= k))
    return cout << 0 << endl, 0;
  if (l == 0) {
    if (k == 0)
      cout << 1 << endl;
    else
      cout << 0 << endl;
    return 0;
  }
  long long ans = 1;
  long long zero = nthFib(n + 2);
  long long one = (be(2, n) - nthFib(n + 2) + mod) % mod;
  vector<bool> bt;
  while (k) {
    bt.push_back(k & 1);
    k = k >> 1;
  }
  while (bt.size() != l) bt.push_back(0);
  reverse(bt.begin(), bt.end());
  for (int i = 0; i < bt.size(); ++i) {
    if (!bt[i])
      ans = (ans * zero) % mod;
    else
      ans = (ans * one) % mod;
  }
  cout << ans << endl;
}
