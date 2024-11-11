#include <bits/stdc++.h>
using namespace std;
const int MOD(1000000007);
const int INF((1 << 30) - 1);
const int MAXN(100005);
vector<pair<int, int> > a[MAXN];
vector<int> v;
int visited[MAXN], change[MAXN];
void dfs_init(int node) {
  visited[node] = 1;
  change[node] = 0;
  v.push_back(node);
  for (int i = 0; i < a[node].size(); i++) {
    int u = a[node][i].first;
    if (!visited[u]) dfs_init(u);
  }
}
void clear_node() {
  for (int i = 0; i < v.size(); i++) visited[v[i]] = 0;
}
void dfs_change(int node, int c) {
  visited[node] = 1;
  for (int i = 0; i < a[node].size(); i++) {
    int u = a[node][i].first, w = a[node][i].second;
    if (!visited[u]) {
      bool press = change[node] ^ change[u];
      if ((press == 0 && w != c) || (press == 1 && w == c)) change[u] ^= 1;
      dfs_change(u, c);
    }
  }
}
bool check(int c) {
  for (int k = 0; k < v.size(); k++) {
    int node = v[k];
    for (int i = 0; i < a[node].size(); i++) {
      int u = a[node][i].first, w = a[node][i].second;
      bool press = change[node] ^ change[u];
      if ((press == 0 && w != c) || (press == 1 && w == c)) return false;
    }
  }
  return true;
}
bool f(int node, int c1, int c2, vector<int> &d) {
  v.clear();
  dfs_init(node);
  clear_node();
  if (c1) change[node] = 1;
  dfs_change(node, c2);
  clear_node();
  if (!check(c2)) return false;
  d.clear();
  for (int i = 0; i < v.size(); i++) {
    if (change[v[i]]) d.push_back(v[i]);
  }
  return true;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    char c;
    scanf("%d%d %c", &u, &v, &c);
    if (c == 'B') {
      a[u].push_back(pair<int, int>(v, 0));
      a[v].push_back(pair<int, int>(u, 0));
    } else {
      a[u].push_back(pair<int, int>(v, 1));
      a[v].push_back(pair<int, int>(u, 1));
    }
  }
  bool p = false;
  vector<int> ans;
  for (int c = 0; c <= 1; c++) {
    bool fail = false;
    vector<int> b;
    for (int i = 1; i <= n; i++) visited[i] = 0;
    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        vector<int> d1, d2;
        bool p1 = f(i, 0, c, d1), p2 = f(i, 1, c, d2);
        for (int i = 0; i < v.size(); i++) visited[v[i]] = 1;
        if (p1 && p2) {
          if (d1.size() < d2.size()) {
            for (int j = 0; j < d1.size(); j++) b.push_back(d1[j]);
          } else {
            for (int j = 0; j < d2.size(); j++) b.push_back(d2[j]);
          }
        } else if (p1) {
          for (int j = 0; j < d1.size(); j++) b.push_back(d1[j]);
        } else if (p2) {
          for (int j = 0; j < d2.size(); j++) b.push_back(d2[j]);
        } else {
          fail = true;
          break;
        }
      }
    }
    if (!fail) {
      if ((!p) || (b.size() < ans.size())) ans = b, p = true;
    }
  }
  if (!p)
    printf("-1");
  else {
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
  }
}
