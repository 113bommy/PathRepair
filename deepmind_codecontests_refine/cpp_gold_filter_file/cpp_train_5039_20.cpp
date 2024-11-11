#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * w;
}
const int N = 1e5 + 5;
int n, a[N], ans = 0;
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
    ans += -a[i];
    a[i] <<= 1;
  }
  int mx = 0, res = 0;
  for (int i = 1; i <= n; ++i) {
    res += a[i];
    mx = max(mx, res);
    if (res < 0) res = 0;
  }
  printf("%d\n", ans + mx);
  return 0;
}
