#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void ckmax(T& x, T y) {
  x = (y > x ? y : x);
}
template <typename T>
inline void ckmin(T& x, T y) {
  x = (y < x ? y : x);
}
const int MAXN = 2e5;
int n, m, in_deg[MAXN + 5], type[MAXN + 5];
struct EDGE {
  int nxt, to;
} edge[MAXN * 2 + 5];
int head[MAXN + 5], tot;
inline void add_edge(int u, int v) {
  edge[++tot].nxt = head[u];
  edge[tot].to = v;
  head[u] = tot;
}
void solve_case() {
  cin >> n >> m;
  tot = 0;
  for (int i = 1; i <= n; ++i) {
    head[i] = 0;
    type[i] = 0;
  }
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    add_edge(u, v);
    in_deg[v]++;
  }
  queue<int> q;
  for (int i = 1; i <= n; ++i)
    if (!in_deg[i]) {
      type[i] = 1;
      q.push(i);
    }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i; i = edge[i].nxt) {
      int v = edge[i].to;
      if (type[u] == 1 && type[v] != 3) type[v] = 2;
      if (type[u] == 2) type[v] = 3;
      in_deg[v]--;
      if (!in_deg[v]) {
        if (!type[v]) type[v] = 1;
        q.push(v);
      }
    }
  }
  vector<int> ans;
  for (int i = 1; i <= n; ++i)
    if (type[i] == 3) {
      ans.push_back(i);
    }
  cout << ((int)(ans).size()) << endl;
  for (int i = 0; i < ((int)(ans).size()); ++i) cout << ans[i] << " ";
  cout << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve_case();
  }
  return 0;
}
