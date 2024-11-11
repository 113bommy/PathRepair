#include <bits/stdc++.h>
using namespace std;
int const N = 300 + 20, MX = 1e5;
long long inf = 1e18;
int n, m, k;
long double fac[MX], ans;
inline long double c(int a, int b) { return fac[b] - fac[a] - fac[b - a]; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  fac[0] = 0;
  for (int i = 1; i < MX; i++) fac[i] = fac[i - 1] + log(i);
  cin >> n >> m >> k;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) {
      int t = i * n + j * n - i * j;
      if (t <= k) ans += exp(c(i, n) + c(j, n) + c(k - t, m - t) - c(k, m));
      if (ans >= 1e99) return cout << "1e99\n", 0;
    }
  cout << setprecision(20) << ans << '\n';
}
