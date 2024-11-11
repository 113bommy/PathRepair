#include <bits/stdc++.h>
using namespace std;
long long s[300001];
long long sum = 0, mod = 998244353;
long long ny(int n);
long long qmksm(long long a, long long b, long long m);
long long zhs(long long n) {
  long long i, j, zc = 1;
  for (i = 1; i <= n; i++) {
    zc *= ((i + n) % mod) * (ny(i) % mod) % mod;
    zc %= mod;
  }
  return zc;
}
long long ny(int n) {
  int i;
  return qmksm(n, mod - 2, mod) % mod;
}
long long qmksm(long long a, long long b, long long m) {
  long long s = 1, z = a % m;
  while (b > 0) {
    if (b & 1 == 1) {
      s *= z;
      s %= m;
    }
    z *= z;
    z %= m;
    b >>= 1;
  }
  return s;
}
int main() {
  long long n, i, j;
  cin >> n;
  for (i = 1; i <= n * 2; i++) cin >> s[i];
  sort(s + 1, s + 1 + n * 2);
  for (i = 1, sum = 0; i <= n; i++) {
    sum += (s[i + n] - s[i]) % mod;
    sum %= mod;
  }
  cout << ((zhs(n) % mod) * sum) % mod;
  return 0;
}
