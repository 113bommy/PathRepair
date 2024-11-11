#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long f[N + 5];
long long inv[N + 5];
int mod = 1e9 + 7;
long long fp(long long b, long long p) {
  if (p == 0) return 1;
  long long tmp = fp(b, p / 2);
  if (p % 2)
    return (((tmp * tmp) % mod) * b) % mod;
  else
    return (tmp * tmp) % mod;
}
long long ncr(int n, int r) {
  return (((f[n] * inv[r]) % mod) * inv[n - r]) % mod;
}
int main() {
  long long n;
  cin >> n;
  f[0] = 1;
  for (int i = 1; i <= N; i++) f[i] = (f[i - 1] * i) % mod;
  for (int i = 0; i <= N; i++) {
    inv[i] = fp(f[i], mod - 2);
  }
  cout << ((((ncr(2 * n - 1, n) * 2) % mod) - n) + mod) % mod << endl;
  return 0;
}
