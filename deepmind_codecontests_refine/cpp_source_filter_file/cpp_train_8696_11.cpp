#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int to, nxt, dis;
} e[200005];
int n, a[100005], num, h[100005];
long long f[100005];
void add(int u, int v, int d) {
  e[++num].to = v;
  e[num].nxt = h[u];
  e[num].dis = d;
  h[u] = num;
}
int dfs(int u, int fa) {
  int v, i, d, res = 1;
  if (f[u] >= a[u]) return 0;
  for (i = h[u]; i; i = e[i].nxt) {
    v = e[i].to;
    if (v != fa) {
      d = e[i].dis;
      f[v] = max(f[u] + d, (long long)d);
      res += dfs(v, u);
    }
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  int i, pos, val;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 2; i <= n; i++) {
    cin >> pos >> val;
    add(i, pos, val);
    add(pos, i, val);
  }
  cout << n - dfs(1, 0);
  return 0;
}
