#include <bits/stdc++.h>
using namespace std;
int m, n, a[100005];
long long orz;
set<int> s;
long long cty(long long x) {
  long long ret = 1;
  int k = m - 2;
  while (k) {
    if (k & 1) ret = (x * ret) % orz;
    x = (x * x) % orz;
    k >>= 1;
  }
  return ret;
}
int main() {
  scanf("%d%d", &m, &n);
  bool hhh = 0;
  orz = m * 1ll;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    if (s.count(a[i])) {
      printf("-1\n");
      return 0;
    }
    s.insert(a[i]);
  }
  sort(a + 1, a + n + 1);
  if (n == 1) {
    printf("%d 0\n", a[1]);
    return 0;
  }
  if (n == m) {
    printf("0 1\n");
    return 0;
  }
  if (n == m - 1) {
    for (int i = 0; i < m; i++) {
      if (!s.count(i)) {
        printf("%d 1\n", (i + 1) % m);
        return 0;
      }
    }
  }
  if (n + n > m) {
    hhh = 1;
    n = 0;
    for (int i = 0; i < m; i++)
      if (!s.count(i)) a[++n] = i;
    s.clear();
    for (int i = 1; i <= n; i++) s.insert(a[i]);
  }
  a[0] = a[n];
  int d = m, o = 0;
  for (int i = 1; i <= n; i++) {
    int k = (a[i] - a[i - 1] + m) % m;
    if (k < d)
      d = k, o = 1;
    else if (k == d)
      o++;
  }
  d = (int)(1ll * d * 1ll * cty(n - o) % orz);
  int hh = 0, out;
  bool ok = 1;
  for (int i = 1; i <= n; i++)
    if (!s.count((a[i] - d + m) % m)) hh = a[i];
  out = hh;
  if (hhh) out = ((int)((n * 1ll * d) % orz) + out) % m;
  for (int i = 1; i <= n; i++) {
    if (!s.count(hh)) ok = 0;
    hh = (hh + d) % m;
  }
  if (ok)
    printf("%d %d\n", out, d);
  else
    printf("-1\n");
  return 0;
}
