#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
long long mod = 1e9 + 7;
long long fmod(long long b, long long exp) {
  long long res = 1;
  while (exp) {
    if (exp & 1ll) res = (res * b) % mod;
    b = (b * b) % mod;
    exp /= 2ll;
  }
  return res;
}
long long A[N], fact[N], inv[N];
int buc[N];
long long comb(int n, int r) {
  if (n < r || n < 0 || r < 0) return 0;
  long long res = (inv[r] * inv[n - r]) % mod;
  return (res * fact[n]) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1, n, i, j;
  cin >> n;
  int cnt = 0, pos = 0;
  int fl = 0;
  for (i = 1; i <= n; i++) {
    cin >> A[i];
    if (A[i] == i) fl = 1;
    if (A[i] + 1) buc[A[i]] = 1;
    if (A[i] == -1) {
      cnt++;
    }
  }
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = (1ll * i * fact[i - 1]) % mod;
  inv[n] = fmod(fact[n], mod - 2);
  for (int i = n - 1; i >= 0; i--) inv[i] = (1ll * (i + 1) * inv[i + 1]) % mod;
  if (fl)
    cout << "0\n";
  else {
    for (i = 1; i <= n; i++)
      if (A[i] == -1 && buc[i] == 0) pos++;
    long long ans = 0;
    long long sn = 1;
    for (int i = 0; i <= pos; i++) {
      long long cur = (comb(cnt, i) * fact[cnt - i]) % mod;
      ans = (ans + (cur * sn) + mod) % mod;
      sn = -sn;
    }
    cout << ans << "\n";
  }
  return 0;
}
