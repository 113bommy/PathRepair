#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  char c;
  bool fu = 0;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') fu = 1, c = getchar();
  for (x = 0; c > 32; c = getchar()) x = x * 10 + c - '0';
  if (fu) x *= -1;
}
template <class T>
inline void read(T &x, T &y) {
  read(x);
  read(y);
}
template <class T>
inline void read(T &x, T &y, T &z) {
  read(x, y);
  read(z);
}
const int N = 211111;
pair<int, int> a[N];
vector<int> g[N];
int ans[N];
bool vis[N];
void dfs(int u, int d) {
  ans[u] = d;
  vis[u] = 1;
  for (int _tmp = g[u].size(), i = 0; i < _tmp; ++i) {
    int v = g[u][i];
    if (vis[v]) continue;
    dfs(v, d ^ 1);
  }
}
int n;
int main() {
  read(n);
  for (int _tmp = n, i = 1; i <= _tmp; ++i) {
    int &x = a[i].first, &y = a[i].second;
    read(x, y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int _tmp = n, i = 1; i <= _tmp; ++i)
    g[i * 2].push_back(i * 2 - 1), g[i * 2 - 1].push_back(i * 2);
  for (int _tmp = n, i = 1; i <= _tmp; ++i)
    if (!vis[i]) dfs(i, 1);
  for (int _tmp = n, i = 1; i <= _tmp; ++i)
    printf("%d %d\n", ans[a[i].first] + 1, ans[a[i].second] + 1);
  return 0;
}
