#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long linf = 1e18;
const int inf = 1e9 + 7;
const int maxn = 1e5 + 100;
const long double PI = 3.14159265358;
const int ii[] = {-1, 1, 0, 0}, jj[] = {0, 0, -1, 1};
int n, m, tim;
int a[maxn * 2];
vector<int> g[maxn * 2];
int h[maxn * 2], s[maxn * 2], f[maxn * 2];
struct node {
  int ans[2];
} t[maxn * 2 * 10];
inline void dfs(int v = 1, int p = -1, int d = 1) {
  h[v] = d;
  s[v] = ++tim;
  for (auto to : g[v])
    if (to != p) dfs(to, v, d + 1);
  f[v] = ++tim;
}
inline void update(int x, int val, int v = 1, int tl = 1, int tr = tim) {
  if (tl > f[x] || tr < s[x]) return;
  if (s[x] <= tl && tr <= f[x]) {
    t[v].ans[h[x] % 2] += val;
    return;
  }
  int tm = tl + tr >> 1;
  update(x, val, v + v, tl, tm);
  update(x, val, v + v + 1, tm + 1, tr);
}
inline int another(int x) { return ((x == 0) ? 1 : 0); }
inline int query(int x, int v = 1, int tl = 1, int tr = tim) {
  int ans = t[v].ans[h[x] % 2] - t[v].ans[another(h[x] % 2)];
  if (tl == tr) return ans;
  int tm = tl + tr >> 1;
  if (s[x] <= tm) return ans + query(x, v + v, tl, tm);
  return ans + query(x, v + v + 1, tm + 1, tr);
}
int main() {
  scanf("%d", &n), scanf("%d", &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1, u, v; i < n; i++)
    scanf("%d", &u), scanf("%d", &v), g[u].push_back(v), g[v].push_back(u);
  dfs();
  while (m--) {
    int type, x, val;
    scanf("%d", &type), scanf("%d", &x);
    if (type == 1) {
      scanf("%d", &val);
      update(x, val);
    } else
      cout << query(x) + a[x] << endl;
  }
}
