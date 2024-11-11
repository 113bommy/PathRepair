#include <bits/stdc++.h>
using namespace std;
long long n, m, k, ans, lr[2000000];
struct arr {
  long long x, y;
} a[2000000];
bool cmp(arr x, arr y) { return x.x < y.x; }
int main() {
  scanf("%lld%lld%lld", &n, &k, &m);
  for (int i = 1; i <= m; i++) scanf("%lld%lld", &a[i].x, &a[i].y);
  ++m;
  a[m] = {0, 0};
  ++m;
  a[m] = {n, 0};
  sort(a + 1, a + m + 1, cmp);
  for (int i = 1; i < m; i++)
    if (a[i + 1].x - a[i].x > k) {
      puts("-1");
      return 0;
    }
  long long l = 1, r = 1, j = 0;
  for (int i = 1; i <= m; i++) {
    while (l < r && a[lr[l]].x + k < a[i].x) {
      ans += (a[lr[l]].x + n - j) * a[lr[l]].y;
      j = a[lr[l]].x + k;
      ++l;
    }
    ans += (a[i].x - j) * a[lr[l]].y;
    j = a[i].x;
    while (l < r && a[lr[r - 1]].y > a[i].y) --r;
    lr[r++] = i;
  }
  printf("%lld", ans);
}
