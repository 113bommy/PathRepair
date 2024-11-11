#include <bits/stdc++.h>
using namespace std;
long long int a[1 << 21], h[1 << 21], ret;
int n, m, i, r, l;
int main() {
  scanf("%d%d", &n, &m);
  a[n] = h[0] = 1;
  for (i = 1; i < n; ++i) a[n + i] = h[i] = h[i - 1] * 5;
  while (m--) {
    scanf("%d %d", &r, &l);
    --r, --l;
    a[l] += h[r], a[r] += a[l];
    a[r + n] += h[l];
    a[l + n] += h[r];
  }
  sort(a, a + 2 * n);
  l = 0, ret = 0;
  for (r = 1; r < 2 * n; ++r) {
    if (a[r] != a[r - 1]) l = r;
    ret += r - l;
  }
  cout << ret << endl;
}
