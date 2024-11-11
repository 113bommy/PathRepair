#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9);
const long long Mod = 998244353;
const int Maxn = int(1e5);
int n, m;
vector<long long> fac(Maxn + 1), invfac(Maxn + 1);
long long fastpow(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = (ans * x) % Mod;
    x = (x * x) % Mod;
    y >>= 1;
  }
  return ans;
}
void init() {
  fac[0] = 1;
  for (int i = 1; i <= Maxn; i++) fac[i] = (fac[i - 1] * (long long)i) % Mod;
  invfac[Maxn] = fastpow(fac[Maxn], Mod - 2);
  for (int i = Maxn - 1; i >= 0; i--)
    invfac[i] = (invfac[i + 1] * (long long)(i + 1)) % Mod;
}
long long nCk(int k, int n) {
  long long ans = fac[n];
  ans = (ans * invfac[k]) % Mod;
  ans = (ans * invfac[n - k]) % Mod;
  return ans;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  long long ans = 0;
  if (n == 2)
    cout << 0;
  else {
    init();
    ans = nCk(n - 1, m);
    ans = (ans * fastpow(2, n - 3)) % Mod;
    ans = (ans * (long long)(n - 2)) % Mod;
    cout << ans;
  }
  return 0;
}
