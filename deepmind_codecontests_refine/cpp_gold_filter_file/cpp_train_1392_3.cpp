#include <bits/stdc++.h>
using namespace std;
void my_dbg() { cout << endl; }
template <typename Arg, typename... Args>
void my_dbg(Arg A, Args... B) {
  cout << ' ' << A;
  my_dbg(B...);
}
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
const int inf = INT_MAX;
const int ninf = INT_MIN;
const int mod = 1e9 + 7;
const int maxN = 1e6 + 2;
vector<string> val(maxN);
set<string> total[maxN];
vector<pair<int, int>> q[maxN];
vi in(maxN), out(maxN), ver(maxN), sz(maxN), lev(maxN), ans(maxN);
vi adj[maxN];
int tim;
void dfs(int node, int par) {
  in[node] = tim;
  ver[tim] = node;
  sz[node] = 1;
  for (int it : adj[node]) {
    if (it != par) {
      tim++;
      lev[it] = lev[node] + 1;
      dfs(it, node);
      sz[node] += sz[it];
    }
  }
  out[node] = tim;
}
void dsu_on_tree(int node, int par, bool keep) {
  int mx = -1, big_child = -1;
  for (int it : adj[node]) {
    if (it != par && sz[it] > mx) {
      mx = sz[it];
      big_child = it;
    }
  }
  for (int it : adj[node]) {
    if (it != par && it != big_child) dsu_on_tree(it, node, 0);
  }
  if (big_child != -1) dsu_on_tree(big_child, node, 1);
  total[lev[node]].insert(val[node]);
  for (int it : adj[node]) {
    if (it != par && it != big_child) {
      for (int t = in[it]; t <= out[it]; t++) {
        int u = ver[t];
        total[lev[u]].insert(val[u]);
      }
    }
  }
  for (auto query : q[node]) {
    int depth = lev[node] + query.second, idx = query.first;
    if (depth < maxN)
      ans[idx] = (int)total[depth].size();
    else
      ans[idx] = 0;
  }
  if (!keep) {
    for (int t = in[node]; t <= out[node]; t++) {
      int u = ver[t];
      total[lev[u]].erase(val[u]);
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  vi roots;
  for (int i = 1; i < (int)n + 1; i++) {
    int p;
    cin >> val[i] >> p;
    if (p != 0) {
      adj[i].push_back(p);
      adj[p].push_back(i);
    } else {
      roots.push_back(i);
    }
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < (int)m; i++) {
    int v, k;
    scanf("%d", &v);
    scanf("%d", &k);
    q[v].push_back(make_pair(i, k));
  }
  for (int it : roots) {
    tim++;
    dfs(it, -1);
  }
  for (int it : roots) {
    dsu_on_tree(it, -1, 0);
  }
  for (int i = 0; i < (int)m; i++) {
    printf("%d ", (int)(ans[i]));
  }
  return 0;
}
