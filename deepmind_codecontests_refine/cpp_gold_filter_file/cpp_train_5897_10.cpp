#include <bits/stdc++.h>
using namespace std;
const int maxn = 200009;
const int MOD = 1e9 + 7;
set<int> V[maxn];
int dep[maxn], st, ed, dist;
void dfs(int u, int fa, int d = 0) {
  dep[u] = d;
  if (dep[u] > dist) {
    dist = dep[u];
    ed = u;
  }
  for (int v : V[u])
    if (v != fa) {
      dfs(v, u, d + 1);
    }
}
void dfs2(int u, int fa, vector<int> &dis) {
  for (int v : V[u])
    if (v != fa) {
      dis[v] = dis[u] + 1;
      dfs2(v, u, dis);
    }
}
int main() {
  ios_base::sync_with_stdio(false), cout.tie(0), cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    V[u].insert(v);
    V[v].insert(u);
  }
  dist = -1;
  dfs(1, 1);
  st = ed;
  dist = -1;
  dfs(ed, ed);
  vector<int> DISTST(n + 1), DISTED(n + 1);
  dfs2(st, st, DISTST);
  dfs2(ed, ed, DISTED);
  vector<int> que;
  for (int i = 1; i <= n; ++i)
    if (i != st && i != ed && ((int)(V[i]).size()) == 1) {
      que.push_back(i);
    }
  vector<pair<pair<int, int>, int>> ans;
  int64_t tot = 0;
  for (int i = 0; i < ((int)(que).size()); ++i) {
    if (DISTST[que[i]] >= DISTED[que[i]]) {
      tot += DISTST[que[i]];
      ans.push_back(make_pair(make_pair(st, que[i]), que[i]));
    } else {
      tot += DISTED[que[i]];
      ans.push_back(make_pair(make_pair(ed, que[i]), que[i]));
    }
    for (int v : V[que[i]]) {
      V[v].erase(que[i]);
      if (((int)(V[v]).size()) == 1) que.push_back(v);
    }
  }
  for (int i = DISTST[ed]; i >= 1; --i) {
    tot += i;
    int a = *V[ed].begin();
    V[a].erase(ed);
    ans.push_back(make_pair(make_pair(ed, st), ed));
    ed = a;
  }
  cout << tot << "\n";
  for (auto i : ans) {
    cout << i.first.first << " " << i.first.second << " " << i.second << '\n';
  }
  return 0;
}
