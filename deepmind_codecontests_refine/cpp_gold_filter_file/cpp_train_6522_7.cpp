#include <bits/stdc++.h>
using namespace std;
int read() {
  int tmp = 0, fh = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    tmp = tmp * 10 + ch - '0';
    ch = getchar();
  }
  return tmp * fh;
}
int d, num[100010], n, b;
int dist(int l, int r) { return (abs(r - l) - 1) / d + 1; }
bool check(int x) {
  int m = n / 2, pl = x + 1, pr = n - x, lesl = b, lesr = b;
  for (int i = 1; pl <= m && i <= n; i++) {
    int j = num[i];
    while (j != 0 && pl <= m) {
      if (dist(i, pl) > pl) return false;
      if (lesl > j)
        lesl -= j, j = 0;
      else
        j -= lesl, pl++, lesl = b;
    }
  }
  for (int i = n; pr >= (n - m) && i > 0; i--) {
    int j = num[i];
    while (j != 0 && pr >= (n - m)) {
      if (dist(i, pr) > (n - pr + 1)) return false;
      if (lesr > j)
        lesr -= j, j = 0;
      else
        j -= lesr, pr--, lesr = b;
    }
  }
  return true;
}
int main() {
  n = read(), d = read(), b = read();
  for (int i = 1; i <= n; i++) num[i] = read();
  int l = 0, r = n / 2, mid, ans;
  while (l <= r) {
    mid = (l + r) / 2;
    if (check(mid) == true)
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%d\n", ans);
  return 0;
}
