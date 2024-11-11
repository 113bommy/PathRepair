#include <bits/stdc++.h>
using namespace std;
int n, m;
int inf = 1e9 + 10;
const int maxn = 5e5 + 10;
vector<int> adj[maxn], in[maxn], out[maxn];
vector<int> top;
vector<pair<int, int> > E;
int a[maxn], b[maxn], c[maxn], t[maxn];
int cmp[maxn];
bool mark[maxn];
inline bool Cmp(int a, int b) { return c[a] < c[b]; }
inline void add_edge(int a, int b) {
  out[a].push_back(b);
  in[b].push_back(a);
  return;
}
void dfs(int v) {
  mark[v] = true;
  for (int u : out[v]) {
    if (!mark[u]) dfs(u);
  }
  top.push_back(v);
}
int cm = 0;
void dfs2(int v) {
  mark[v] = true;
  cmp[v] = cm;
  for (int u : in[v]) {
    if (!mark[u]) {
      dfs2(u);
    }
  }
}
bool check(int mid) {
  top.clear();
  cm = 0;
  for (int i = 0; i < 7 * n; i++) {
    in[i].clear();
    out[i].clear();
  }
  memset(cmp, 0, sizeof cmp);
  for (auto e : E) {
    add_edge(e.first * 2, e.second * 2 + 1);
    add_edge(e.second * 2, e.first * 2 + 1);
  }
  for (int i = 0; i < m; i++) {
    if (t[i] > mid) add_edge(i * 2 + 1, i * 2);
  }
  int end = m;
  for (int i = 0; i < n; i++) {
    if (adj[i].size()) {
      int pr = adj[i][0];
      for (int j = 1; j < adj[i].size(); j++) {
        int e = adj[i][j];
        add_edge(pr * 2 + 1, end * 2 + 1);
        add_edge(end * 2, pr * 2);
        add_edge(e * 2 + 1, end * 2 + 1);
        add_edge(end * 2, e * 2);
        add_edge(pr * 2 + 1, e * 2);
        add_edge(e * 2 + 1, pr * 2);
        pr = end;
        end++;
      }
    }
  }
  memset(mark, 0, sizeof mark);
  for (int i = 0; i < end * 2; i++) {
    if (!mark[i]) {
      dfs(i);
    }
  }
  memset(mark, 0, sizeof mark);
  reverse(top.begin(), top.end());
  for (int u : top) {
    if (!mark[u]) {
      cm++;
      dfs2(u);
    }
  }
  for (int i = 0; i < end; i++) {
    if (cmp[i * 2] == cmp[i * 2 + 1]) {
      return false;
    }
  }
  return true;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i] >> c[i] >> t[i];
    a[i]--;
    b[i]--;
    adj[a[i]].push_back(i);
    adj[b[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    sort(adj[i].begin(), adj[i].end(), Cmp);
    int cnt = 0;
    for (int j = 0; j < adj[i].size(); j++) {
      int k = j;
      while (k < adj[i].size() && c[adj[i][k]] == c[adj[i][j]]) {
        k++;
      }
      if (k - j > 2) {
        cout << "No";
        return 0;
      }
      if (k - j == 2) {
        E.push_back({adj[i][j], adj[i][j + 1]});
        cnt++;
      }
      j = k - 1;
    }
    if (cnt > 1) {
      cout << "No";
      return 0;
    }
  }
  int l = 0, r = inf;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  if (r == inf) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  check(r);
  vector<int> ans;
  for (int i = 0; i < m; i++) {
    if (cmp[i * 2] < cmp[i * 2 + 1]) {
      ans.push_back(i);
    }
  }
  cout << r << " " << (int)ans.size() << endl;
  for (int u : ans) cout << u + 1 << " ";
  cout << endl;
}
