#include <bits/stdc++.h>
using namespace std;
int n, s, t, a[100009];
int read() {
  int x = 1;
  char ch;
  while (ch = getchar(), ch < '0' || ch > '9')
    if (ch == '-') x = -1;
  int s = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
  return s * x;
}
bool check(int x) {
  if (abs(s - t) > x) return 0;
  int l = a[n] - x, r = a[n] + x;
  for (int i = n - 1; i; i--) {
    int L = a[i] - x, R = a[i] + x;
    if (a[i] < l || a[i] > r) {
      L = max(L, l);
      R = min(R, r);
    }
    if (L > R) return 0;
    l = L, r = R;
  }
  return (s >= l && s <= r || t >= l && t <= r);
}
int main() {
  n = read(), s = read(), t = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  int l = 0, r = 1000000000, ret = 1000000000;
  while (l <= r) {
    if (check((l + r >> 1)))
      ret = (l + r >> 1), r = (l + r >> 1) - 1;
    else
      l = (l + r >> 1) + 1;
  }
  printf("%d\n", ret);
  return 0;
}
