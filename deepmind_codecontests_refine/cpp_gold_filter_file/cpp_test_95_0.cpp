#include <bits/stdc++.h>
using namespace std;
const int mo = 998244353;
inline int read() {
  int x = 0, w = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    w |= ch == '-';
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return w ? -x : x;
}
int T, n, m, x;
int a[1000005];
int pre[2][1000005], suf[2][1000005];
inline int id(int x, int y) { return (x - 1) * m + y - 1; }
int rk[1000005];
struct node {
  int l, r, id;
  inline bool friend operator<(node aa, node bb) { return aa.l < bb.l; }
} p[1000005];
int ans[1000005], ok[1000005];
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &x);
      a[(i - 1) * m + j - 1] = x;
    }
  for (int i = 1; i <= n; i++) {
    pre[0][id(i, 1)] = pre[1][id(i, 1)] = a[id(i, 1)];
    for (int j = 2; j <= m; j++) {
      pre[0][id(i, j)] = min(pre[0][id(i, j - 1)], a[id(i, j)]);
      pre[1][id(i, j)] = max(pre[1][id(i, j - 1)], a[id(i, j)]);
    }
    suf[0][id(i, m)] = suf[1][id(i, m)] = a[id(i, m)];
    for (int j = m - 1; j >= 1; j--) {
      suf[0][id(i, j)] = min(suf[0][id(i, j + 1)], a[id(i, j)]);
      suf[1][id(i, j)] = max(suf[1][id(i, j + 1)], a[id(i, j)]);
    }
  }
  for (int i = 1; i < m; i++) {
    for (int j = 1; j <= n; j++) p[j] = {pre[0][id(j, i)], pre[1][id(j, i)], j};
    sort(p + 1, p + n + 1);
    int mx = 0, flag = 1;
    for (int j = 1; j <= n; j++) {
      mx = max(mx, p[j].r);
      rk[p[j].id] = j;
      if (mx < p[j + 1].l)
        ok[n - j + 1] = 1;
      else
        ok[n - j + 1] = 0;
    }
    for (int j = 1; j <= n; j++)
      p[j] = {suf[0][id(j, i + 1)], suf[1][id(j, i + 1)], j};
    sort(p + 1, p + n + 1);
    mx = 0, flag = 1;
    for (int j = 1; j <= n; j++) {
      mx = max(mx, p[j].r);
      if (mx < p[j + 1].l)
        ok[j + 1] &= 1;
      else
        ok[j + 1] &= 0;
    }
    int now = 0;
    for (int j = n; j > 1; j--) {
      now = max(now, rk[p[j].id]);
      if (now <= n - j + 1 && ok[j]) {
        for (int k = 1; k < j; k++) ans[p[k].id] = 0;
        for (int k = j; k <= n; k++) ans[p[k].id] = 1;
        printf("YES\n");
        for (int k = 1; k <= n; k++) {
          if (ans[k])
            printf("B");
          else
            printf("R");
        }
        printf(" %d\n", i);
        return;
      }
    }
  }
  printf("NO\n");
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
