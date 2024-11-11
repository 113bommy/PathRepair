#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
int cl(int x, int y) { return (x / y) + (x % y != 0); }
int vis[200001] = {0}, pos[200001] = {0};
void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> a(n), b(k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) vis[i] = 0;
  for (int i = 0; i < n; i++) {
    pos[a[i]] = i;
  }
  for (int i = 0; i < k; i++) {
    scanf("%d", &b[i]);
    vis[b[i]] = 1;
  }
  long long ans = 1;
  for (int i = 0; i < k; i++) {
    int x = pos[b[i]];
    vis[b[i]] = 0;
    if (!x) {
      if (vis[a[1]]) ans = 0;
    } else if (x == n - 1) {
      if (vis[a[n - 1]]) ans = 0;
    } else if (vis[a[x - 1]] && vis[a[x + 1]])
      ans = 0;
    else if (!vis[a[x - 1]] && !vis[a[x + 1]])
      ans *= 2;
    ans %= mod;
  }
  printf("%lld\n", ans);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
