#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int bit[maxn];
int vis[maxn];
int a[maxn];
long long c[maxn];
struct pi {
  int l;
  int id;
} pp;
int low(int p) { return p & (-p); };
void merg(int p, int n, int k) {
  while (p <= n) {
    bit[p] += k;
    p = p + low(p);
  }
}
long long sum(int p) {
  long long s = 0;
  while (p > 0) {
    s += bit[p];
    p = p - low(p);
  }
  return s;
}
vector<pi> g[maxn];
int main() {
  int i, j, n, m;
  cin >> n >> m;
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    pp.id = i;
    pp.l = a;
    g[b].push_back(pp);
  }
  memset(vis, -1, sizeof(vis));
  for (i = 1; i <= n; i++) {
    vis[i] = i;
    for (j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        if (vis[j] != -1) {
          merg(vis[j], n, 1);
        }
        if (j * j != a[i]) {
          if (vis[a[i] / j] != -1) {
            merg(vis[a[i] / j], n, 1);
          }
        }
      }
    }
    for (j = 2 * a[i]; j <= n; j += a[i]) {
      if (vis[j] != -1) {
        merg(vis[j], n, 1);
      }
    }
    int p = g[i].size();
    for (j = 0; j < p; j++) {
      c[g[i][j].id] = sum(i) - sum(g[i][j].l - 1);
    }
  }
  for (i = 0; i < m; i++) {
    printf("%I64d\n", c[i]);
  }
}
