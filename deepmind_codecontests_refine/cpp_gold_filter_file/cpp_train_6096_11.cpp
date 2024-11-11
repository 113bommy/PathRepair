#include <bits/stdc++.h>
using namespace std;
const int N = 100;
const int oo = 1000;
int n, l, r;
int left1, left2, right1, right2, top1, top2, bot1, bot2;
int a[100][100], f[100][100];
int print(int x, int y, int u, int v) {
  if (x > u || y > v) return 0;
  printf("? %d %d %d %d\n", x, y, u, v);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret;
}
int main() {
  scanf("%d", &n);
  l = 1;
  r = n;
  left1 = n + 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    int ans = print(1, mid, n, n);
    if (ans == 2) {
      left1 = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  l = 1;
  r = n;
  left2 = n + 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    int ans = print(1, mid, n, n);
    if (ans >= 1) {
      left2 = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  l = 1;
  r = n;
  right2 = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    int ans = print(1, 1, n, mid);
    if (ans == 2) {
      right2 = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  l = 1;
  r = n;
  right1 = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    int ans = print(1, 1, n, mid);
    if (ans >= 1) {
      right1 = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  l = 1;
  r = n;
  top1 = n + 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    int ans = print(mid, 1, n, n);
    if (ans == 2) {
      top1 = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  l = 1;
  r = n;
  top2 = n + 1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    int ans = print(mid, 1, n, n);
    if (ans >= 1) {
      top2 = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  l = 1;
  r = n;
  bot2 = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    int ans = print(1, 1, mid, n);
    if (ans == 2) {
      bot2 = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  l = 1;
  r = n;
  bot1 = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    int ans = print(1, 1, mid, n);
    if (ans >= 1) {
      bot1 = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  if (print(top2, 1, bot1, n) == 1) {
    swap(bot1, bot2);
  } else if (print(1, left2, n, right1) == 1) {
    swap(right1, right2);
  }
  if (!(print(top1, left1, bot1, right1) == 1 &&
        print(top2, left2, bot2, right2) == 1)) {
    swap(top1, top2);
    swap(bot1, bot2);
  }
  printf("! %d %d %d %d %d %d %d %d\n", top1, left1, bot1, right1, top2, left2,
         bot2, right2);
  return 0;
}
