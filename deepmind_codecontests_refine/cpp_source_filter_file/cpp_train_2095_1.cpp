#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], b[200005], top, q[200005], now, lat, ans[200005];
int gets() {
  int v = 0;
  bool f = 0;
  char ch;
  while (!isdigit(ch)) {
    f |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) {
    v = (v << 3) + (v << 1) + ch - 48;
    ch = getchar();
  }
  return f ? -v : v;
}
int main() {
  n = gets();
  m = gets();
  for (int i = 1; i <= n + m; i++) a[i] = gets();
  for (int i = 1; i <= m + n; i++) {
    b[i] = gets();
    if (b[i]) q[++top] = i;
  }
  a[0] = -1000000005;
  now = 0;
  lat = 1;
  q[m + 1] = n + m + 1;
  a[n + m + 1] = 1000000005;
  for (int i = 1; i <= n + m; i++) {
    if (b[i]) {
      now = lat;
      lat++;
      continue;
    }
    if (a[i] - a[q[now]] <= a[q[lat]] - a[i])
      ans[now]++;
    else
      ans[lat]++;
  }
  for (int i = 1; i < m; i++) printf("%d ", ans[i]);
  printf("%d\n", ans[m]);
  return 0;
}
