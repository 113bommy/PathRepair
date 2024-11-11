#include <bits/stdc++.h>
inline int Read() {
  int x(0), f(1);
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  return x * f;
}
const int maxn = 1e2 + 9, inf = 0x3f3f3f3f;
struct node {
  int x, y;
} a[maxn], b[maxn];
int n, r, ans, tot1, tot2;
int f[60009];
inline bool cmp1(node xx, node yy) { return xx.x < yy.x; }
inline bool cmp2(node xx, node yy) {
  if (xx.x + xx.y == yy.x + yy.y)
    return xx.x < yy.x;
  else
    return xx.x + xx.y > yy.x + yy.y;
}
int main() {
  n = Read();
  r = Read();
  for (int i = 1; i <= n; ++i) {
    int x(Read()), y(Read());
    if (y >= 0)
      a[++tot1] = (node){x, y};
    else
      b[++tot2] = (node){x, y};
  }
  std::sort(a + 1, a + 1 + tot1, cmp1);
  for (int i = 1; i <= tot1; ++i) {
    if (r >= a[i].x)
      r += a[i].y, ++ans;
    else
      break;
  }
  std::sort(b + 1, b + 1 + tot2, cmp2);
  memset(f, -inf, sizeof(f));
  f[r] = ans;
  for (int i = 1; i <= tot2; ++i)
    for (int j = 0; j <= 60000; ++j) {
      if (j + b[i].y < 0) continue;
      f[j + b[i].y] = std::max(f[j + b[i].y], f[j] + 1);
    }
  for (int i = 0; i <= 60000; ++i) ans = std::max(ans, f[i]);
  printf("%d\n", ans);
  return 0;
}
