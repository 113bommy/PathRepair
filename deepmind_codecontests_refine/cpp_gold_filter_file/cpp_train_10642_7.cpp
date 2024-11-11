#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<int> g[N];
vector<int> a[N];
int st[N], en[N];
int tot = 0;
int p[N][20];
int h[N];
void dfs(int u, int P) {
  st[u] = ++tot;
  for (int i = 0; i < 17; ++i) p[u][i + 1] = p[p[u][i]][i];
  for (int v : g[u])
    if (v != P) {
      p[v][0] = u;
      h[v] = h[u] + 1;
      dfs(v, u);
    }
  en[u] = ++tot;
}
bool is_anc(int u, int v) {
  if (u == 0) return 1;
  if (st[u] > st[v]) return 0;
  if (en[v] > en[u]) return 0;
  return 1;
}
int lca(int u, int v) {
  if (is_anc(u, v)) return u;
  for (int i = 17; i >= 0; --i)
    if (!is_anc(p[u][i], v)) u = p[u][i];
  return p[u][0];
}
int dis(int u, int v) { return h[u] + h[v] - 2 * h[lca(u, v)]; }
struct virus {
  int source;
  int speed;
  virus(int _v = 0, int _s = 0) : source(_v), speed(_s) {}
  int reach(int v) {
    int distance = h[source] + h[v] - 2 * h[lca(source, v)];
    return (distance + speed - 1) / speed;
  }
};
vector<virus> vir;
int infected[N];
bool cmp(int i, int j, int v) {
  if (i < 0) return 0;
  if (j < 0) return 1;
  int t1 = vir[i].reach(v);
  int t2 = vir[j].reach(v);
  if (t1 != t2)
    return t1 < t2;
  else
    return i < j;
}
void cal0(int u, int p) {
  for (int v : a[u])
    if (v != p) {
      cal0(v, u);
      if (cmp(infected[v], infected[u], u)) infected[u] = infected[v];
    }
}
void cal1(int u, int p) {
  for (int v : a[u])
    if (v != p) {
      if (cmp(infected[u], infected[v], v)) infected[v] = infected[u];
      cal1(v, u);
    }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int x;
    cin >> x;
    int y;
    cin >> y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  dfs(1, 0);
  int q;
  cin >> q;
  memset(infected, -1, sizeof infected);
  for (int i = 0; i < q; ++i) {
    vector<int> vec;
    vector<int> imp;
    int k;
    cin >> k;
    int m;
    cin >> m;
    for (int j = 0; j < k; ++j) {
      int v;
      cin >> v;
      int s;
      cin >> s;
      vec.emplace_back(v);
      vir.emplace_back(v, s);
      infected[v] = j;
    }
    for (int j = 0; j < m; ++j) {
      int x;
      cin >> x;
      vec.emplace_back(x);
      imp.emplace_back(x);
    }
    sort(vec.begin(), vec.end(), [&](int x, int y) { return st[x] < st[y]; });
    for (int i = (int)vec.size() - 1; i > 0; --i)
      vec.emplace_back(lca(vec[i], vec[i - 1]));
    sort(vec.begin(), vec.end(), [&](int x, int y) { return st[x] < st[y]; });
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    stack<int> wtf;
    for (int x : vec) {
      while (wtf.size() && !is_anc(wtf.top(), x)) wtf.pop();
      if (wtf.size()) a[wtf.top()].emplace_back(x);
      wtf.push(x);
    }
    cal0(vec[0], 0);
    cal1(vec[0], 0);
    for (int x : imp) cout << infected[x] + 1 << " ";
    cout << "\n";
    for (int x : vec) {
      a[x].clear();
      infected[x] = -1;
    }
    vir.clear();
  }
}
