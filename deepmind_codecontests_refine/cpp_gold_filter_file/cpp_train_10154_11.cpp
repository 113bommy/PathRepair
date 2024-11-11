#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int n;
long long a[maxn], b[maxn], s;
void xorGauss(int n) {
  int r = 0, c = 60, m = 60;
  for (; r < n && c >= 0; ++r, --c) {
    int p = r;
    for (; p < n; ++p)
      if ((a[p] >> c) & 1) break;
    if (p == n) {
      --r;
      continue;
    }
    if (p != r) swap(a[p], a[r]);
    for (int i = 0; i < n; ++i)
      if (i != r && ((a[i] >> c) & 1)) a[i] ^= a[r];
  }
  int len = r, j = 60;
  for (int i = (0); i <= (r - 1); ++i)
    if (a[i]) {
      while (!(a[i] & (1LL << j))) --j;
      if (s & (1LL << j)) s ^= a[i];
    }
  if (s)
    puts("1/1");
  else
    printf("%lld/%lld\n", (1LL << len) - 1, 1LL << len);
}
int main() {
  scanf("%d", &n);
  for (int i = (0); i <= (n - 1); ++i)
    scanf("%lld %lld", a + i, b + i), s ^= a[i], a[i] ^= b[i];
  xorGauss(n);
  return 0;
}
