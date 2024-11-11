#include <bits/stdc++.h>
using namespace std;
int l[500010], r[500010], s[500010], a[500010], f[500010];
int n, i, z, ans;
int max(int a, int b) {
  if (a > b) return a;
  return b;
}
void build(int x, int a, int b) {
  int m;
  l[x] = a;
  r[x] = b;
  if (b - a > 1) {
    m = (a + b) >> 1;
    build(2 * x, a, m);
    build(2 * x + 1, m, b);
  }
}
void change(int x, int a, int b, int c) {
  int m;
  if (r[x] - l[x] == 1) {
    s[x] = c;
    return;
  } else {
    m = (l[x] + r[x]) >> 1;
    if (a < m) change(2 * x, a, b, c);
    if (m < b) change(2 * x + 1, a, b, c);
    s[x] = max(s[2 * x], s[2 * x + 1]);
  }
}
int query(int x, int a, int b) {
  int m, ans;
  if ((a <= l[x]) && (r[x] <= b)) return s[x];
  m = (l[x] + r[x]) >> 1;
  ans = 0;
  if (a < m) ans = max(ans, query(2 * x, a, b));
  if (m < b) ans = max(ans, query(2 * x + 1, a, b));
  return ans;
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  build(1, 0, n);
  for (i = 1; i <= n; i++) {
    if (a[i] - 1)
      z = query(1, 0, a[i] - 1);
    else
      z = 0;
    f[i] = z + 1;
    change(1, a[i - 1], a[i], f[i]);
  }
  for (i = 1; i <= n; i++) ans = max(ans, f[i]);
  printf("%d", ans);
}
