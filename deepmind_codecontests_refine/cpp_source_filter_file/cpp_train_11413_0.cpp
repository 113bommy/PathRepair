#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m, pnt[N], cnt[N], vis[N];
long long ans[N], sum[N];
pair<pair<int, int>, pair<int, int> > edge[N];
map<int, vector<int> > edge2;
int father(int x) {
  if (x != pnt[x]) pnt[x] = father(pnt[x]);
  return pnt[x];
}
void dfs(int u, int root) {
  vis[u] = root;
  vector<int> &t = edge2[u];
  sum[u] = cnt[u];
  for (int i = 0; i < (int)(t.size()); ++i) {
    if (vis[t[i]]) continue;
    dfs(t[i], root);
    sum[u] += sum[t[i]];
  }
}
void solve() {
  int u, v, w;
  m = n - 1;
  memset(ans, 0, sizeof(ans));
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; ++i) {
    pnt[i] = i;
    cnt[i] = 1;
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    u--;
    v--;
    edge[i] = make_pair(make_pair(w, i), make_pair(u, v));
  }
  sort(edge, edge + m);
  for (int i = 0; i < m; ++i) {
    int j = i;
    for (; j < m; ++j)
      if (edge[i].first.first != edge[j].first.first) break;
    edge2.clear();
    for (int k = i; k < j; ++k) {
      int p = father(edge[k].second.first);
      int q = father(edge[k].second.second);
      vis[p] = vis[q] = sum[p] = sum[q] = 0;
      if (edge2.find(p) == edge2.end()) {
        edge2[p] = vector<int>();
      }
      edge2[p].push_back(q);
      if (edge2.find(q) == edge2.end()) {
        edge2[q] = vector<int>();
      }
      edge2[q].push_back(p);
    }
    map<int, vector<int> >::iterator it = edge2.begin();
    for (; it != edge2.end(); ++it) {
      if (vis[it->first]) continue;
      dfs(it->first, it->first + 1);
    }
    for (int k = i; k < j; ++k) {
      int p = father(edge[k].second.first);
      int q = father(edge[k].second.second);
      long long c = min(sum[p], sum[q]);
      ans[edge[k].first.second] = c * (sum[vis[p] - 1] - c) * 2;
    }
    for (int k = i; k < j; ++k) {
      int p = father(edge[i].second.first);
      int q = father(edge[i].second.second);
      if (p == q) continue;
      pnt[p] = q;
      cnt[q] += cnt[p];
    }
    i = j - 1;
  }
  long long res = 0;
  int ct = 0;
  for (int i = 0; i < m; ++i) {
    if (res < ans[i]) {
      res = ans[i];
      ct = 1;
    } else if (res == ans[i]) {
      ct++;
    }
  }
  printf(
      "%I64d"
      " %d\n",
      res, ct);
  bool first = true;
  for (int i = 0; i < m; ++i) {
    if (ans[i] != res) continue;
    if (!first)
      printf(" ");
    else
      first = false;
    printf("%d", i + 1);
  }
  puts("");
}
int main() {
  while (scanf("%d", &n) != EOF) {
    solve();
  }
  return 0;
}
