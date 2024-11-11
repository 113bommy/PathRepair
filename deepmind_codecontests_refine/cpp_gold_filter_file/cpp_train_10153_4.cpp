#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int INF = 1E9;
const int MAXN = 100500;
int n;
int a[MAXN];
long long path[MAXN], arc[MAXN], maxArc[MAXN], keep[MAXN], ans[MAXN];
long long res;
vector<int> g[MAXN];
void dfs(int v, int p) {
  for (auto w : g[v])
    if (w != p) {
      dfs(w, v);
      ans[v] = max(ans[v], arc[v] + arc[w]);
      ans[v] = max(ans[v], keep[v] + path[w]);
      ans[v] = max(ans[v], path[v] + keep[w]);
      keep[v] = max(keep[v], maxArc[v] + path[w] + a[v]);
      keep[v] = max(keep[v], path[v] + arc[w]);
      keep[v] = max(keep[v], keep[w] + a[v]);
      ans[v] = max(ans[v], keep[v]);
      maxArc[v] = max(maxArc[v], arc[w]);
      ans[v] = max(ans[v], maxArc[v]);
      arc[v] = max(arc[v], path[v] + path[w]);
      arc[v] = max(arc[v], arc[w]);
      ans[v] = max(ans[v], arc[v]);
      path[v] = max(path[v], path[w] + a[v]);
      ans[v] = max(ans[v], path[v]);
    }
  path[v] = max(path[v], (long long)a[v]);
  arc[v] = max(arc[v], (long long)a[v]);
  keep[v] = max(keep[v], (long long)a[v]);
  ans[v] = max(ans[v], (long long)a[v]);
  res = max(res, ans[v]);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); i++) scanf("%d", &a[i]);
  for (int i = 0; i < (int)(n - 1); i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  res = 0;
  dfs(0, -1);
  cout << res << '\n';
  return 0;
}
