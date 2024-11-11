#include <bits/stdc++.h>
using namespace std;
int t[300010], a[300010], n, m, l, r;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
bool check(int x) {
  for (int i = 1; i <= n; i++) {
    t[i] = a[i];
    if (t[i] >= t[i - 1]) {
      if (t[i] + x >= m) {
        if ((t[i] + x) % m >= t[i - 1]) t[i] = (t[i] + x) % m;
      }
    } else {
      if (t[i] + x >= t[i - 1])
        t[i] = t[i - 1];
      else
        return 0;
    }
  }
  return 1;
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  l = 0;
  r = m;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
  return 0;
}
