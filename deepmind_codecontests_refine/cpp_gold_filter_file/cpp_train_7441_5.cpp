#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
int a[N], h[N], f[N << 2], lazy[N << 2];
vector<int> p[N], g[N];
struct node {
  int fi, id, se;
} b[N];
void dfs(int x, int fa) {
  b[x] = b[fa];
  if (h[x] <= b[x].fi) {
    b[x].se = b[x].fi;
    b[x].fi = h[x];
    b[x].id = x;
  } else {
    if (h[x] < b[x].se) b[x].se = h[x];
  }
  for (int v : p[x])
    if (v != fa) {
      dfs(v, x);
    }
}
void built(int x, int l, int r, int n) {
  if (l == r) {
    f[x] = -(n - l + 1);
    return;
  }
  int mid = (l + r) / 2;
  built(x << 1, l, mid, n);
  built(x << 1 | 1, mid + 1, r, n);
  f[x] = min(f[x << 1], f[x << 1 | 1]);
}
void push_down(int x) {
  f[x << 1] += lazy[x];
  lazy[x << 1] += lazy[x];
  f[x << 1 | 1] += lazy[x];
  lazy[x << 1 | 1] += lazy[x];
  lazy[x] = 0;
}
void update(int x, int l, int r, int left, int right, int y) {
  if (left > r || right < l) return;
  if (left <= l && right >= r) {
    f[x] += y;
    lazy[x] += y;
    return;
  }
  push_down(x);
  int mid = (l + r) / 2;
  update(x << 1, l, mid, left, right, y);
  update(x << 1 | 1, mid + 1, r, left, right, y);
  f[x] = min(f[x << 1], f[x << 1 | 1]);
}
int R;
void query(int x, int l, int r) {
  if (f[x] >= 0) return;
  if (l == r) {
    R = l;
    return;
  }
  push_down(x);
  int mid = (l + r) / 2;
  if (f[x << 1 | 1] < 0)
    query(x << 1 | 1, mid + 1, r);
  else
    query(x << 1, l, mid);
}
bool cmp(int x, int y) { return b[x].se < b[y].se; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    p[u].push_back(v);
    p[v].push_back(u);
  }
  int k;
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) scanf("%d", &a[i]);
  sort(a + 1, a + k + 1);
  b[0] = {(int)2e9, 0, (int)2e9};
  dfs(1, 0);
  built(1, 1, k, k);
  for (int i = 1; i <= n; i++) {
    g[b[i].id].push_back(i);
    int t = upper_bound(a + 1, a + k + 1, b[i].fi) - a - 1;
    update(1, 1, k, 1, t, 1);
  }
  if (f[1] >= 0) {
    printf("0");
    return 0;
  }
  int ans = 2e9;
  for (int i = 1; i <= n; i++)
    if (g[i].size()) {
      sort(g[i].begin(), g[i].end(), cmp);
      int len = g[i].size(), tmp = -1;
      for (int j = 0; j < len; j++) {
        int t = upper_bound(a + 1, a + k + 1, b[g[i][j]].fi) - a - 1;
        update(1, 1, k, 1, t, -1);
      }
      for (int j = 0; j < len; j++) {
        int t = upper_bound(a + 1, a + k + 1, b[g[i][j]].se) - a - 1;
        R = 0;
        query(1, 1, k);
        if (tmp == -1 && f[1] + len - j >= 0 && R <= t) {
          tmp = a[R];
        }
        update(1, 1, k, 1, t, 1);
      }
      for (int j = 0; j < len; j++) {
        int t = upper_bound(a + 1, a + k + 1, b[g[i][j]].se) - a - 1;
        update(1, 1, k, 1, t, -1);
      }
      for (int j = 0; j < len; j++) {
        int t = upper_bound(a + 1, a + k + 1, b[g[i][j]].fi) - a - 1;
        update(1, 1, k, 1, t, 1);
      }
      if (tmp != -1) {
        ans = min(ans, tmp - h[i]);
      }
    }
  if (ans == 2e9)
    printf("-1");
  else
    printf("%d", ans);
  return 0;
}
