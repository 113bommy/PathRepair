#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
bool Finish_read;
template <class T>
inline void read(T &x) {
  Finish_read = 0;
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    if (ch == EOF) return;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  x *= f;
  Finish_read = 1;
}
template <class T>
inline void print(T x) {
  if (x / 10 != 0) print(x / 10);
  putchar(x % 10 + '0');
}
template <class T>
inline void writeln(T x) {
  if (x < 0) putchar('-');
  x = abs(x);
  print(x);
  putchar('\n');
}
template <class T>
inline void write(T x) {
  if (x < 0) putchar('-');
  x = abs(x);
  print(x);
}
const int maxn = 200005;
int n, dis[maxn], c0, c1, sz[maxn];
vector<int> G[maxn];
long long ans;
inline void dfs(int u, int f) {
  sz[u] = 1;
  for (int i = 0; i < (int)G[u].size(); ++i) {
    int v = G[u][i];
    if (v == f) continue;
    dis[v] = dis[u] + 1;
    dfs(v, u);
    sz[u] += sz[v];
    ans += sz[v] * (n - sz[v]);
  }
}
int main() {
  read(n);
  for (int i = 1, x, y; i < n; ++i)
    read(x), read(y), G[x].push_back(y), G[y].push_back(x);
  dfs(1, 0);
  for (int i = 1; i <= n; ++i)
    if (dis[i] & 1)
      ++c1;
    else
      ++c0;
  printf("%lld\n", (ans + 1ll * c0 * c1) / 2);
}
