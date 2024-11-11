#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int f[N], a[N], ne[N], sz[N], n, tot, m, k, vis[N];
struct node {
  int nu, nv, u, v;
  friend bool operator<(const node a, const node b) {
    if (a.nu == b.nu) {
      return a.nv < b.nv;
    }
    return a.nu < b.nu;
  }
} p[N];
void inint() {
  for (int i = 0; i <= 2 * n; i++) {
    f[i] = i;
    sz[i] = 1;
  }
  tot = 0;
}
int F(int x) { return f[x] == x ? x : F(f[x]); }
void mere(int x, int y) {
  int xx = F(x), yy = F(y);
  if (xx != yy) {
    if (sz[xx] > sz[yy]) swap(xx, yy);
    sz[yy] += sz[xx];
    f[xx] = f[yy];
    ne[++tot] = xx;
  }
}
void roll_back(int l) {
  while (tot > l) {
    int now = ne[tot--];
    sz[f[now]] -= sz[now];
    f[now] = now;
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  inint();
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    vis[a[i]] = 0;
  }
  int cnt = 1;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (a[u] == a[v]) {
      if (vis[a[u]]) {
        continue;
      }
      if (F(u) == F(v)) {
        k--;
        vis[a[u]] = 1;
      } else {
        mere(u, v + n);
        mere(u + n, v);
      }
    } else {
      if (a[u] > a[v]) swap(u, v);
      p[cnt].u = u, p[cnt].v = v;
      p[cnt].nv = a[v];
      p[cnt++].nu = a[u];
    }
  }
  long long ans = (long long)(k - 1) * k / 2;
  sort(p + 1, p + cnt);
  int i, j;
  int Len = tot;
  for (i = 1; i < cnt; i = j + 1) {
    roll_back(Len);
    for (j = i; j < cnt; j++) {
      if (j == cnt - 1 || p[j].nu != p[j + 1].nu || p[j].nv != p[j + 1].nv) {
        break;
      }
    }
    if (vis[p[j].nu] || vis[p[j].nv]) {
      continue;
    }
    for (int kk = i; kk <= j; kk++) {
      mere(p[kk].u, p[kk].v + n);
      mere(p[kk].v, p[kk].u + n);
      if (F(p[kk].u) == F(p[kk].v)) {
        ans--;
        break;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
