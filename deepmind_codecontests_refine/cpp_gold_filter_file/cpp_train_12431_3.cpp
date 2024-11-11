#include <bits/stdc++.h>
using namespace std;
const int maxn = 3 * 1e5 + 10;
int n, m;
int fa[maxn], pre[maxn], ne[maxn];
int getf(int v) { return fa[v] == v ? v : fa[v] = getf(fa[v]); }
int main() {
  int t, i, j, k, l, r, w, tmp, a;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    fa[i] = i, ne[i] = i + 1;
  }
  while (m--) {
    scanf("%d%d%d", &l, &r, &w);
    for (i = l; i <= r; i = tmp) {
      getf(i);
      pre[fa[i]] = w;
      fa[fa[i]] = w;
      tmp = ne[i];
      ne[i] = r + 1;
    }
  }
  for (i = 1; i <= n; i++) {
    if (pre[i] == i) pre[i] = 0;
    printf(i != n ? "%d " : "%d", pre[i]);
  }
  return 0;
}
