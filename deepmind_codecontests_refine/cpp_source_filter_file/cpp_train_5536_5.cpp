#include <bits/stdc++.h>
using namespace std;
const int M = 200010;
int a[M], b[M], last[M], n, q, x, y, f;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    scanf("%d", &f);
    if (f == 1) {
      scanf("%d%d", &x, &y);
      a[x] = y;
      last[x] = i;
    } else {
      scanf("%d", &y);
      b[i] = y;
    }
  }
  for (int i = n - 1; i >= 0; --i) b[i] = max(b[i], b[i + 1]);
  for (int i = 1; i <= n; ++i) {
    printf("%d ", max(a[i], b[last[i]]));
  }
}
