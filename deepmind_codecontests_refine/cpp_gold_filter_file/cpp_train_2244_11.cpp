#include <bits/stdc++.h>
using namespace std;
int l, r, n, a[4][2], tot, ans[8], b[4];
bool pd;
int Query(int r1, int c1, int r2, int c2) {
  int ret;
  printf("? %d %d %d %d\n", r1, c1, r2, c2);
  fflush(stdout);
  scanf("%d", &ret);
  return ret;
}
int main() {
  scanf("%d", &n);
  l = 1, r = n;
  while (l < r) {
    int mid = (l + r) / 2;
    if (Query(1, 1, n, mid) == 2)
      r = mid;
    else
      l = mid + 1;
  }
  l = 1, a[0][0] = r;
  while (l < r) {
    int mid = (l + r) / 2;
    if (Query(1, 1, n, mid) > 0)
      r = mid;
    else
      l = mid + 1;
  }
  a[0][1] = r;
  l = 1, r = n;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (Query(1, mid, n, n) == 2)
      l = mid;
    else
      r = mid - 1;
  }
  a[1][0] = l;
  r = n;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (Query(1, mid, n, n) > 0)
      l = mid;
    else
      r = mid - 1;
  }
  a[1][1] = l;
  l = 1, r = n;
  while (l < r) {
    int mid = (l + r) / 2;
    if (Query(1, 1, mid, n) == 2)
      r = mid;
    else
      l = mid + 1;
  }
  a[2][0] = r;
  l = 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (Query(1, 1, mid, n) > 0)
      r = mid;
    else
      l = mid + 1;
  }
  a[2][1] = r;
  l = 1, r = n;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (Query(mid, 1, n, n) == 2)
      l = mid;
    else
      r = mid - 1;
  }
  a[3][0] = l;
  r = n;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (Query(mid, 1, n, n) > 0)
      l = mid;
    else
      r = mid - 1;
  }
  a[3][1] = l;
  for (int i = 0; i < 1 << 4; i++) {
    for (int j = 0; j < 4; j++)
      if (i & 1 << j)
        b[j] = 1;
      else
        b[j] = 0;
    bool pd = true;
    if (a[3][b[3]] > a[2][b[2]] || a[1][b[1]] > a[0][b[0]] ||
        Query(a[3][b[3]], a[1][b[1]], a[2][b[2]], a[0][b[0]]) != 1)
      pd = false;
    if (a[3][1 ^ b[3]] > a[2][1 ^ b[2]] || a[1][1 ^ b[1]] > a[0][1 ^ b[0]] ||
        Query(a[3][1 ^ b[3]], a[1][1 ^ b[1]], a[2][1 ^ b[2]], a[0][1 ^ b[0]]) !=
            1)
      pd = false;
    if (a[0][b[0]] >= a[1][1 ^ b[1]] && a[2][b[2]] >= a[3][1 ^ b[3]])
      pd = false;
    if (pd) {
      ans[0] = a[3][b[3]];
      ans[1] = a[1][b[1]];
      ans[2] = a[2][b[2]];
      ans[3] = a[0][b[0]];
      ans[0 + 4] = a[3][1 ^ b[3]];
      ans[1 + 4] = a[1][1 ^ b[1]];
      ans[2 + 4] = a[2][1 ^ b[2]];
      ans[3 + 4] = a[0][1 ^ b[0]];
      break;
    }
  }
  putchar('!');
  for (int i = 0; i < 8; i++) printf(" %d", ans[i]);
  puts("");
  fflush(stdout);
  return 0;
}
