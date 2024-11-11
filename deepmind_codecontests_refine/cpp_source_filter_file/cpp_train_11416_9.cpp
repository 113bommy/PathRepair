#include <bits/stdc++.h>
using namespace std;
struct md {
  int v;
  md(int _v = 0) { v = _v; }
  void operator+=(md a) { v = (0LL + v + a.v) % 1000000007; }
  void operator*=(md a) { v = (1LL * v * a.v) % 1000000007; }
};
md operator+(md a, md b) { return md((0LL + a.v + b.v) % 1000000007); }
md operator-(md a, md b) {
  return md((0LL + a.v - b.v + 1000000007) % 1000000007);
}
md operator*(md a, md b) { return md(1LL * a.v * b.v % 1000000007); }
md bigmod(md b, int i) {
  md r(1);
  for (int j = (29); j >= (0); j--) {
    r *= r;
    if ((i >> j) & 1) r *= b;
  }
  return r;
}
md num[5005];
md ppdt[5005], inv[5005];
md ans[10005];
int main() {
  int n;
  scanf("%d", &n);
  num[0] = ppdt[0] = inv[0] = num[1] = ppdt[1] = inv[1] = md(1);
  for (int i = (2); i <= (n); i++) {
    int t;
    scanf("%d", &t);
    num[i] = md(t);
    ppdt[i] = ppdt[i - 1] * num[i];
    inv[i] = bigmod(ppdt[i], 1000000007 - 2);
  }
  int mx = n * 2 - 2;
  for (int i = (0); i <= (n + 1); i++) {
    md tmp(i >= 3);
    for (int j = (1); j <= (mx); j++) {
      int l = i + j - 1;
      int r = i + j + j - 2;
      if (l - 1 < 1) continue;
      if (l - 1 > n) break;
      ans[j] += ppdt[l - 1] * tmp;
      md v;
      if (l <= 1 || r > n)
        v = md(0);
      else {
        ans[j] += ppdt[l - 1] * inv[l - 1] * ppdt[r];
        tmp += inv[l] * ppdt[r] * (num[l] - md(1));
      }
    }
  }
  md inv2 = bigmod(2, 1000000007 - 2);
  for (int i = (1); i <= (mx); i++) {
    ans[i] *= inv2;
    printf("%d%c", ans[i].v, (i == mx) ? '\n' : ' ');
  }
  return 0;
}
