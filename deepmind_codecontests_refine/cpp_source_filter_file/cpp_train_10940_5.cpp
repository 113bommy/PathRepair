#include <bits/stdc++.h>
template <typename Y>
inline bool updmin(Y &a, Y b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename Y>
inline bool updmax(Y &a, Y b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename Y>
inline Y abs(Y a) {
  if (a < 0) a = -a;
  return a;
}
template <typename Y>
inline Y sqr(Y a) {
  return a * a;
}
int read() {
  int w = 1, q = 0, ch = ' ';
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') w = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) q = q * 10 + ch - 48;
  return q * w;
}
inline void FileIO() {
  freopen(
      ""
      ".in",
      "r", stdin);
  freopen(
      ""
      ".out",
      "w", stdout);
}
const int N = 1000100;
std::vector<int> v, r, G[N], R[N];
int n, m;
int vis[N];
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    G[x].push_back(y);
    R[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    v.push_back(i);
    for (auto t : G[i]) {
      vis[t] = 1;
    }
  }
  std::reverse(v.begin(), v.end());
  memset(vis, 0, sizeof vis);
  for (auto i : v) {
    vis[i] = 1;
    for (auto t : R[i]) {
      vis[i] &= !vis[t];
    }
    if (vis[i]) r.push_back(i);
  }
  printf("%lld\n", r.size());
  for (auto t : r) {
    printf("%d ", t);
  }
  return 0;
}
