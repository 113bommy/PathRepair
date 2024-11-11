#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m, pnt[N], vis[N];
long long vsum[N], esum[N], vcnt[N];
pair<pair<int, int>, pair<int, int> > edge[N];
vector<int> edge2[N];
int find(int x) {
  if (x != pnt[x]) pnt[x] = find(pnt[x]);
  return pnt[x];
}
void dfs(int u, int root) {
  vis[u] = root;
  vsum[u] = vcnt[u];
  for (int i = 0; i < (int)(edge2[u]).size(); ++i) {
    int v = edge2[u][i];
    if (vis[v]) continue;
    dfs(v, root);
    vsum[u] += vsum[v];
  }
}
void solve() {
  int u, v, w;
  m = n - 1;
  memset(esum, 0, sizeof(esum));
  for (int i = 0; i < n; ++i) {
    vcnt[i] = 1;
    pnt[i] = i;
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    edge[i] = make_pair(make_pair(w, i), make_pair(u - 1, v - 1));
  }
  sort(edge, edge + m);
  for (int i = 0; i < m; ++i) {
    int j = i + 1;
    for (; j < m; ++j)
      if (edge[i].first.first != edge[j].first.first) break;
    set<int> s;
    for (int k = i; k < j; ++k) {
      s.insert(find(edge[k].second.first));
      s.insert(find(edge[k].second.second));
    }
    vector<int> vt((s).begin(), (s).end());
    for (int k = 0; k < (int)(vt).size(); ++k) {
      vsum[vt[k]] = vis[vt[k]] = 0;
      edge2[vt[k]] = vector<int>();
    }
    for (int k = i; k < j; ++k) {
      int p = find(edge[k].second.first);
      int q = find(edge[k].second.second);
      edge2[p].push_back(q);
      edge2[q].push_back(p);
    }
    for (int k = 0; k < (int)(vt).size(); ++k) {
      if (vis[vt[k]]) continue;
      dfs(vt[k], vt[k] + 1);
    }
    for (int k = i; k < j; ++k) {
      int p = find(edge[k].second.first);
      int q = find(edge[k].second.second);
      long long c = min(vsum[p], vsum[q]);
      esum[edge[k].first.second] = 2 * c * (vsum[vis[p] - 1] - c);
    }
    for (int k = i; k < j; ++k) {
      int p = find(edge[k].second.first);
      int q = find(edge[k].second.second);
      pnt[p] = q;
      vcnt[q] += vcnt[p];
    }
    i = j - 1;
  }
  long long ans = 0;
  int ct = 0;
  for (int i = 0; i < m; ++i) {
    if (ans < esum[i]) {
      ans = esum[i];
      ct = 1;
    } else if (ans == esum[i]) {
      ct++;
    }
  }
  printf(
      "%lld"
      " %d\n",
      ans, ct);
  bool first = true;
  for (int i = 0; i < m; ++i) {
    if (esum[i] != ans) continue;
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
