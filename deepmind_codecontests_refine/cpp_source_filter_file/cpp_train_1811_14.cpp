#include <bits/stdc++.h>
using namespace std;
const int N = 1100000;
int n, k, a[N], b[N], c[N], m;
int main() {
  scanf("%d%d", &n, &k);
  m = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    m = max(m, a[i]);
  }
  ++m;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j) ++b[abs(a[i] - a[j])];
  for (int i = 1; i <= m; ++i)
    for (int j = 2; i * j <= m; ++j) b[i] += b[j * i];
  int f;
  for (int i = 1; i <= m; ++i) {
    if (b[i] > k * (k + 1) / 2) continue;
    if (b[i] <= k) {
      printf("%d", i);
      break;
    }
    memset(c, 0, sizeof(c));
    f = 0;
    for (int j = 1; j <= n; ++j) {
      ++c[a[j] % i];
      if (c[a[j % i]] > 1) ++f;
      if (f > k) break;
    }
    if (f <= k) {
      printf("%d", i);
      break;
    }
  }
}
