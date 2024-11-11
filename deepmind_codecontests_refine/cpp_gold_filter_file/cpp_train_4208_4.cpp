#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;
int m, n, res, ma;
int a[N], b[N], st;
int s, f;
int main() {
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &b[i]);
  }
  sort(b + 1, b + m + 1);
  a[1] = b[1];
  n = 1;
  for (int i = 2; i <= m; ++i) {
    if (b[i] != a[n]) {
      ++n;
      a[n] = b[i];
    }
  }
  scanf("%d%d", &f, &s);
  res = 0;
  while (s < f) {
    ma = 1;
    st = 0;
    if (b == 0 && a[n] > f) {
      res++;
      break;
    }
    for (int i = 1; i <= n; ++i) {
      if (a[i] > f) break;
      if (f - f % a[i] >= s) {
        st = 1;
        if (f % a[i] > ma) ma = f % a[i];
      }
    }
    if (st == 0) {
      res += (f - s);
      break;
    }
    res++;
    f -= ma;
  }
  printf("%d\n", res);
  return 0;
}
