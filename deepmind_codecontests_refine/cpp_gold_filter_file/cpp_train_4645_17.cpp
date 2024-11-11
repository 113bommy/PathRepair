#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 1000;
int n, d;
int fa[N][20];
inline void read(int &x) {
  char c = getchar();
  x = 0;
  while (c > '9' || c < '0') c = getchar();
  while (c <= '9' && c >= '0') x = (x << 1) + (x << 3) + c - '0', c = getchar();
}
set<int> v1, v2;
int s1[N], s2[N];
int dep[N], lg[N];
inline int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  while (dep[x] > dep[y]) x = fa[x][lg[dep[x] - dep[y]]];
  if (x == y) return x;
  for (int i = 19; i >= 0; i--) {
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  }
  return fa[x][0];
}
inline int dis(int x, int y) { return dep[x] + dep[y] - 2 * dep[lca(x, y)]; }
int main() {
  read(n);
  for (int i = 2; i <= n + 100; i++) lg[i] = (lg[i >> 1] + 1);
  v1.insert(1), s1[1] = 1;
  for (int i = 2; i <= n + 1; i++) {
    int x;
    read(x);
    dep[i] = dep[x] + 1;
    fa[i][0] = x;
    for (int j = 1; j <= 19; j++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
    if (s1[x]) {
      for (auto s : v1) {
        if (dis(i, s) == d + 1) v2.insert(s), s2[s] = 1;
        s1[s] = 0;
      }
      v1.clear();
      v1.insert(i), s1[i] = 1;
      d++;
    } else if (s2[x]) {
      for (auto s : v2) {
        if (dis(i, s) == d + 1) v1.insert(s), s1[s] = 1;
        s2[s] = 0;
      }
      v2.clear();
      v2.insert(i), s2[i] = 1, d++;
    } else {
      if (!v1.empty() && dis(*v1.begin(), i) == d)
        v2.insert(i), s2[i] = 1;
      else if (!v2.empty() && dis(*v2.begin(), i) == d)
        v1.insert(i), s1[i] = 1;
    }
    printf("%d\n", v1.size() + v2.size());
  }
}
