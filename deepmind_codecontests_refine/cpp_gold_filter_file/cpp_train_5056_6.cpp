#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 100 * 1000 + 5;
const int off = 131072 * 2;
long long A[maxn];
int B[maxn];
vector<pair<int, int> > adj[maxn];
int ans[maxn];
int cnt = -1;
long long tree[2 * off];
vector<int> path;
void update(int w) {
  if (w < 1) return;
  tree[w] = tree[w * 2] + tree[w * 2 + 1];
  update(w >> 1);
}
int query(int w, long long s) {
  if (w >= off) return w;
  if (tree[w * 2 + 1] <= s) {
    return query(w * 2, s - tree[w * 2 + 1]);
  }
  return query(w * 2 + 1, s);
}
long long query2(int p, int k, int beg, int end, int w) {
  if (p == beg && k == end) return tree[w];
  int m = (beg + end) >> 1;
  if (k <= m) return query2(p, k, beg, m, w << 1);
  if (p >= m) return query2(p, k, m, end, (w << 1) + 1);
  return query2(p, m, beg, m, w << 1) + query2(m, k, m, end, (w << 1) + 1);
}
int dfs2(int u) {
  int s = B[u];
  for (int i = 0; i < (adj[u].size()); ++i) {
    pair<int, int> p = adj[u][i];
    s += dfs2(p.first);
  }
  ans[u] = s;
  return s;
}
void dfs(int u) {
  cnt++;
  path.push_back(u);
  for (int i = 0; i < (adj[u].size()); ++i) {
    pair<int, int> p = adj[u][i];
    int v = p.first, w = p.second;
    tree[off + cnt] = w;
    update((off + cnt) >> 1);
    int end = query(1, A[v]) - off;
    if (query2(end, off, 0, off, 1) > A[v]) end = end + 1;
    ans[v] = cnt + 1 - end;
    B[u]++;
    if (end > 0) B[path[end - 1]]--;
    dfs(v);
  }
  tree[off + cnt] = 0;
  update((off + cnt) >> 1);
  cnt--;
  path.pop_back();
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < (n); ++i) cin >> A[i];
  for (int i = 1; i < n; ++i) {
    int p, w;
    cin >> p >> w;
    adj[--p].push_back(make_pair(i, w));
  }
  dfs(0);
  dfs2(0);
  for (int i = 0; i < (n); ++i) cout << ans[i] << " ";
}
int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
