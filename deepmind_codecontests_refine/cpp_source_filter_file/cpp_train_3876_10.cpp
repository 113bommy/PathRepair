#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  int ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
int add(int x, int y) { return x + y >= 998244353 ? x + y - 998244353 : x + y; }
int sub(int x, int y) { return x - y < 0 ? x - y + 998244353 : x - y; }
int mul(int x, int y) { return 1LL * x * y % 998244353; }
struct Query {
  int x, y, u, v;
};
Query q[2000005];
int a[305][305], fa[2000005], ans[2000005];
int id[305][305], cnt, res, n, m, Q;
int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }
void merge(int u, int v) {
  u = find(u), v = find(v);
  if (u != v) fa[u] = v, res--;
}
void update(int x, int y) {
  if (x > 1 && a[x - 1][y] == a[x][y]) merge(id[x - 1][y], id[x][y]);
  if (x < n && a[x + 1][y] == a[x][y]) merge(id[x + 1][y], id[x][y]);
  if (y > 1 && a[x][y - 1] == a[x][y]) merge(id[x][y - 1], id[x][y]);
  if (y < m && a[x][y + 1] == a[x][y]) merge(id[x][y + 1], id[x][y]);
}
void work1() {
  for (int i = 1; i <= Q; i++) {
    if (q[i].u == q[i].v) continue;
    int x = q[i].x, y = q[i].y;
    a[x][y] = q[i].u;
    res = 1;
    id[x][y] = ++cnt;
    fa[cnt] = cnt;
    update(x, y);
    ans[i] += res;
  }
}
void work2() {
  for (int i = Q; i >= 1; i--) {
    if (q[i].u == q[i].v) continue;
    int x = q[i].x, y = q[i].y;
    a[x][y] = q[i].v;
    res = 1;
    id[x][y] = ++cnt;
    fa[cnt] = cnt;
    update(x, y);
    ans[i] -= res;
  }
}
signed main() {
  cin >> n >> m >> Q;
  for (int i = 1; i <= Q; i++) {
    q[i].x = read(), q[i].y = read(), q[i].u = read();
    q[i].v = a[q[i].x][q[i].y];
    a[q[i].x][q[i].y] = q[i].u;
  }
  memset(a, 0, sizeof(a));
  work1();
  memset(fa, 0, sizeof(fa));
  memset(id, 0, sizeof(id));
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      id[i][j] = ++cnt;
      fa[cnt] = cnt;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      update(i, j);
    }
  }
  work2();
  ans[0] = 1;
  for (int i = 1; i <= Q; i++) ans[i] += ans[i - 1];
  for (int i = 1; i <= Q; i++) printf("%d\n", ans[i]);
  return 0;
}
