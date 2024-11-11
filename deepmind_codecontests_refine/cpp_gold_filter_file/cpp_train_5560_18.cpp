#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long modpow(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long ans = modpow(a, b / 2);
  ans = ans * ans % mod;
  if (b & 1) ans = ans * a % mod;
  return ans;
}
long long modinv(long long x) { return modpow(x, mod - 2); }
long long frac[100001];
void build_frac() {
  frac[0] = 1;
  for (int i = 1; i <= 100000; i++) {
    frac[i] = frac[i - 1] * i % mod;
  }
}
long long c(long long m, long long n) {
  if (m < n) return -1;
  long long ans = frac[m];
  ans = ans * modinv(frac[n]) % mod;
  ans = ans * modinv(frac[m - n]) % mod;
  return ans;
}
void solve() {
  int n;
  cin >> n;
  build_frac();
  int a[n + 1], cnt = 0;
  set<int> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > 0)
      s.insert(a[i]);
    else
      cnt++;
  }
  int x = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == -1 && s.count(i) == 1) x++;
  }
  x = cnt - x;
  long long ans = frac[cnt];
  for (int i = 1; i <= x; i++) {
    long long tmp = c(x, i) * frac[cnt - i] % mod;
    if (i % 2)
      ans = (ans - tmp + mod) % mod;
    else
      ans = (ans + tmp) % mod;
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) solve();
}
