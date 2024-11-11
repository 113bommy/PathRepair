#include <bits/stdc++.h>
using namespace std;
const int M = 1e4 + 5;
int n, m, q, x, y;
struct number2 {
  int x, y;
} a[M];
struct number1 {
  int f[505], sum = 0;
  int get(int x) {
    if (f[x] == 0)
      return x;
    else
      return f[x] = get(f[x]);
  }
  void hb(int x, int y) {
    int xx = get(x);
    int yy = get(y);
    if (xx != yy) {
      f[xx] = yy;
      sum++;
    }
  }
} l[M], r[M], ans;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &a[i].x, &a[i].y);
    l[i] = l[i - 1];
    l[i].hb(a[i].x, a[i].y);
  }
  for (int i = m; i >= 1; i--) {
    r[i] = r[i + 1];
    r[i].hb(a[i].x, a[i].y);
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &x, &y);
    ans = l[x - 1];
    for (int i = 1; i <= n; i++)
      if (r[y + 1].f[i] != 0) ans.hb(ans.f[i], r[y + 1].f[i]);
    printf("%d\n", n - ans.sum);
  }
  return 0;
}
