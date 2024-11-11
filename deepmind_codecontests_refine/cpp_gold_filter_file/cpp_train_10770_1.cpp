#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int res, ok = 1;
  char ch;
  for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') ok = -1;
  res = ch - '0';
  for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
    res = res * 10 + ch - '0';
  return res * ok;
}
int n, lt, x, y, a[200005];
bool okx, oky;
int main() {
  n = read();
  lt = read();
  x = read();
  y = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) {
    int l = i + 1, r = n;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (a[mid] - x >= a[i])
        r = mid;
      else
        l = mid + 1;
    }
    if (a[l] - x == a[i]) okx = true;
  }
  for (int i = 1; i <= n; i++) {
    int l = i + 1, r = n;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (a[mid] - y >= a[i])
        r = mid;
      else
        l = mid + 1;
    }
    if (a[l] - y == a[i]) oky = true;
  }
  if (okx && oky) {
    printf("0\n");
    return 0;
  }
  if (okx || oky) {
    if (okx)
      printf("1\n%d\n", y);
    else
      printf("1\n%d\n", x);
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    int now = a[i] + x, l = 1, r = n;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (a[mid] - y >= now)
        r = mid;
      else
        l = mid + 1;
    }
    if (a[l] - y == now && now <= lt) {
      printf("1\n%d\n", now);
      return 0;
    }
    l = 1;
    r = n;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (now - y > a[mid])
        l = mid + 1;
      else
        r = mid;
    }
    if (now - y == a[l] && now <= lt) {
      printf("1\n%d\n", now);
      return 0;
    }
    now = a[i] - x;
    l = 1;
    r = n;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (a[mid] - y >= now)
        r = mid;
      else
        l = mid + 1;
    }
    if (a[l] - y == now && now >= 0) {
      printf("1\n%d\n", now);
      return 0;
    }
    l = 1;
    r = n;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (now - y > a[mid])
        l = mid + 1;
      else
        r = mid;
    }
    if (now - y == a[l] && now >= 0) {
      printf("1\n%d\n", now);
      return 0;
    }
  }
  printf("2\n%d %d\n", x, y);
  return 0;
}
