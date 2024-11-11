#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
struct A {
  double x, y;
  long long a, b;
} a[N];
long long tr[N], n;
bool cmp(A x, A y) { return x.x < y.x; }
bool tmp(A x, A y) { return x.y < y.y; }
void ins(long long x) {
  while (x <= n) {
    tr[x]++;
    x += (x & -x);
  }
}
long long gt(long long x) {
  long long ret = 0;
  while (x) {
    ret += tr[x];
    x -= (x & -x);
  }
  return ret;
}
long long ask(long long x, long long y) { return gt(y) - gt(x - 1); }
int main() {
  long long p;
  scanf("%I64d%I64d", &n, &p);
  double m = p + 0.000005;
  for (long long i = 1; i <= n; i++) {
    long long x, y;
    scanf("%I64d%I64d", &x, &y);
    a[i].b = i;
    a[i].x = double(x) / double(double(y) - m);
    a[i].y = double(x) / double(double(y) + m);
  }
  sort(a + 1, a + n + 1, cmp);
  for (long long i = 1; i <= n; i++) a[i].a = i;
  sort(a + 1, a + n + 1, tmp);
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    ans += i - 1 - ask(1, a[i].a - 1);
    ins(a[i].a);
  }
  printf("%I64d", ans);
  return 0;
}
