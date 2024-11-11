#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, k, cnt, head[N], p[N], d[N], cnt2, head2[N];
bool v[N];
struct edge {
  int to, next;
} e[N], e2[N];
inline void add_edge(int u, int v) {
  cnt++;
  e[cnt].to = v;
  e[cnt].next = head[u];
  head[u] = cnt;
}
inline void add_edge2(int u, int v) {
  cnt2++;
  e2[cnt2].to = v;
  e2[cnt2].next = head2[u];
  head2[u] = cnt2;
}
queue<int> Q;
void bfs(int tt) {
  Q.push(tt);
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    for (int i = head2[cur]; i; i = e2[i].next) {
      int q = e2[i].to;
      if (!v[q]) {
        Q.push(q);
        d[q] = d[cur] + 1;
        v[q] = true;
      }
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    add_edge(u, v);
    add_edge2(v, u);
  }
  cin >> k;
  for (int i = 1; i <= k; i++) cin >> p[i];
  d[p[k]] = 0;
  v[p[k]] = true;
  bfs(p[k]);
  int minres = 0;
  int maxres = 0;
  for (int i = 1; i < k; i++) {
    int cur = p[i];
    int nxt = p[i + 1];
    if (d[nxt] > d[cur] - 1) {
      minres++;
      maxres++;
    } else {
      bool fg = false;
      for (int ix = head[cur]; ix; ix = e[ix].next) {
        int q = e[ix].to;
        if (d[q] == d[cur] - 1 && q != nxt) fg = true;
      }
      if (fg == true) maxres++;
    }
  }
  cout << minres << " " << maxres << endl;
  return 0;
}
