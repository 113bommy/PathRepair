#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int M = 1e5 + 100;
int isroot[N], h[N], fa[N], siz[N];
int n, m, cnt, k;
struct edge {
  int to, next;
} e[M << 1];
long long ans;
int mx = 1, tmp;
inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int main() {
  scanf("%d%d%d", &n, &m, &k);
  int x;
  for (int i = 1; i <= k; i++) scanf("%d", &x), isroot[x] = 1;
  for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
  int u, v;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    u = find(u), v = find(v);
    if (u == v) continue;
    if (!isroot[u] && !isroot[v]) {
      fa[u] = v;
      siz[u] += siz[v];
    } else {
      if (isroot[v]) swap(u, v);
      fa[v] = u;
      siz[u] += siz[v];
      mx = max(siz[u], mx);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i == find(i)) {
      if (isroot[i]) {
        ans += 1ll * (siz[i] - 1) * siz[i] / 2;
      } else {
        tmp += siz[i];
      }
    }
  }
  ans -= 1ll * mx * (mx - 1) / 2;
  ans += 1ll * (mx + tmp) * (mx + tmp - 1) / 2;
  cout << ans - m << endl;
}
