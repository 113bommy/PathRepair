#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int n, m, ans;
int a[maxn], sz[maxn];
int ctr[maxn][2];
char s[maxn];
class Dsu {
 private:
  int fa[maxn << 1];

 public:
  int rk[maxn << 1], on[maxn << 1], force[maxn << 1];
  inline int find(int x) { return (x == fa[x]) ? x : (fa[x] = find(fa[x])); }
  inline void init() {
    for (int i = (0); i < (n << 1); ++i) {
      on[i] = i & 1;
      rk[i] = on[i] ^ 1;
      fa[i] = i;
      force[i] = false;
    }
    return;
  }
  inline void combine(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    fa[u] = v;
    rk[v] += rk[u];
    on[v] |= on[u];
    force[v] |= force[u];
    return;
  }
} dsu;
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s);
  for (int i = (0); i < (n); ++i) a[i] = s[i] - '0';
  for (int i = (0); i < (m); ++i) {
    int x;
    scanf("%d", &x);
    for (int j = (0); j < (x); ++j) {
      int y;
      scanf("%d", &y);
      --y;
      ctr[y][sz[y]++] = i;
    }
  }
  dsu.init();
  for (int i = (0); i < (n); ++i) {
    if (sz[i] == 1) {
      int u = ctr[i][0], u0 = dsu.find(u << 1), u1 = dsu.find(u << 1 | 1);
      if (!a[i]) {
        if (dsu.on[u1]) {
          ans -= dsu.rk[u1];
          ans += dsu.rk[u0];
        }
        dsu.on[u1] = false;
        dsu.on[u0] = dsu.force[u0] = true;
      } else {
        if (dsu.on[u0]) {
          ans -= dsu.rk[u0];
          ans += dsu.rk[u1];
        }
        dsu.on[u0] = false;
        dsu.on[u1] = dsu.force[u1] = true;
      }
    } else {
      int u = ctr[i][0], v = ctr[i][1], u0 = dsu.find(u << 1),
          u1 = dsu.find(u << 1 | 1), v0 = dsu.find(v << 1),
          v1 = dsu.find(v << 1 | 1), w;
      if (dsu.on[u0])
        ans -= dsu.rk[u0];
      else
        ans -= dsu.rk[u1];
      if (u0 != v0 && u1 != v0) {
        if (dsu.on[v0])
          ans -= dsu.rk[v0];
        else
          ans -= dsu.rk[v1];
      }
      if (s[i] == '0') {
        dsu.combine(u0, v1);
        dsu.combine(u1, v0);
      } else {
        dsu.combine(u0, v0);
        dsu.combine(u1, v1);
      }
      u0 = dsu.find(u0);
      u1 = dsu.find(u1);
      if (dsu.force[u0])
        w = u0;
      else if (dsu.force[u1])
        w = u1;
      else
        w = dsu.rk[u0] < dsu.rk[u1] ? u0 : u1;
      ans += dsu.rk[w];
      dsu.on[w] = true;
      dsu.on[dsu.find(w ^ 1)] = false;
    }
    printf("%d\n", ans);
  }
  return 0;
}
