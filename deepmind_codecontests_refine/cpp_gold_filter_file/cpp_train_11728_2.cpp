#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:536870912")
#pragma warning(disable : 4996)
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int N = 2e5 + 100;
int a[N], p[N];
int main() {
  int n, d, b;
  scanf("%d%d%d", &n, &d, &b);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    p[i + 1] = p[i] + a[i];
  }
  int m = n / 2;
  if (n % 2 == 0) m--;
  int z = 0, x = 0, y = 0, t = d;
  for (int i = 0; i <= m; i++, t = min(t + d, n - 1 - i)) {
    if (a[i] + z < b) {
      if (p[t + i + 1] - p[i] + z < b)
        z += a[i], x++;
      else {
        z -= b - a[i];
      }
    } else {
      z += a[i] - b;
    }
  }
  z = 0;
  t = d;
  for (int i = n - 1; i > m; i--, t = min(t + d, i)) {
    if (a[i] + z < b) {
      if (p[i + 1] - p[i - t] + z < b)
        z += a[i], y++;
      else {
        z -= b - a[i];
      }
    } else {
      z += a[i] - b;
    }
  }
  printf("%d", max(x, y));
  return 0;
}
