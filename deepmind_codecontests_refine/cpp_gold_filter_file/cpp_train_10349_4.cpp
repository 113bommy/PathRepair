#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, const U &b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, const U &b) {
  if (a < b) a = b;
}
int d[1000100], deg[1000100], vst[1000100];
vector<int> adj[1000100];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while (m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[v].push_back(u);
    deg[u]++;
  }
  deque<int> q;
  int s, t;
  scanf("%d %d", &s, &t);
  q.push_back(t);
  for (int i = 1; i <= n; i++) d[i] = 0x3f3f3f3f;
  d[t] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    if (vst[u]) continue;
    vst[u] = 1;
    for (int i = adj[u].size(); i--;) {
      int v = adj[u][i];
      deg[v]--;
      if (deg[v]) {
        if (d[v] > d[u] + 1) {
          d[v] = d[u] + 1;
          q.push_back(v);
        }
      } else if (d[v] > d[u]) {
        d[v] = d[u];
        q.push_front(v);
      }
    }
  }
  if (d[s] < 0x3f3f3f3f)
    cout << d[s];
  else
    puts("-1");
}
