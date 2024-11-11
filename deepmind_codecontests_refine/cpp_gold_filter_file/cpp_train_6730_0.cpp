#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int x[N], n;
int main() {
  int i, j, a, b, c, bi, ci, k, ans, mx;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", x + i);
  sort(x, x + n);
  a = b = c = 0;
  for (i = 1; i < n && x[i] == x[i - 1]; i++)
    ;
  a = i;
  for (; i < n && x[i] == x[0] + 1; i++)
    ;
  b = i - a;
  c = n - i;
  k = c - a;
  mx = n;
  ans = a;
  if (c)
    for (i = 0; i < n; i++) {
      ci = i + k;
      bi = n - i - ci;
      if (ci > n || ci < 0 || bi < 0) continue;
      j = min(i, a) + min(bi, b) + min(ci, c);
      if (j < mx) {
        mx = j;
        ans = i;
      }
    }
  printf("%d\n", mx);
  ci = ans + k;
  bi = n - ans - ci;
  for (i = 0; i < ans; i++) printf("%d ", x[0]);
  for (i = 0; i < bi; i++) printf("%d ", x[0] + 1);
  for (i = 0; i < ci; i++) printf("%d ", x[0] + 2);
  return 0;
}
