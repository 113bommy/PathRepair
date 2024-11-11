#include <bits/stdc++.h>
using namespace std;
int a[10001000], b[10001000], f[10001000];
int n, m, i, j, k, l, ans, c, d;
int find(int x, int y) {
  int l, r, mid;
  l = 0;
  r = y - 1;
  while (l != r) {
    mid = (l + r) / 2 + 1;
    if (f[mid] > x)
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &c);
    a[c] = i;
  }
  for (i = 1; i <= n; i++) {
    scanf("%d", &c);
    b[i] = a[c];
  }
  ans = 1;
  f[0] = 100000086;
  f[1] = b[1];
  for (i = 2; i <= n; i++) {
    c = find(b[i], i);
    f[c + 1] = i;
    ans = max(c + 1, ans);
  }
  printf("%d\n", ans);
  return 0;
}
