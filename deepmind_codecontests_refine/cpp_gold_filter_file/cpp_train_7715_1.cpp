#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 2e4 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;
void Print(int *a, int n) {
  for (int i = 1; i < n; i++) printf("%d ", a[i]);
  printf("%d\n", a[n]);
}
int n;
char a[N];
int X, Y;
int x[N], y[N];
bool ck(int len) {
  for (int l = 1, r = len; r <= n; l++, r++) {
    int dx = x[n] - (x[r] - x[l - 1]);
    int dy = y[n] - (y[r] - y[l - 1]);
    dx = abs(dx - X);
    dy = abs(dy - Y);
    if (len >= dx + dy && (len - dx - dy) % 2 == 0) return true;
  }
  return false;
}
int main() {
  scanf("%d%s", &n, a + 1);
  scanf("%d%d", &X, &Y);
  for (int i = 1; i <= n; i++) {
    int dx = 0, dy = 0;
    if (a[i] == 'R')
      dx = 1;
    else if (a[i] == 'L')
      dx = -1;
    else if (a[i] == 'U')
      dy = 1;
    else
      dy = -1;
    x[i] = x[i - 1] + dx, y[i] = y[i - 1] + dy;
  }
  int l = 0, r = n;
  int ans = -1;
  while (l <= r) {
    int m = l + r >> 1;
    if (ck(m))
      ans = m, r = m - 1;
    else
      l = m + 1;
  }
  printf("%d\n", ans);
  return 0;
}
