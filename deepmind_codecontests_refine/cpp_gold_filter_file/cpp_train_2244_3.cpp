#include <bits/stdc++.h>
using namespace std;
int l, r, n, mid, res;
int ans[9];
int query(int a, int b, int c, int d) {
  printf("? %d %d %d %d\n", a, b, c, d);
  fflush(stdout);
  int x;
  scanf("%d", &x);
  return x;
}
void find(int a, int b, int c, int d) {
  int res = a;
  l = a, r = c;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (!query(mid, b, c, d))
      r = mid - 1;
    else
      res = mid, l = mid + 1;
  }
  a = res;
  l = a, r = c, res = c;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (query(a, b, mid, d))
      res = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  c = res;
  l = b, r = d, res = b;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (!query(a, mid, c, d))
      r = mid - 1;
    else
      res = mid, l = mid + 1;
  }
  b = res;
  l = b, r = d, res = d;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (query(a, b, c, mid))
      res = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  d = res;
  ans[++ans[0]] = a, ans[++ans[0]] = b, ans[++ans[0]] = c, ans[++ans[0]] = d;
}
int main() {
  scanf("%d", &n);
  l = 1, r = n;
  res = n;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (!query(1, 1, n, mid))
      l = mid + 1;
    else
      res = mid, r = mid - 1;
  }
  if ((query(1, 1, n, res) == 1) && (query(1, res + 1, n, n) == 1)) {
    find(1, 1, n, res);
    find(1, res + 1, n, n);
    putchar('!');
    for (int i = 1; i <= 8; i++) printf(" %d", ans[i]);
    return 0;
  }
  l = 1, r = n, res = n;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (!query(1, 1, mid, n))
      l = mid + 1;
    else
      res = mid, r = mid - 1;
  }
  find(1, 1, res, n);
  find(res + 1, 1, n, n);
  putchar('!');
  for (int i = 1; i <= 8; i++) printf(" %d", ans[i]);
  return 0;
}
