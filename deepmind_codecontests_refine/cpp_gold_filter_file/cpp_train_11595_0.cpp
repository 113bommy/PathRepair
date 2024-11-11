#include <bits/stdc++.h>
using namespace std;
long long tmp[10];
struct Bigint {
  const static int maxn = 10;
  const static int Base = (int)1e5;
  int a[maxn];
  int n;
  Bigint(long long x = 0) {
    n = 0;
    for (; x; x /= Base) a[n++] = x % Base;
  }
  void operator+=(const Bigint &b) {
    for (; n < b.n; a[n++] = 0)
      ;
    for (int i = 0; i < b.n; i++) a[i] += b.a[i];
    for (int i = 0; i < n; i++)
      if (a[i] >= Base) {
        a[i] -= Base;
        if (i == n - 1)
          a[n++] = 1;
        else
          a[i + 1]++;
      }
  }
  void operator-=(const Bigint &b) {
    assert(n >= b.n);
    for (int i = 0; i < b.n; i++) a[i] -= b.a[i];
    for (int i = 0; i < n; i++)
      if (a[i] < 0) {
        a[i] += Base;
        a[i + 1]--;
      }
    for (; n && !a[n - 1]; --n)
      ;
  }
  void operator*=(const Bigint &b) {
    if (!n || !b.n) {
      n = 0;
      return;
    }
    memset(tmp, 0, sizeof(tmp[0]) * (n + b.n + 1));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < b.n; j++) tmp[i + j] += (long long)a[i] * b.a[j];
    n = n + b.n - 1;
    long long left = 0;
    for (int i = 0; i < n || left; i++) {
      if (i == n) n++;
      left += tmp[i];
      a[i] = left % Base;
      left /= Base;
    }
  }
  void print() const {
    if (n > 2)
      printf("...%05d%05d\n", a[1], a[0]);
    else {
      if (n == 2)
        printf("%d%05d\n", a[1], a[0]);
      else
        printf("%d\n", n ? a[0] : 0);
    }
  }
};
Bigint countFunc(int R, int l, int r) {
  int tmp[3] = {R, R + 1, 2 * R + 1};
  for (int it = 2; it <= 3; it++)
    for (int i = 0; i < 3; i++)
      if (!(tmp[i] % it)) {
        tmp[i] /= it;
        break;
      }
  Bigint r1 = tmp[0];
  r1 *= tmp[1];
  r1 *= tmp[2];
  r1 *= r - l;
  Bigint r2 = (long long)R + 1;
  long long coef = ((long long)r * (r + 1) - (long long)l * (l + 1)) / 2;
  r2 *= abs(coef);
  if (coef >= 0)
    r1 += r2;
  else
    r1 -= r2;
  return r1;
}
Bigint countRect(long long x, long long y) {
  long long tmp = min(x, y) * min(x, y);
  Bigint res = 1;
  for (int it = 0; it < 2; it++, tmp++) res *= ((tmp & 1) ? tmp : tmp / 2);
  if (x > y) {
    res += countFunc(x - 1, 0, y);
    res -= countFunc(y - 1, 0, y);
  }
  if (x < y) {
    res += countFunc(y, -x, 0);
    res -= countFunc(x, -x, 0);
  }
  return res;
}
void solve() {
  int x1, x2, y1, y2;
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  --x1, --y1;
  swap(x1, y1), swap(x2, y2);
  Bigint res = countRect(x2, y2);
  res += countRect(x1, y1);
  res -= countRect(x1, y2);
  res -= countRect(x2, y1);
  res.print();
}
int main() {
  int t;
  while (scanf("%d", &t) >= 1) {
    for (; t; t--) solve();
  }
  return 0;
}
