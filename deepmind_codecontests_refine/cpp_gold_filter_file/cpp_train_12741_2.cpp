#include <bits/stdc++.h>
using namespace std;
const int maxN = 100009;
int mu[maxN];
int n, m, W, H, special;
int xx, yy, a, b;
void readf() {
  scanf("%d%d", &n, &m);
  scanf("%d%d", &xx, &yy);
  scanf("%d%d", &a, &b);
}
long long discal(int x, int y, int u, int v) {
  return (long long)(x - u * 2) * (x - u * 2) +
         (long long)(y - v * 2) * (y - v * 2);
}
int ternary_search(int l, int r, int x1, int y1) {
  int res = 1000000001;
  long long minf = 1e19;
  if (discal(x1 + l * 2, y1, xx, yy) < minf)
    minf = discal(x1 + l * 2, y1, xx, yy), res = l;
  else if (discal(x1 + l * 2, y1, xx, yy) == minf)
    minf = discal(x1 + l * 2, y1, xx, yy), res = min(res, l);
  if (discal(x1 + r * 2, y1, xx, yy) < minf)
    minf = discal(x1 + r * 2, y1, xx, yy), res = r;
  else if (discal(x1 + r * 2, y1, xx, yy) == minf)
    minf = discal(x1 + r * 2, y1, xx, yy), res = min(res, r);
  while (r - l > 2) {
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    long long f1 = discal(x1 + m1 * 2, y1, xx, yy);
    long long f2 = discal(x1 + m2 * 2, y1, xx, yy);
    if (f1 <= f2) {
      r = m2;
      if (f1 < minf)
        minf = f1, res = m1;
      else if (f1 == minf)
        minf = f1, res = min(res, m1);
    } else {
      l = m1;
      if (f2 < minf)
        minf = f2, res = m2;
      else if (f2 == minf)
        minf = f2, res = min(res, m2);
    }
  }
  if (discal(x1 + l * 2, y1, xx, yy) < minf)
    minf = discal(x1 + l * 2, y1, xx, yy), res = l;
  else if (discal(x1 + l * 2, y1, xx, yy) == minf)
    minf = discal(x1 + l * 2, y1, xx, yy), res = min(res, l);
  if (r - l == 1 && discal(x1 + l * 2 + 2, y1, xx, yy) < minf)
    minf = discal(x1 + l * 2 + 2, y1, xx, yy), res = l + 1;
  else if (r - l == 1 && discal(x1 + l * 2 + 2, y1, xx, yy) == minf)
    minf = discal(x1 + l * 2 + 2, y1, xx, yy), res = min(res, l + 1);
  if (discal(x1 + r * 2, y1, xx, yy) < minf)
    minf = discal(x1 + r * 2, y1, xx, yy), res = r;
  else if (discal(x1 + r * 2, y1, xx, yy) == minf)
    minf = discal(x1 + r * 2, y1, xx, yy), res = min(res, r);
  return res;
}
int ternary_search2(int l, int r, int x1, int y1) {
  int res = 1000000001;
  long long minf = 1e19;
  if (discal(x1, y1 + l * 2, xx, yy) < minf)
    minf = discal(x1, y1 + l * 2, xx, yy), res = l;
  else if (discal(x1, y1 + l * 2, xx, yy) == minf)
    minf = discal(x1, y1 + l * 2, xx, yy), res = min(res, l);
  if (discal(x1, y1 + r * 2, xx, yy) < minf)
    minf = discal(x1, y1 + r * 2, xx, yy), res = r;
  else if (discal(x1, y1 + r * 2, xx, yy) == minf)
    minf = discal(x1, y1 + r * 2, xx, yy), res = min(res, r);
  while (r - l > 2) {
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    long long f1 = discal(x1, y1 + m1 * 2, xx, yy);
    long long f2 = discal(x1, y1 + m2 * 2, xx, yy);
    if (f1 <= f2) {
      r = m2;
      if (f1 < minf)
        minf = f1, res = m1;
      else if (f1 == minf)
        res = min(res, m1);
    } else {
      l = m1;
      if (f2 < minf)
        minf = f2, res = m2;
      else if (f2 == minf)
        minf = f2, res = min(res, m2);
    }
  }
  if (discal(x1, y1 + l * 2, xx, yy) < minf)
    minf = discal(x1, y1 + l * 2, xx, yy), res = l;
  else if (discal(x1, y1 + l * 2, xx, yy) == minf)
    minf = discal(x1, y1 + l * 2, xx, yy), res = min(res, l);
  if (r - l == 1 && discal(x1, y1 + l * 2 + 2, xx, yy) < minf)
    minf = discal(x1, y1 + l * 2 + 2, xx, yy), res = l + 1;
  else if (r - l == 1 && discal(x1, y1 + l * 2 + 2, xx, yy) == minf)
    minf = discal(x1, y1 + l * 2 + 2, xx, yy), res = min(res, l + 1);
  if (discal(x1, y1 + r * 2, xx, yy) < minf)
    minf = discal(x1, y1 + r * 2, xx, yy), res = r;
  else if (discal(x1, y1 + r * 2, xx, yy) == minf)
    minf = discal(x1, y1 + r * 2, xx, yy), res = min(res, r);
  return res;
}
void prime_distribute(int x, int k) {
  int N = trunc(sqrt(x));
  for (int i = 2; i <= N; i++) {
    while (x % i == 0) x = x / i, mu[i] += k;
  }
  if (special == 0)
    special = x;
  else if (special == x)
    special = 1;
}
void process() {
  int i, j;
  prime_distribute(a, 1);
  prime_distribute(b, -1);
  long long tmp = special;
  for (i = 2; i < maxN; i++)
    for (j = 1; j <= mu[i]; j++) tmp = tmp * i;
  int t = min(trunc(m / ((tmp * b) / a)), trunc(n / tmp));
  W = tmp * t;
  H = (tmp * b * t) / a;
  int x1 = 0, y1 = 0, x2 = W, y2 = H;
  int deltaX = ternary_search(0, n - x2, x2, y2);
  int deltaY = ternary_search2(0, m - y2, x2, y2);
  printf("%d %d %d %d", deltaX, deltaY, x2 + deltaX, y2 + deltaY);
}
int main() {
  readf();
  process();
}
