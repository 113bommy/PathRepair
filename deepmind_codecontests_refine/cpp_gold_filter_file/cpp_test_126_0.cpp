#include <bits/stdc++.h>
using namespace std;
const int N = 1005, M = 4005, inf = 1e9;
int nn, s, t, dep[N], hd[N], cur[N], nxt[M], to[M], w[M], tot;
void add(int u, int v, int ww) {
  nxt[++tot] = hd[u], to[tot] = v, w[tot] = ww, hd[u] = tot;
  nxt[++tot] = hd[v], to[tot] = u, w[tot] = 0, hd[v] = tot;
}
bool bfs() {
  memset(dep, 0, sizeof(dep));
  dep[s] = 1;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = hd[u]; i; i = nxt[i]) {
      if (w[i] && !dep[to[i]]) {
        dep[to[i]] = dep[u] + 1;
        q.push(to[i]);
      }
    }
  }
  return dep[t] > 0;
}
int dfs(int u, int f) {
  if (u == t) return f;
  int ret = 0;
  for (int &i = cur[u]; i; i = nxt[i])
    if (w[i] && dep[to[i]] == dep[u] + 1) {
      int fl = dfs(to[i], min(f, w[i]));
      f -= fl, ret += fl;
      w[i] -= fl, w[i ^ 1] += fl;
      if (!f) break;
    }
  return ret;
}
int n, m, a[N], ans[N], x[N], y[N], id[N], rd[N], tp[N];
vector<int> g[N], vec;
void solve(int lb, int rb, int l, int r) {
  if (l > r) return;
  if (lb == rb) {
    for (int i = l; i <= r; i++) ans[id[i]] = vec[lb];
    return;
  }
  int mid = (lb + rb) >> 1, lp = l, rp = r;
  nn = r - l + 3, tot = 1;
  memset(hd, 0, sizeof(hd));
  s = nn - 1, t = nn;
  for (int i = l; i <= r; i++) {
    if (a[id[i]] <= vec[mid])
      add(s, i - l + 1, 1);
    else
      add(i - l + 1, t, 1);
    for (auto v : g[id[i]])
      if (l <= rd[v] && rd[v] <= r) add(i - l + 1, rd[v] - l + 1, inf);
  }
  while (bfs()) {
    memcpy(cur, hd, sizeof(cur));
    dfs(s, inf);
  }
  for (int i = l; i <= r; i++)
    if (dep[i - l + 1])
      tp[lp++] = id[i];
    else
      tp[rp--] = id[i];
  for (int i = l; i <= r; i++) rd[id[i] = tp[i]] = i;
  solve(lb, mid, l, rp);
  solve(mid + 1, rb, lp, r);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    vec.push_back(a[i]);
  }
  sort(vec.begin(), vec.end());
  vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x[i], &y[i]);
    g[y[i]].push_back(x[i]);
  }
  for (int i = 1; i <= n; i++) rd[id[i] = i] = i;
  solve(0, (int)vec.size() - 1, 1, n);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  puts("");
  return 0;
}
