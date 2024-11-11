#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;
long long power(long long a, int p, long long mod) {
  if (mod == 1) return 0;
  if (p == 0) return 1;
  if (p == 1) return a % mod;
  long long half = power(a, p / 2, mod);
  long long res = half * half % mod;
  if (p & 1) res = res * a % mod;
  return res;
}
long long reverse(long long a, long long mod) {
  long long rv = power(a, mod - 2, mod);
  return rv;
}
long long reverse_elem[2010];
long long C[2010];
long long repeat;
int n;
void init() {
  memset(reverse_elem, 0, sizeof reverse_elem);
  for (int i = 1; i <= 2000; ++i) {
    reverse_elem[i] = reverse(i, MOD);
  }
  C[0] = 1;
  for (int i = 1; i <= 2000; ++i) {
    C[i] = 1;
    for (int j = 1; j <= i; ++j) {
      C[i] = C[i] * (repeat - 1 + j) % MOD;
      C[i] = C[i] * reverse_elem[j] % MOD;
    }
  }
}
long long a[2010];
int main() {
  while (cin >> n >> repeat) {
    init();
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
      long long v = 0;
      for (int j = 0; j <= i; ++j) {
        v = (v + a[j] * C[i - j] % MOD) % MOD;
      }
      if (i) cout << " ";
      cout << v;
    }
    cout << endl;
  }
  return 0;
}
