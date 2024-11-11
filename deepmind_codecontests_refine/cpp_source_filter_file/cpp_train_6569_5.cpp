#include <bits/stdc++.h>
using namespace std;
char rd;
int pn;
template <typename Type>
inline void read(Type& v) {
  pn = 1;
  while ((rd = getchar()) < '0' || rd > '9')
    if (rd == '-') pn = -1;
  v = rd - '0';
  while ((rd = getchar()) >= '0' && rd <= '9') v = v * 10 + rd - '0';
  v *= pn;
}
template <typename Type>
inline void out(Type v, bool c = 1) {
  if (v == 0)
    putchar(48);
  else {
    if (v < 0) {
      putchar('-');
      v = -v;
    }
    int len = 0, dg[20];
    while (v > 0) {
      dg[++len] = v % 10;
      v /= 10;
    }
    for (int i = len; i >= 1; i--) putchar(dg[i] + 48);
  }
  if (c)
    putchar('\n');
  else
    putchar(' ');
}
const int MAXN = 200005;
struct P {
  int l, r;
  bool operator<(const P& t) const { return l < t.l; }
} a[MAXN];
long long s[MAXN];
long long n, h;
void init() {
  read(n);
  read(h);
  for (int i = 1; i <= n; i++) {
    read(a[i].l);
    read(a[i].r);
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i].r - a[i].l;
  s[n + 1] = s[n];
}
bool check(int xx, int yy) {
  return h > (a[yy].l - a[xx].l) - (s[yy - 1] - s[xx - 1]);
}
long long doit(int k) {
  int l = k + 1, r = n;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check(k, mid))
      l = mid;
    else
      r = mid - 1;
  }
  return h + s[l] - s[k - 1];
}
long long ans;
void work() {
  for (int i = 1; i <= n; i++) ans = max(ans, doit(i));
  out(ans);
}
int main() {
  init();
  work();
  return 0;
}
