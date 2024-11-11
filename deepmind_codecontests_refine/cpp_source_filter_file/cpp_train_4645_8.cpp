#include <bits/stdc++.h>
using namespace std;
int n, fa[300005][21], dep[300005], lg[300005] = {-1}, maxx;
vector<int> v1, v2;
inline int read() {
  int w = 0, f = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    w = (w << 1) + (w << 3) + ch - '0', ch = getchar();
  return w * f;
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  while (dep[x] > dep[y]) x = fa[x][lg[dep[x] - dep[y]]];
  if (x == y) return x;
  for (int i = lg[dep[x]]; ~i; i--)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}
int dis(int x, int y) { return dep[x] + dep[y] - 2 * dep[lca(x, y)]; }
int main() {
  for (int i = 1; i <= 300000; i++) lg[i] = lg[i >> 1] + 1;
  n = read(), v1.push_back(1), dep[1] = 1;
  for (int i = 2; i <= n + 1; i++) {
    int x = read(), d1 = 0, d2 = 0;
    fa[i][0] = x, dep[i] = dep[x] + 1;
    for (int j = 1; j <= 20; j++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
    if (v1.size()) d1 = dis(v1[0], i);
    if (v2.size()) d2 = dis(v2[0], i);
    if (max(d1, d2) > maxx) {
      maxx = max(d1, d2);
      if (maxx == d1) {
        for (int j = 0; j < v2.size(); j++)
          if (dis(v2[j], i) == d1) v1.push_back(v2[j]);
        v2.clear(), v2.push_back(i);
      }
      if (maxx == d2) {
        for (int j = 0; j < v1.size(); j++)
          if (dis(v1[j], i) == d2) v2.push_back(v1[j]);
        v1.clear(), v1.push_back(i);
      }
    } else if (max(d1, d2) == maxx) {
      if (maxx == d1)
        v2.push_back(i);
      else
        v1.push_back(i);
    }
    printf("%lu\n", v1.size() + v2.size());
  }
  return 0;
}
