#include <bits/stdc++.h>
using namespace std;
int t, n, m, fa[2005], ox[2005], oy[2005], sum[2005];
bitset<2005> a[2005];
struct node {
  int x, y, z;
} e[2000005];
int read() {
  int x = 0, fl = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') fl = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * fl;
}
int cmp(node a, node b) { return a.z > b.z; }
int gf(int x) { return x == fa[x] ? fa[x] : fa[x] = gf(fa[x]); }
void merge(int x, int y) {
  fa[gf(x)] = gf(y);
  return;
}
int main() {
  t = read();
  while (t--) {
    n = read(), m = read();
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; i++) a[i].reset();
    for (int i = 1; i <= m; i++) {
      char ch[2005];
      scanf("%s", ch + 1);
      for (int j = 1; j <= n; j++)
        a[j][i] = ch[j] - '0', sum[i] += (ch[j] - '0');
    }
    int tot = 0;
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
        e[++tot] = (node){i, j, (int)(a[i] & a[j]).count()};
    sort(e + 1, e + tot + 1, cmp);
    int p = 0;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= tot; i++)
      if (gf(e[i].x) != gf(e[i].y))
        merge(e[i].x, e[i].y), p++, ox[p] = e[i].x, oy[p] = e[i].y;
    int fl = 1;
    for (int i = 1; i <= m; i++) {
      int s = 0;
      for (int j = 1; j <= p; j++) s += (a[ox[j]][i] && a[oy[j]][i]);
      if (s != sum[i] - 1) {
        fl = 0;
        break;
      }
    }
    if (fl) {
      puts("YES");
      for (int i = 1; i <= p; i++) printf("%d %d\n", ox[i], oy[i]);
    } else
      puts("NO");
  }
  return 0;
}
