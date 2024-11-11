#include <bits/stdc++.h>
using namespace std;
int n, inv[25];
const int mod = 1e9 + 7;
long long m, f[25], ans;
long long C(long long x, int y) {
  if (x < 0 || y < 0 || x < y) return 0;
  x %= mod;
  if (y == 0) return 1;
  long long ans = 1;
  for (int i = 0; i < y; i++) ans = (ans * (x - i)) % mod;
  for (int i = 1; i <= y; i++) ans = (ans * inv[i]) % mod;
  return ans;
}
int ksm(int a, int b, int p) {
  int re = 1;
  while (b) {
    if (b & 1) re = ((long long)re * a) % p;
    a = ((long long)a * a) % p;
    b >>= 1;
  }
  return re;
}
int main() {
  for (int i = 1; i <= 20; i++) inv[i] = ksm(i, mod - 2, mod);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> f[i];
  for (int x = 0; x < (1 << n); x++) {
    int p = 0;
    long long tmp = n + m;
    for (int i = 0; i < n; i++)
      if (x & (1 << i)) {
        p++;
        tmp -= f[i + 1];
      }
    tmp -= p + 1;
    if (p & 1)
      ans = (ans - C(tmp, n - 1)) % mod;
    else
      ans = (ans + C(tmp, n - 1)) % mod;
  }
  ans = (ans + mod) % mod;
  cout << ans << endl;
  return 0;
}
