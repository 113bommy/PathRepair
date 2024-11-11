#include <bits/stdc++.h>
using namespace std;
struct cor {
  int x, y;
} a[201000];
int n, b[101000], m, c[201000], last, cnt, ansc;
long long ans, f[201000];
bool cmp(cor a, cor b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].x), a[i].y = i;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i + n].x), a[i + n].y = i;
  sort(&a[1], &a[n + n + 1], cmp);
  scanf("%I64d", &m);
  ans = 1LL;
  last = 1;
  f[1] = 1;
  for (int i = 2; i <= n + n; i++) {
    int tmp = i;
    c[i] = c[i - 1];
    while (tmp % 2 == 0) c[i]++, tmp /= 2;
    f[i] = (f[i - 1] * tmp) % m;
  }
  for (int i = 2; i <= n + n + 1; i++) {
    if (a[i].x > a[i - 1].x || i > n + n) {
      (ans *= f[i - last]) %= m;
      ansc += c[i - last];
      ansc -= cnt;
      cnt = 0;
      last = i;
    } else if (a[i].x == a[i - 1].x && a[i].y == a[i - 1].y)
      cnt++;
  }
  for (int i = 1; i <= ansc; i++) (ans *= 2) %= m;
  printf("%I64d\n", ans);
  return 0;
}
