#include <bits/stdc++.h>
using namespace std;
int n, m, f[50010];
struct node {
  int f[12], g[12], size;
} a[50010];
struct cmp {
  bool operator()(node a, node b) {
    for (int i = 1; i <= m; i++)
      if (a.f[i] > b.g[i]) return 0;
    return 1;
  }
};
multiset<node, cmp> q;
inline void up(node &a, node b) {
  for (int i = 1; i <= m; i++)
    a.f[i] = max(a.f[i], b.f[i]), a.g[i] = min(a.g[i], b.g[i]);
  a.size += b.size;
}
inline bool operator==(node a, node b) {
  int t = 0;
  for (int i = 1; i <= m; i++) t |= (a.f[i] > b.g[i]) | (2 * (a.g[i] < b.f[i]));
  return t == 3;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) f[i] = i;
  node p1, p2;
  for (int i = 1; i <= m; i++) p1.f[i] = p1.g[i] = 0;
  for (int i = 1; i <= m; i++) p2.f[i] = p2.g[i] = 1999999999;
  q.insert(p1);
  q.insert(p2);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      scanf("%d", &a[i].f[j]), a[i].g[j] = a[i].f[j], a[i].size = 1;
  for (int i = 1; i <= n; i++) {
    set<node>::iterator it = q.lower_bound(a[i]), it2;
    while (*it == a[i]) it2 = it, it2--, up(a[i], *it), q.erase(it), it = it2;
    it = q.lower_bound(a[i]);
    while (*it == a[i]) it2 = it, it2++, up(a[i], *it), q.erase(it), it = it2;
    q.insert(a[i]);
    printf("%d\n", (--(--q.end()))->size);
  }
  return 0;
}
