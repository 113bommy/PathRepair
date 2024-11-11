#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
const int MOD = 1e9 + 7;
int n, m, pos;
long long jc[maxn];
long long er[maxn];
int vis[maxn];
void init() {
  jc[0] = er[0] = 1;
  for (int i = 1; i <= n; i++) jc[i] = (jc[i - 1] * i) % MOD;
  for (int i = 1; i <= n; i++) er[i] = (er[i - 1] * 2) % MOD;
}
long long inv(long long a, long long m) {
  return (a == 1 ? 1 : inv(m % a, m) * (m - m / a) % m);
}
int main() {
  cin >> n >> m;
  init();
  memset(vis, 0, sizeof(vis));
  int l = n + 1, r = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &pos);
    vis[pos] = 1;
    if (pos < l) l = pos;
    if (pos > r) r = pos;
  }
  int cnt = 0;
  long long ans = jc[n - m];
  for (int i = 1; i <= n; i++) {
    if (vis[i]) {
      ans = (ans * inv(jc[cnt], MOD)) % MOD;
      cnt = 0;
    } else
      cnt++;
  }
  ans = (ans * inv(jc[cnt], MOD)) % MOD;
  cnt = 0;
  for (int i = l + 1; i <= r; i++) {
    if (!vis[i])
      cnt++;
    else {
      if (cnt != 0) ans = (ans * er[cnt - 1]) % MOD;
      cnt = 0;
    }
  }
  cout << ans;
  return 0;
}
