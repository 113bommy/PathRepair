#include <bits/stdc++.h>
using namespace std;
int read();
int n, m;
vector<int> e[200005];
int deg[200005];
void add(int f, int t) { e[f].push_back(t), ++deg[t]; }
queue<int> q;
int h[200005], sg[200005], mx, sum[200005];
vector<int> nx[200005];
void work() {
  for (int i = 1; i <= n; ++i)
    if (!deg[i]) q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop(), sort(nx[u].begin(), nx[u].end());
    for (int x : nx[u])
      if (x > sg[u])
        break;
      else if (x == sg[u])
        ++sg[u];
    sg[u] > mx ? mx = sg[u] : 0;
    for (int v : e[u]) nx[v].push_back(sg[u]), --deg[v] ? void() : q.push(v);
  }
  for (int i = 1; i <= n; ++i) sum[sg[i]] ^= h[i];
  for (int i = 0; i <= mx; ++i)
    if (sum[i]) return puts("WIN"), void();
  puts("LOSE"), void();
}
int vis[200005];
void solve(int d) {
  int u;
  for (u = 1; u <= n; ++u)
    if (sg[u] == d && h[u] > (sum[d] ^ h[u])) break;
  h[u] = sum[d] ^ h[u];
  for (int v = 1; v <= n; ++v) {
    if (sum[sg[v]]) {
      int flg = 0;
      for (int t : e[v])
        if (t == u) flg = 1, h[v] = sum[sg[v]] ^ h[v];
      if (!flg) continue;
      sum[sg[v]] = 0;
    }
  }
  for (int i = 1; i <= n; ++i) printf("%d ", h[i]);
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) h[i] = read();
  for (int i = 1; i <= m; ++i) add(read(), read());
  work();
  for (int i = mx; i >= 0; --i)
    if (sum[i]) return solve(i), 0;
  return 0;
}
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
