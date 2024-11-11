#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9, MOD = INF + 7;
int gcd(int a, int b) { return (b ? gcd(b, a % b) : a); }
int mod(int n) {
  while (n < 0) n += MOD;
  return n % MOD;
}
const int N = 5e3 + 20;
pair<int, int> a[N];
int c[N];
int cnt, n;
bool ok;
int d(int x, int y) {
  return abs(a[x].first - a[y].first) + abs(a[x].second - a[y].second);
}
void dfs(int v, int color, int k) {
  c[v] = color;
  for (int u = 0; u < n; u++) {
    if (d(u, v) <= k) continue;
    if (c[u] == color)
      ok = false;
    else if (c[u] == -1)
      dfs(u, 1 - color, k);
  }
  return;
}
bool isOK(int k) {
  cnt = 1;
  ok = true;
  memset(c, -1, sizeof c);
  for (int i = 0; i < n; i++) {
    if (c[i] == -1) {
      cnt *= 2;
      cnt %= MOD;
      dfs(i, 0, k);
    }
  }
  return ok;
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  int dw = -1, up = 1e4 + 1;
  while (up - dw > 1) {
    int md = (dw + up) / 2;
    if (isOK(md))
      up = md;
    else
      dw = md;
  }
  cout << up << "\n" << cnt % MOD << "\n";
  return 0;
}
