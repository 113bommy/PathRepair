#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x;
  char c;
  int f = 1;
  while ((c = getchar()) != '-' && (c < '0' || c > '9'))
    ;
  if (c == '-') c = getchar(), f = -1;
  x = c ^ '0';
  while ((c = getchar()) >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ '0');
  return x * f;
}
inline long long readll() {
  long long x;
  char c;
  long long f = 1;
  while ((c = getchar()) != '-' && (c < '0' || c > '9'))
    ;
  if (c == '-') c = getchar(), f = -1;
  x = c ^ '0';
  while ((c = getchar()) >= '0' && c <= '9')
    x = (x << 1ll) + (x << 3ll) + (c ^ '0');
  return x * f;
}
inline bool chkmax(int &x, int y) { return (y > x) ? (x = y, 1) : 0; }
inline bool chkmin(int &x, int y) { return (y < x) ? (x = y, 1) : 0; }
const int maxn = 1e5 + 10;
struct point {
  double x, y;
  int sum, w, id;
} a[maxn], b[maxn];
const double eps = 1e-15;
bool check(double x) { return fabs(x) <= eps; }
bool cmpx(const point A, const point B) {
  if (!check(A.x - B.x)) return A.x < B.x;
  return A.y > B.y;
}
bool cmpy(const point A, const point B) {
  if (!check(A.y - B.y)) return A.y < B.y;
}
int n;
long long ans;
void cdq(int L, int R) {
  if (L >= R) return;
  int Mid = (L + R) >> 1;
  cdq(L, Mid), cdq(Mid + 1, R);
  sort(a + L, a + Mid + 1, cmpy), sort(a + Mid + 1, a + R + 1, cmpy);
  int j = L, num = 0;
  for (int i = Mid + 1; i <= R; ++i) {
    while (j <= Mid && a[j].y < a[i].y && !check(a[j].y - a[i].y)) ++num, ++j;
    a[i].sum += Mid - L + 1 - num;
  }
  j = Mid;
  num = 0;
  for (int i = R; i > Mid; --i) {
    while (j >= L && a[j].y >= a[i].y) ++num, --j;
    a[i].sum += num;
  }
}
int main() {
  n = read();
  int m = read();
  for (register int i = 1, iend = n; i <= iend; ++i) {
    int x = read(), v = read();
    b[i].x = (v - m) * 1.0 / x, b[i].y = (v + m) * 1.0 / x;
    b[i].id = i;
  }
  sort(b + 1, b + n + 1, cmpx);
  m = n;
  n = 0;
  for (int i = 1, j = 1; i <= m; i = j + 1, ++j) {
    while (j < m && check(b[j + 1].x - b[i].x) && check(b[j + 1].y - b[i].y))
      ++j;
    a[++n] = b[i];
    a[n].w = j - i + 1;
    a[n].sum = 0;
  }
  sort(a + 1, a + n + 1, cmpx);
  cdq(1, n);
  for (register int i = 1, iend = n; i <= iend; ++i)
    ans += 1ll * (a[i].w - 1 + a[i].sum) * a[i].w / 2;
  printf("%lld\n", ans);
  return 0;
}
