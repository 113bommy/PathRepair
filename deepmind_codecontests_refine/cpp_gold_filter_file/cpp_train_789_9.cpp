#include <bits/stdc++.h>
using namespace std;
char getc() {
  char c = getchar();
  while ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z') && (c < '0' || c > '9'))
    c = getchar();
  return c;
}
int gcd(int n, int m) { return m == 0 ? n : gcd(m, n % m); }
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return x * f;
}
int n, m, a[300010], p[300010], ans[300010], u, t;
bool flag[300010];
struct data {
  int to, nxt;
} edge[300010 << 1];
void addedge(int x, int y) {
  t++;
  edge[t].to = y, edge[t].nxt = p[x], p[x] = t;
}
void dfs(int k) {
  flag[k] = 1;
  for (int i = p[k]; i; i = edge[i].nxt)
    if (!flag[edge[i].to]) {
      dfs(edge[i].to);
      if (a[edge[i].to]) ans[++u] = (i - 1) / 2 + 1, a[k] ^= 1;
    }
}
signed main() {
  n = read(), m = read();
  int cnt = 0, cnt2 = 0;
  for (int i = 1; i <= n; i++)
    a[i] = read(), cnt += (a[i] == -1), cnt2 += (a[i] == 1);
  if (cnt == 0 && (cnt2 & 1)) {
    cout << -1;
    return 0;
  }
  for (int i = 1; i <= n; i++)
    if (a[i] == -1)
      if (cnt2 & 1)
        cnt2 = 0, a[i] = 1;
      else
        a[i] = 0;
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    addedge(x, y), addedge(y, x);
  }
  dfs(1);
  cout << u << endl;
  for (int i = 1; i <= u; i++) printf("%d ", ans[i]);
  return 0;
}
