#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int INF = 1e9 + 7;
const int N = 2e5 + 7;
const int M = 5e6 + 7;
int a[N], phi[31];
int n, mod;
int get(int x) {
  int ans = x;
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) {
      ans = ans / i * (i - 1);
      while (x % i == 0) x /= i;
    }
  if (x != 1) ans = ans / x * (x - 1);
  return ans;
}
int gg(long long x, int p) { return x >= p ? x % p + p : x; }
int qpow(int a, int b, int p) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = gg(1ll * ans * a, p);
    a = gg(1ll * a * a, p);
    b >>= 1;
  }
  return ans % p;
}
int dfs(int l, int r, int i) {
  if (l == r || phi[i] == 1) return gg(a[l], phi[i]);
  return qpow(a[l], dfs(l + 1, r, i + 1), phi[i]);
}
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> mod;
  phi[0] = mod;
  for (int i = 1; i <= 30; i++) phi[i] = get(phi[i - 1]);
  for (int i = 1; i <= n; i++) cin >> a[i];
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    printf("%d\n", dfs(l, r, 0) % mod);
  }
  return 0;
}
