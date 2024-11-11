#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
struct edge {
  int a, b, cap, flow;
};
int n;
vector<edge> e;
vector<vector<int> > g, gr;
vector<int> level, ptr, comp;
vector<char> used;
vector<vector<int> > ans;
void dfs2(int v) {
  used[v] = 1;
  comp.push_back(v);
  for (int i = 0; i < gr[v].size(); i++) {
    int to = gr[v][i];
    if (!used[to]) dfs2(to);
  }
}
void add_edge(int v, int to, int cap) {
  edge a = {v, to, cap, 0};
  edge b = {to, v, 0, 0};
  g[v].push_back(e.size());
  e.push_back(a);
  g[to].push_back(e.size());
  e.push_back(b);
}
bool bfs() {
  queue<int> q;
  level.assign(n + 15, -1);
  q.push(n + 10);
  level[n + 10] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (v == n + 11) {
      return true;
    }
    for (int i = 0; i < g[v].size(); i++) {
      int ind = g[v][i];
      int to = e[ind].b;
      if (e[ind].cap > e[ind].flow && level[to] == -1) {
        level[to] = level[v] + 1;
        q.push(to);
      }
    }
  }
  return false;
}
int dfs(int v, int flow) {
  if (v == n + 11) return flow;
  if (flow == 0) return 0;
  for (int i = ptr[v]; i < g[v].size(); i++, ptr[v]++) {
    int ind = g[v][i];
    int to = e[ind].b;
    if (level[to] != level[v] + 1) {
      continue;
    }
    int add = dfs(to, min(flow, e[ind].cap - e[ind].flow));
    if (add) {
      e[ind].flow += add;
      e[ind ^ 1].flow -= add;
      return add;
    }
  }
  return 0;
}
int find() {
  int flow = 0;
  while (bfs()) {
    ptr.assign(n + 15, 0);
    while (int add = dfs(n + 10, 1e9)) flow += add;
  }
  return flow;
}
int main() {
  cin >> n;
  g.resize(n + 15);
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<char> pr(1e5, true);
  pr[0] = pr[1] = 0;
  for (int i = 2; i < pr.size(); i++) {
    if (pr[i]) {
      for (int j = i + i; j < pr.size(); j += i) pr[j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int numb = arr[i] + arr[j];
      if (pr[numb]) {
        if (arr[i] % 2 == 1) {
          add_edge(j, i, 1);
        } else {
          add_edge(i, j, 1);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 1) {
      add_edge(i, n + 11, 1e9);
    } else {
      add_edge(n + 10, i, 2);
    }
  }
  int res = find();
  if (res != n) {
    cout << "Impossible";
    return 0;
  }
  gr.resize(n);
  for (int i = 0; i < e.size(); i++) {
    int v = e[i].a, to = e[i].b;
    int flow = e[i].flow;
    if (v <= n && to <= n && flow) {
      gr[v].push_back(to);
      gr[to].push_back(v);
    }
  }
  used.assign(g.size(), false);
  for (int i = 0; i < gr.size(); i++) {
    if (!used[i]) {
      comp.clear();
      dfs2(i);
      ans.push_back(comp);
    }
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].size() << " ";
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] + 1 << " ";
    }
    cout << "\n";
  }
  return 0;
}
