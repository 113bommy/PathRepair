#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
vector<int> g[N], ice[N];
int ans[N];
int tree[4 * N], lazy[4 * N];
bool haslazy[4 * N];
int n, m;
void prop(int pos, int start, int end) {
  if (!haslazy[pos]) return;
  tree[pos] = lazy[pos];
  haslazy[pos] = false;
  if (start != end) {
    haslazy[(2 * pos + 1)] = haslazy[(2 * pos + 2)] = true;
    lazy[(2 * pos + 1)] = lazy[(2 * pos + 2)] = lazy[pos];
  }
}
int update(int start, int end, int ustart, int uend, int val, int pos) {
  prop(pos, start, end);
  if (ustart > end or uend < start) return tree[pos];
  if (start >= ustart and end <= uend) {
    lazy[pos] = val;
    haslazy[pos] = true;
    prop(pos, start, end);
    return tree[pos];
  }
  int mid = (start + end) / 2;
  int l = update(start, mid, ustart, uend, val, (2 * pos + 1));
  int r = update(mid + 1, end, ustart, uend, val, (2 * pos + 2));
  return tree[pos] = max(l, r);
}
int find_max(int start, int end, int pos) {
  prop(pos, start, end);
  if (start == end) return start;
  int mid = (start + end) / 2;
  prop((2 * pos + 1), start, mid);
  prop((2 * pos + 2), mid + 1, end);
  if (tree[(2 * pos + 2)] > tree[(2 * pos + 1)])
    return find_max(mid + 1, end, (2 * pos + 2));
  return find_max(start, mid, (2 * pos + 1));
}
void set_1() { update(1, n, 1, n, 1, 0); }
void set_0(int c) { update(1, n, c, c, 0, 0); }
int next_color() {
  int ret = find_max(1, n, 0);
  update(1, n, ret, ret, 0, 0);
  return ret;
}
void dfs(int u, int last) {
  set_1();
  for (int i = 0; i < ice[u].size(); i++) {
    if (ans[ice[u][i]]) set_0(ans[ice[u][i]]);
  }
  for (int i = 0; i < ice[u].size(); i++) {
    if (!ans[ice[u][i]]) ans[ice[u][i]] = next_color();
  }
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v != last) dfs(v, u);
  }
}
int main() {
  scanf("%d %d", &n, &m);
  int anscnt = 1;
  for (int i = 1; i <= n; i++) {
    int s;
    scanf("%d", &s);
    anscnt = max(anscnt, s);
    while (s--) {
      int x;
      scanf("%d", &x);
      ice[i].push_back(x);
    }
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  printf("%d\n", anscnt);
  dfs(1, -1);
  for (int i = 1; i <= m; i++) {
    if (ans[i] == 0) ans[i] = 1;
    printf("%d%c", ans[i], " \n"[i == m]);
  }
  return 0;
}
