#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 14, mod = 1e9 + 7;
int n;
long long T, t[maxn];
int po2[maxn], fac[maxn], rfac[maxn];
int rev(int a) {
  int ans = 1;
  for (int b = mod - 2; b; b >>= 1, a = (long long)a * a % mod)
    if (b & 1) ans = (long long)ans * a % mod;
  return ans;
}
void prep() {
  fac[0] = rfac[0] = po2[0] = 1;
  for (int i = 1; i <= n; i++) {
    po2[i] = po2[i - 1] * 2 % mod;
    fac[i] = (long long)i * fac[i - 1] % mod;
    rfac[i] = rev(fac[i]);
  }
}
int c(int n, int r) {
  return (long long)fac[n] * rfac[r] % mod * rfac[n - r] % mod;
}
int sumc(int n, long long r) {
  if (r < 0) return 0;
  if (r >= n) return po2[n];
  static int curn = n, curr = 0, curans = 0;
  assert(curn >= n && curr <= r);
  while (curn > n) {
    curn--;
    curans = (curans + c(curn, curr)) % mod;
    curans = (long long)curans * rev(2) % mod;
  }
  while (curr <= r) curans = (curans + c(n, curr++)) % mod;
  return curans;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> T;
  prep();
  for (int i = 0; i < n; i++) {
    cin >> t[i + 1];
    t[i + 1] += t[i];
  }
  int ans = 0, last = 0;
  for (int i = n; i > 0; i--) {
    int prob =
        (long long)sumc(i, min<long long>(T - t[i], i)) * rev(po2[i]) % mod;
    ans = (ans + (long long)(prob - last + mod) * i) % mod;
    last = prob;
  }
  cout << ans << '\n';
}
