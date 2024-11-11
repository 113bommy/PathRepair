#include <bits/stdc++.h>
using namespace std;
class LCA {
 public:
  LCA(int _n) : n(_n) {
    logn = log2(_n) + 1;
    x = vector<vector<int>>(_n);
    p = vector<vector<int>>(_n, vector<int>(logn, -1));
    d = vector<int>(_n);
  }
  void AddEdge(int a, int b) {
    x[a].push_back(b);
    x[b].push_back(a);
  }
  void Dfs(int a, int fa, int depth) {
    d[a] = depth;
    p[a][0] = fa;
    for (int i : x[a]) {
      if (i == fa) continue;
      Dfs(i, a, depth + 1);
    }
  }
  void Build(int r) {
    root = r;
    Dfs(r, -1, 0);
    for (int j = 1; j < logn; ++j) {
      for (int i = 0; i < n; ++i) {
        if (p[i][j - 1] != -1) p[i][j] = p[p[i][j - 1]][j - 1];
      }
    }
  }
  int Lca(int a, int b) {
    if (d[a] < d[b]) swap(a, b);
    int log = 1;
    while ((1 << log) <= d[a]) ++log;
    --log;
    for (int i = log; i >= 0; --i) {
      if (d[a] - (1 << i) >= d[b]) a = p[a][i];
    }
    if (a == b) return a;
    for (int i = log; i >= 0; --i) {
      if (p[a][i] != -1 && p[a][i] != p[b][i]) {
        a = p[a][i];
        b = p[b][i];
      }
    }
    return p[a][0];
  }
  int Dist(int a, int b) {
    int c = Lca(a, b);
    return d[a] + d[b] - 2 * d[c];
  }
  int Move(int a, int b, int dist) {
    int c = Lca(a, b);
    if (d[a] - d[c] >= dist) return Parent(a, dist);
    dist -= d[a] - d[c];
    return Parent(b, d[b] - d[c] - dist);
  }
  int Parent(int a, int l) {
    for (int i = logn - 1; i >= 0; --i) {
      if (l >= (1 << i)) {
        a = p[a][i];
        l -= (1 << i);
      }
      if (a == -1) return -1;
    }
    return a;
  }
  int n, logn;
  int root;
  vector<vector<int>> x;
  vector<vector<int>> p;
  vector<int> d;
};
const int MAXN = 200010;
int nn;
int o[MAXN];
struct Node {
  int v, t, d, i;
  bool operator<(const Node& b) const {
    if (t != b.t) return t < b.t;
    if (i != b.i) return i < b.i;
    if (d != b.d) return d < b.d;
    return v < b.v;
  }
};
void Dfs(int a, LCA& lca) {
  o[a] = ++nn;
  for (int b : lca.x[a]) {
    if (o[b] > 0) continue;
    Dfs(b, lca);
  }
}
bool z[MAXN];
int h[MAXN];
int v[MAXN], s[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  LCA lca(n);
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    lca.AddEdge(a - 1, b - 1);
  }
  lca.Build(0);
  Dfs(0, lca);
  int times;
  cin >> times;
  while (times--) {
    int k, m;
    cin >> k >> m;
    vector<int> allv;
    for (int i = 1; i <= k; ++i) {
      cin >> v[i] >> s[i];
      --v[i];
      if (!z[v[i]]) {
        allv.push_back(v[i]);
        z[v[i]] = true;
      }
    }
    vector<int> ansv(m);
    for (int i = 0; i < m; ++i) {
      cin >> ansv[i];
      --ansv[i];
      if (!z[ansv[i]]) {
        allv.push_back(ansv[i]);
        z[ansv[i]] = true;
      }
    }
    sort(allv.begin(), allv.end(),
         [&](const int a, const int b) { return o[a] < o[b]; });
    int allvs = allv.size();
    for (int i = 0; i + 1 < allvs; ++i) {
      int t = lca.Lca(allv[i], allv[i + 1]);
      if (!z[t]) {
        z[t] = true;
        allv.push_back(t);
      }
    }
    sort(allv.begin(), allv.end(),
         [&](const int a, const int b) { return o[a] < o[b]; });
    allvs = allv.size();
    for (int i = 0; i < allv.size(); ++i) h[allv[i]] = i;
    vector<vector<pair<int, int>>> y(allvs);
    stack<int> st;
    for (int i : allv) {
      while (!st.empty() && lca.Lca(st.top(), i) != st.top()) {
        st.pop();
      }
      if (st.empty()) {
        st.push(i);
        continue;
      }
      int a = h[st.top()], b = h[i];
      int dist = lca.Dist(st.top(), i);
      y[a].push_back({b, dist});
      y[b].push_back({a, dist});
      st.push(i);
    }
    vector<Node> ans(allvs, {-1, n + 1, -1, -1});
    vector<bool> zz(allvs);
    set<Node> ss;
    for (int i = 1; i <= k; ++i) {
      int vi = h[v[i]];
      ans[vi] = {vi, 0, 0, i};
      ss.insert(ans[vi]);
    }
    while (!ss.empty()) {
      Node a = *ss.begin();
      ss.erase(ss.begin());
      if (zz[a.v]) continue;
      zz[a.v] = true;
      for (auto [b, dist] : y[a.v]) {
        Node c = a;
        c.v = b;
        if (dist <= c.d) {
          c.d -= dist;
        } else {
          dist -= c.d;
          c.d = 0;
          c.t += dist / s[c.i];
          dist %= s[c.i];
          if (dist != 0) {
            ++c.t;
            c.d = s[c.i] - dist;
          }
        }
        if (c < ans[b]) {
          ans[b] = c;
          ss.insert(c);
        }
      }
    }
    for (int i : ansv) {
      cout << ans[h[i]].i << " ";
    }
    cout << '\n';
    for (int i : allv) z[i] = false;
  }
  return 0;
}
