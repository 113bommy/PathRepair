#include <bits/stdc++.h>
using namespace std;
char op[300005];
int n, k, fa[300005], v[300005], num[300005], sz[300005], ans, gx[300005];
vector<int> vec[300005];
int ff(int x) {
  if (fa[x] == x) return x;
  int f = ff(fa[x]);
  v[x] ^= v[fa[x]];
  return fa[x] = f;
}
inline void merge(int x, int y, int p) {
  if (ff(x) == ff(y)) return;
  int fx = ff(x), fy = ff(y);
  if (fx == 0) swap(fx, fy);
  v[fx] = p ^ v[x] ^ v[y];
  sz[fy] += sz[fx];
  num[fy] += v[fx] ? sz[fx] - num[fx] : num[fx];
  ans -= gx[fy] + gx[fx];
  if (fy == 0)
    gx[fy] = num[fy];
  else
    gx[fy] = min(sz[fy] - num[fy], num[fy]);
  ans += gx[fy], fa[fx] = fy;
}
int main() {
  scanf("%d%d%s", &n, &k, op + 1);
  for (int i = 0; i <= k; i++) fa[i] = i, sz[i] = 1;
  for (int i = 1, c, x; i <= k; i++) {
    scanf("%d", &c);
    while (c--) scanf("%d", &x), vec[x].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    if (vec[i].size() == 1) vec[i].push_back(0);
  }
  for (int i = 1; i <= n; i++) {
    if (!vec[i].empty()) merge(vec[i][0], vec[i][1], op[i] == '0');
    printf("%d\n", ans);
  }
  return 0;
}
