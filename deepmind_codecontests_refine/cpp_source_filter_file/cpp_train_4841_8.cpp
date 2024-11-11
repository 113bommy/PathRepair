#include <bits/stdc++.h>
using namespace std;
const int N = 400020;
const int M = 400020;
const int E = 400020;
int n1, n2, cnt, head[N], nxt[E], to[E];
int matching[M], dist[N], q[N];
bool used[N], vis[N];
void init(int _n1, int _n2) {
  n1 = _n1, n2 = _n2;
  cnt = 0;
  fill(head, head + n1, -1);
}
void add_edge(int u, int v) {
  to[cnt] = v;
  nxt[cnt] = head[u], head[u] = cnt++;
}
void bfs() {
  fill(dist, dist + n1, -1);
  int sz = 0;
  for (int u = 0; u < n1; u++) {
    if (!used[u]) q[sz++] = u, dist[u] = 0;
  }
  for (int i = 0; i < sz; i++) {
    int u1 = q[i];
    for (int j = head[u1]; j >= 0; j = nxt[j]) {
      int u2 = matching[to[j]];
      if (u2 >= 0 && dist[u2] < 0) dist[u2] = dist[u1] + 1, q[sz++] = u2;
    }
  }
}
bool dfs(int u1) {
  vis[u1] = 1;
  for (int i = head[u1]; i >= 0; i = nxt[i]) {
    int v = to[i];
    int u2 = matching[v];
    if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) {
      matching[v] = u1, used[u1] = 1;
      return 1;
    }
  }
  return 0;
}
int maxmatching() {
  fill(used, used + n1, 0);
  fill(matching, matching + n2, -1);
  for (int rlt = 0;;) {
    bfs();
    fill(vis, vis + n1, 0);
    int f = 0;
    for (int u = 0; u < n1; u++)
      if (!used[u] && dfs(u)) f++;
    if (!f) return rlt;
    rlt += f;
  }
}
int n, m;
bool ex[N];
vector<int> v[N];
int main() {
  scanf("%d %d", &n, &m);
  bool *Ex = ex + (N >> 1);
  init(n, 2 * m);
  for (int i = 1; i <= n; i++) {
    int k;
    scanf("%d", &k);
    v[i].resize(k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &v[i][j]);
      if (Ex[v[i][j]]) {
        if (v[i][j] > 0)
          v[i][j] += m;
        else
          v[i][j] -= m;
      } else
        Ex[v[i][j]] = 1;
      add_edge(i - 1, v[i][j] - 1);
    }
    sort(v[i].begin(), v[i].end());
  }
  int rlt = maxmatching();
  if (rlt < n) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (int i = 0; i < m; i++) {
    bool now = 0;
    if (~matching[i]) {
      int j = matching[i] + 1;
      if (binary_search(v[j].begin(), v[j].end(), i + 1)) now = 1;
    }
    if (~matching[i + m]) {
      int j = matching[i + m] + 1;
      if (binary_search(v[j].begin(), v[j].end(), i + m + 1)) now = 1;
    }
    putchar('0' + now);
  }
  return 0;
}
