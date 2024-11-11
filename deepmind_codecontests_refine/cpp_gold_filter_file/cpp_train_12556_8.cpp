#include <bits/stdc++.h>
using namespace std;
const int mo = 1e9 + 7;
int n, a[1 << 20], c[1 << 20], ans;
long long fpm(long long x, long long y) {
  long long s = 1;
  while (y) {
    if (y & 1) s = (s * x) % mo;
    y >>= 1, x = (x * x) % mo;
  }
  return s;
}
int main() {
  int i, j, k, x, y;
  scanf("%d\n", &n), c[0] = (1 << n), ans = 0;
  for (i = 0; i < (1 << n); i++) a[i] = getchar() - '0';
  for (i = 1; i < (1 << n); i++) c[i] = (c[i - (i & (-i))] >> 1);
  for (i = 2; i <= (1 << n); i <<= 1)
    for (j = 0; j < (1 << n); j += i)
      for (k = 0; k < i / 2; k++) {
        x = a[j + k], y = a[j + k + i / 2];
        a[j + k] = (x + y >= mo ? x + y - mo : x + y);
        a[j + k + i / 2] = (x - y < 0 ? x - y + mo : x - y);
      }
  for (i = 0; i < (1 << n); i++) a[i] = (1LL * a[i] * a[i]) % mo;
  for (i = 2; i <= (1 << n); i <<= 1)
    for (j = 0; j < (1 << n); j += i)
      for (k = 0; k < i / 2; k++) {
        x = a[j + k], y = a[j + k + i / 2];
        a[j + k] = (x + y >= mo ? x + y - mo : x + y);
        a[j + k + i / 2] = (x - y < 0 ? x - y + mo : x - y);
      }
  x = fpm(1 << n, mo - 2);
  for (i = 0; i < (1 << n); i++) a[i] = (1LL * a[i] * x) % mo;
  for (i = 0; i < (1 << n); i++) ans = (ans + 1LL * a[i] * c[i]) % mo;
  ans = (3LL * ans) % mo;
  cout << ans;
  return 0;
}
