#include <bits/stdc++.h>
using namespace std;
void qmax(int &x, int y) {
  if (x < y) x = y;
}
void qmin(int &x, int y) {
  if (x > y) x = y;
}
inline long long read() {
  char s;
  long long k = 0, base = 1;
  while ((s = getchar()) != '-' && s != EOF && !(isdigit(s)))
    ;
  if (s == EOF) exit(0);
  if (s == '-') base = -1, s = getchar();
  while (isdigit(s)) {
    k = k * 10 + (s ^ '0');
    s = getchar();
  }
  return k * base;
}
inline void write(int x) {
  static char cnt, num[15];
  cnt = 0;
  if (!x) {
    putchar('0');
    return;
  }
  for (; x; x /= 10) num[++cnt] = x % 10;
  for (; cnt; putchar(num[cnt--] + 48))
    ;
}
const int maxn = 1e5 + 200;
int n, s;
struct node {
  long long s, a, b, c;
} a[maxn];
bool cmp(node aa, node bb) { return aa.c < bb.c; }
long long ans, s1, s2, ans2;
int main() {
  n = read();
  s = read();
  for (int i = 1; i <= n; i++) {
    a[i].s = read();
    a[i].a = read();
    a[i].b = read();
    a[i].c = a[i].a - a[i].b;
    if (a[i].a >= a[i].b) {
      s1 += a[i].s;
      ans += (long long)a[i].s * a[i].a;
    } else {
      s2 += a[i].s;
      ans += (long long)a[i].s * a[i].b;
    }
  }
  if ((s1 % s + s2 % s) > s) {
    printf("%lld\n", ans);
    return 0;
  }
  s1 %= s;
  s2 %= s;
  ans2 = ans;
  sort(a + 1, a + n + 1, cmp);
  int p = 1, p1;
  while (a[p].c < 0 && p < n) p++;
  p1 = p;
  while (a[p1].c >= 0 && p1 >= 1) p1--;
  while (s1 > 0) {
    if (s1 - a[p].s < 0) break;
    s1 -= a[p].s;
    ans -= a[p].s * a[p].c;
    p++;
  }
  if (s1 > 0) {
    ans -= a[p].c * s1;
  }
  while (s2 > 0) {
    if (s2 - a[p1].s < 0) break;
    s2 -= a[p1].s;
    ans2 += a[p1].s * a[p1].c;
    p1--;
  }
  if (s2 > 0) {
    ans2 += a[p1].c * s2;
    s2 = 0;
  }
  ans = max(ans, ans2);
  printf("%lld\n", ans);
  return 0;
}
