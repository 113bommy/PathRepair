#include <bits/stdc++.h>
using namespace std;
const int max_n = 5e5 + 100;
int n, m;
bool vis[max_n];
int ts[max_n];
int blog[max_n];
int res[max_n];
bool cmp(int a, int b) { return ts[a] < ts[b]; }
struct edge {
  int to, next;
} E[max_n << 1];
int head[max_n];
int cnt = 1;
void add(int from, int to) {
  E[cnt].to = to;
  E[cnt].next = head[from];
  head[from] = cnt++;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    add(u, v);
    add(v, u);
  }
  for (int i = 1; i <= n; ++i) cin >> ts[i];
  for (int i = 1; i <= n; ++i) blog[i] = i;
  sort(blog + 1, blog + 1 + n, cmp);
  for (int i = 1; i <= n; ++i) res[i] = 1;
  for (int _ = 1; _ <= n; ++_) {
    int u = blog[_];
    vis[u] = true;
    if (res[u] != ts[u]) {
      cout << -1;
      return 0;
    }
    for (int i = head[u]; i; i = E[i].next) {
      int v = E[i].to;
      if (vis[v])
        continue;
      else if (ts[u] == ts[v] || res[v] < ts[u]) {
        cout << -1;
        return 0;
      } else
        res[v] = ts[u] + 1;
    }
  }
  for (int i = 1; i <= n; ++i) cout << blog[i] << " ";
}
