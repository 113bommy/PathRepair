#include <bits/stdc++.h>
using namespace std;
const int maxn = 6 * 1e6;
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
long long prime[maxn * 2];
bool isprime[maxn] = {0};
void getprime() {
  memset(prime, 0, sizeof(prime));
  for (int i = 2; i <= maxn; i++) {
    if (!prime[i]) {
      prime[++prime[0]] = i;
      isprime[i] = 1;
    }
    for (int j = 1; j <= prime[0] && prime[j] <= maxn / i; j++) {
      prime[prime[j] * i] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
long long f[maxn * 2] = {0};
int main() {
  if (fopen("/home/lianyi/123.txt", "r") != NULL) {
    freopen("/home/lianyi/123.txt", "r", stdin);
  } else {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
  }
  getprime();
  long long t, l, r;
  f[1] = 1;
  for (long long i = 2; i <= maxn; i++) {
    if (isprime[i]) {
      f[i] = i * (i - 1) / 2;
      f[i] %= mod;
      continue;
    }
    for (int j = 1;; j++) {
      if (i % prime[j] == 0) {
        f[i] = f[i / prime[j]] + i * (prime[j] - 1) / 2 % mod;
        f[i] %= mod;
        break;
      }
    }
  }
  while (cin >> t >> l >> r) {
    long long x = 1;
    long long res = 0;
    for (long long i = l; i <= r; i++) {
      res = (res + f[i] * x % mod) % mod;
      x = x * t % mod;
    }
    cout << res << '\n';
  }
  return 0;
}
