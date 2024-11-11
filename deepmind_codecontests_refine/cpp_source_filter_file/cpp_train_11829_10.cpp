#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9, N = 3e5 + 5;
vector<vector<int>> graph;
bool used[N];
vector<map<int, bool>> if_;
int len[N];
struct edge {
  int go, to;
};
vector<edge> ans;
void dfs(int v, int prev) {
  used[v] = true;
  for (int u : graph[v]) {
    if (!used[u]) {
      len[u] = len[v] + 1;
      dfs(u, v);
    }
  }
  int cnt = 0;
  for (int u : graph[v]) {
    if (len[v] < len[u] && !if_[v][u] && !if_[u][v] && u != prev) {
      if_[v][u] = true;
      if_[u][v] = true;
      cnt++;
      edge p;
      p.go = v;
      p.to = u;
      ans.push_back(p);
    }
  }
  if (cnt % 2 == 1 && v != prev) {
    edge p;
    p.go = v;
    p.to = prev;
    if_[v][prev] = true;
    if_[prev][v] = true;
    ans.push_back(p);
  } else if (cnt % 2 == 1) {
    ans.pop_back();
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    vector<int> a;
    graph.push_back(a);
    map<int, bool> mp;
    if_.push_back(mp);
  }
  for (int i = 0; i < m; i++) {
    int go, to;
    cin >> go >> to;
    graph[--go].push_back(--to);
    if_[go][to] = false;
    graph[to].push_back(go);
    if_[to][go] = false;
  }
  len[0] = 0;
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs(i, i);
    }
  }
  int len = ans.size();
  len -= len % 2;
  cout << m / 2 << endl;
  for (int i = 0; i < len; i += 2) {
    edge e = ans[i], e_ = ans[i + 1];
    cout << e.to + 1 << " " << e.go + 1 << " " << e_.to + 1 << endl;
  }
}
