#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
const int mod = 1e9 + 7;
int n, m;
long long ans;
long long inv[N], f1[N], f2[N], pn[N], pm[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  inv[1] = f1[0] = f2[0] = pn[0] = pm[0] = 1;
  for (int i = 2; i < N; i++) {
    inv[i] = mod - (mod / i * inv[mod % i]) % mod;
  }
  for (int i = 1; i < N; i++) {
    f1[i] = f1[i - 1] * i % mod;
    f2[i] = f2[i - 1] * inv[i] % mod;
    pn[i] = pn[i - 1] * n % mod;
    pm[i] = pm[i - 1] * m % mod;
  }
  for (int i = 1; i <= min(n - 1, m); i++) {
    ans += f1[m - 1] * f2[i - 1] % mod * f2[m - i] % mod * f1[n - 2] % mod *
           f2[n - i - 1] % mod * pm[n - i - 1] % mod *
           (i < n - 1 ? pn[n - i - 2] * (i + 1) % mod : 1) % mod;
  }
  cout << ans << '\n';
  return 0;
}
