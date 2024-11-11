#include <bits/stdc++.h>
using namespace std;
int getmod(long long x, int mod) {
  if (x >= 32) return 32 + (x - 32) % mod;
  return x;
}
int phi(int n) {
  int res = n;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      res -= res / i;
    }
  if (n > 1) res -= res / n;
  return res;
}
vector<int> G;
int bp(int a, int n, int mod) {
  if (n == 0) return 1;
  if (n % 2) return getmod(1ll * bp(a, n - 1, mod) * a, mod);
  int t = bp(a, n / 2, mod);
  return getmod(1ll * t * t, mod);
}
int main() {
  int n, m;
  cin >> n >> m;
  G.push_back(m);
  while (m > 1) m = phi(m), G.push_back(m);
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    r = min(r, l + (int)G.size() - 1);
    int ans = 1;
    for (int j = r; j >= l; j--) {
      int x = ans;
      ans = bp(a[j], x, G[j - l]);
    }
    cout << ans << "\n";
  }
  return 0;
}
