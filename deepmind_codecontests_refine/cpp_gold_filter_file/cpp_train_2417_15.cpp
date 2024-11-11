#include <bits/stdc++.h>
const int N = 6000;
long long ans;
int n;
long long C(int x, int y) {
  long long ans = 1;
  if (y > x) return 0;
  for (int i = x; i > x - y; i--) ans = ans * i;
  for (int i = 2; i <= y; i++) ans /= i;
  return ans;
}
struct point {
  int x, y;
  friend long long operator*(point x, point y) {
    return (long long)x.x * y.y - (long long)x.y * y.x;
  }
  friend point operator-(point x, point y) { return {x.x - y.x, x.y - y.y}; }
} a[N], b[N];
bool cmp(point x, point y) {
  int typex = (x.y < 0 || (x.y == 0 && x.x < 0));
  int typey = (y.y < 0 || (y.y == 0 && y.x < 0));
  return typex == typey ? x * y > 0 : typex < typey;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].x, &a[i].y);
  long long ans = C(n, 5) * 5;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++)
      if (i != j) b[++cnt] = a[j] - a[i];
    std::sort(b + 1, b + n, cmp);
    for (int j = 1, p = 0; j <= cnt; j++) {
      b[cnt + j] = b[j];
      if (p <= j) p = j + 1;
      while (b[p] * b[j] < 0 && p <= cnt + j) p++;
      ans = ans - C(cnt + j - p, 3);
    }
  }
  printf("%lld\n", ans);
}
