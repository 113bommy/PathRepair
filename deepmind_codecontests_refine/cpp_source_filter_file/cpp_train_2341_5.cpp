#include <bits/stdc++.h>
using namespace std;
const int Q = 1 << 20;
int n, m;
void gg() {
  puts("NO");
  exit(0);
}
struct cer {
  long long t, x, mt, dv;
};
bool operator<(cer a, cer b) { return a.mt < b.mt; }
struct dt {
  long long xx[Q], tt[Q];
  int ans[Q];
  cer a[Q];
  bool OK(long long sm) {
    a[n + 1] = (cer){m, sm, m, 0};
    for (int i = 1; i <= n + 1; i++) {
      long long del = a[i].x - a[i - 1].x - (a[i].dv - a[i - 1].dv) * sm;
      if (del < -1e9 || del > 1e9 || labs(del) > a[i].mt - a[i - 1].mt)
        return 0;
      if ((labs(del) & 1) != ((a[i].mt - a[i - 1].mt) & 1)) return 0;
      if (del > 0)
        for (int j = 1; j <= del; j++) ans[a[i - 1].mt + j] = 1;
      else
        for (int j = 1; j <= -del; j++) ans[a[i - 1].mt + j] = -1;
      for (int j = labs(del) + 1; j <= a[i].mt - a[i - 1].mt; j++)
        ans[a[i - 1].mt + j] = (j & 1) ? 1 : -1;
    }
    return 1;
  }
  void init() {
    for (int i = 1; i <= n; i++)
      a[i] = (cer){tt[i], xx[i], tt[i] % m, tt[i] / m};
    a[0] = (cer){0, 0, 0, 0};
    sort(a, a + n + 1);
    for (int i = 1; i <= n; i++)
      if (a[i].mt == a[i - 1].mt) {
        long long b = a[i].dv - a[i - 1].dv, d = a[i].x - a[i - 1].x;
        if (d % b) gg();
        if (!OK(d / b)) gg();
        return;
      }
    a[n + 1] = (cer){0, 0, m, -1};
    long long L = -m, R = m;
    for (int i = 1; i <= n + 1; i++) {
      long long d = a[i].dv - a[i - 1].dv;
      if (!d) {
        long long v = a[i].x - a[i - 1].x;
        if (v < -1e9 || v > 1e9 || labs(v) > a[i].mt - a[i - 1].mt) gg();
        if ((labs(v) & 1) != ((a[i].mt - a[i - 1].mt) & 1)) gg();
        continue;
      }
      long long l = a[i].x - a[i - 1].x - (a[i].mt - a[i - 1].mt),
                r = a[i].x - a[i - 1].x + (a[i].mt - a[i - 1].mt);
      if (d < 0) swap(l, r), l = -l, r = -r, d = -d;
      if (l >= 0)
        L = max(L, (l + d - 1) / d);
      else
        L = max(L, l / d);
      if (r >= 0)
        R = min(R, r / d);
      else
        R = min(R, (r - d + 1) / d);
    }
    if (L > R) gg();
    if (!OK(L)) {
      if (L == R) gg();
      if (!OK(L + 1)) gg();
    }
  }
} px, py;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    long long t, x, y;
    scanf("%lld%lld%lld", &t, &x, &y);
    px.xx[i] = x + y, py.xx[i] = x - y;
    px.tt[i] = py.tt[i] = t;
  }
  px.init(), py.init();
  for (int i = 1; i <= m; i++)
    if (px.ans[i] == 1)
      if (py.ans[i] == 1)
        putchar('R');
      else
        putchar('U');
    else if (py.ans[i] == 1)
      putchar('D');
    else
      putchar('L');
  return 0;
}
