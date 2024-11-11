#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
const long long INF = 1e18 + 7;
int n, a[MAXN], d[MAXN] = {}, k, l = 1, r = 0;
long long f[MAXN], g[MAXN], ans = 0;
void add(long long &a, const long long &b) {
  a += b;
  if (a > INF) a = INF;
}
long long sum(long long a, long long b) {
  a += b;
  if (a > INF) a = INF;
  return a;
}
void cost(int newl, int newr) {
  while (r < newr) ans += 1LL * (d[a[++r]]++);
  while (r > newr) ans -= 1LL * (--d[a[r--]]);
  while (l > newl) ans += 1LL * (d[a[--l]]++);
  while (l < newl) ans -= 1LL * (--d[a[l++]]);
}
void calc(int l, int r, int mn, int mx) {
  if (l > r) return;
  int mid = (l + r) >> 1, opt = 0;
  for (int i = min(mx, mid - 1); i >= mn; --i) {
    cost(i + 1, mid);
    if (g[i] + ans < f[mid]) f[mid] = g[i] + ans, opt = i;
  }
  calc(l, mid - 1, mn, opt);
  calc(mid + 1, r, opt, mx);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  g[0] = f[0] = 0;
  for (int i = 1; i <= n; ++i) f[i] = g[i] = INF;
  for (int i = 1; i <= k; ++i) {
    calc(1, n, 0, n);
    for (int j = 1; j <= n; ++j) g[j] = f[j], f[j] = INF;
  }
  cout << g[n];
  return 0;
}
