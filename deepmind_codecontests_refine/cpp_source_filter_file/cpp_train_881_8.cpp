#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int maxn = 110000;
int n, m, x, y, z;
int fa[maxn], rk[maxn];
bool vis[maxn];
int find(int x) {
  if (fa[x] == x) return fa[x];
  int tx = fa[x];
  fa[x] = find(fa[x]);
  rk[x] = (rk[x] + rk[tx] + 1) & 1;
  return fa[x];
}
long long powmod(int x, int k) {
  long long tx = (long long)x;
  int n = k;
  long long ret = (long long)1;
  while (n) {
    if (n & 1) ret = (ret * tx) % mod;
    tx = (tx * tx) % mod;
    n >>= 1;
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
    rk[i] = 1;
  }
  bool flag = false;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &x, &y, &z);
    if (flag) continue;
    if (z) {
      int fx = find(x);
      int fy = find(y);
      if (fx != fy) {
        fa[fx] = fy;
        rk[fx] = (rk[x] + rk[y]) & 1;
      } else if (fx == fy) {
        if (rk[x] != rk[y]) {
          flag = true;
        }
      }
    } else {
      int fx = find(x);
      int fy = find(y);
      if (fx != fy) {
        fa[fx] = fy;
        rk[fx] = (rk[x] + rk[y]) & 1;
      } else if (fx == fy) {
        if (rk[x] == rk[y]) {
          flag = true;
        }
      }
    }
  }
  if (flag) {
    puts("0");
    return 0;
  }
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= n; i++) vis[find(i)] = true;
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (vis[i]) cnt++;
  long long ans = powmod(2, cnt - 1);
  cout << ans << endl;
  return 0;
}
