#include <bits/stdc++.h>
using namespace std;
const int N = 312345;
int a[N];
int read() {
  int x;
  scanf("%d", &x);
  return x;
}
int n, d[N], ind[N];
void update(int x, int y) {
  while (x <= n) d[x] += y, x = (x | (x - 1)) + 1;
}
int sum(int x) {
  int s = 0;
  while (x > 0) s += d[x], x = (x & (x - 1));
  return s;
}
int main() {
  int m, i, j;
  n = read();
  for (i = 1; i <= n; i++) {
    a[i] = read();
    if (!ind[a[i] - 1]) update(a[i], 1);
    ind[a[i]] = i;
  }
  ind[0] = n + 1;
  m = read();
  int t, l, r, x, y;
  for (i = 1; i <= m; i++) {
    t = read();
    l = read();
    r = read();
    if (t == 1) {
      printf("%d\n", sum(r) - sum(l - 1));
    } else {
      x = a[l];
      y = a[r];
      if (x > y) swap(x, y);
      if (ind[x] < ind[x - 1]) update(x, -1);
      if (ind[y] < ind[y - 1]) update(y, -1);
      if (y != x + 1 && ind[x + 1] < ind[x]) update(x + 1, -1);
      if (ind[y + 1] < ind[y]) update(y + 1, -1);
      ind[a[l]] = r;
      ind[a[r]] = l;
      swap(a[l], a[r]);
      if (ind[x] < ind[x - 1]) update(x, 1);
      if (ind[y] < ind[y - 1]) update(y, 1);
      if (y != x + 1 && ind[x + 1] < ind[x]) update(x + 1, 1);
      if (ind[y + 1] < ind[y]) update(y + 1, 1);
    }
  }
}
