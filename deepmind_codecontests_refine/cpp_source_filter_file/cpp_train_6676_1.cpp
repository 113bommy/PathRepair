#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
long long a[2000010], r[2000010];
long long po(long long base, long long x) {
  long long ret = 1;
  while (x) {
    if (x & 1) ret = ret * base % MOD;
    base = base * base % MOD;
    x >>= 1;
  }
  return ret;
}
void ntt(int n, int type) {
  for (int i = 1; i < n; i++) {
    r[i] = (r[i >> 1] >> 1) | ((i & 1) * (n >> 1));
    if (i < r[i]) swap(a[i], a[r[i]]);
  }
  for (int i = 1; i < n; i <<= 1) {
    long long wn = po(3, type * (MOD / (i * 2)) + MOD - 1);
    for (int j = 0; j < n; j += i * 2) {
      long long w = 1;
      for (int k = 0; k < i; k++) {
        int x = a[j + k], y = w * a[j + k + i] % MOD;
        a[j + k] = (x + y) % MOD;
        a[j + k + i] = (x - y + MOD) % MOD;
        w = w * wn % MOD;
      }
    }
  }
  if (type == 1) return;
  int invn = po(n, MOD - 2);
  for (int i = 0; i < n; i++) a[i] = a[i] * invn % MOD;
}
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  n >>= 1;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    a[x] = 1;
  }
  int d = 1;
  while (d <= n * 18) d <<= 1;
  ntt(d, 1);
  for (int i = 0; i < d; i++) a[i] = po(a[i], n);
  ntt(d, -1);
  long long ans = 0;
  for (int i = 0; i < n * 9; i++) ans = (ans + a[i] * a[i]) % MOD;
  cout << ans << "\n";
}
