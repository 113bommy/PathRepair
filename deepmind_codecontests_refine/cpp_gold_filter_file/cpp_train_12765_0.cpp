#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int inf = 1e9;
int n, S, s, u, v;
struct T {
  long long s, x, y, d;
} a[maxn];
bool operator<(const T x, const T y) { return x.d > y.d; }
int main() {
  scanf("%d %d", &n, &S);
  long long sum = 0, tot = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", &s, &u, &v);
    a[i] = {s, u, v, v - u};
    sum += 1LL * u * s;
    tot += s;
  }
  sort(a + 1, a + 1 + n);
  long long x = 0, y = 0, ans = sum, free = ((tot + S - 1) / S * S) - tot;
  for (int i = 1; i <= n; i++) {
    if (a[i].d <= 0) break;
    x += a[i].s;
    y += a[i].d * a[i].s;
    if (a[i + 1].d > 0) continue;
    long long temp = x / S * S, det = x - temp;
    long long x2 = 0, y2 = 0;
    for (int j = 1; j <= i; j++) {
      x2 += a[j].s, y2 += a[j].d * a[j].s;
      if (x2 >= temp) {
        y2 -= a[j].d * (x2 - temp);
        break;
      }
    }
    ans = max(ans, sum + y2);
    if (temp == ((tot + S - 1) / S * S)) break;
    temp += S, det = temp - x;
    det = max(det - free, 0LL);
    if (a[i + 1].d <= 0) {
      long long x1 = 0, y1 = 0;
      int j;
      for (j = i + 1; j <= n; j++) {
        x1 += a[j].s, y1 += a[j].d * a[j].s;
        if (x1 >= det) {
          y1 -= a[j].d * (x1 - det);
          break;
        }
      }
      ans = max(ans, sum + y + y1);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
