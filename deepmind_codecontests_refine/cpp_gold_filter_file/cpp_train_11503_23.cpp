#include <bits/stdc++.h>
using namespace std;
template <class T>
T GCD(T a, T b) {
  return b ? GCD(b, a % b) : a;
}
template <class T>
T LCM(T a, T b) {
  return a / GCD(a, b) * b;
}
const int MAXN = 1010;
const int MAXM = 20010;
const double eps = 1e-10;
const double pi = atan(1.0) * 4.0;
int n, m, d, h;
int main() {
  while (cin >> n >> m) {
    int ans = -1, ph, pd, ok = 1;
    for (int i = 1; i <= m; i++) {
      scanf("%d %d", &d, &h);
      if (!ok) continue;
      if (ans == -1) {
        ans = d - 1 + h;
      } else {
        if (fabs(h - ph) > fabs(d - pd)) ok = 0;
        int p = (h - ph + d - pd) / 2;
        ans = max(ans, ph + p);
      }
      pd = d;
      ph = h;
    }
    ans = max(ph + n - pd, ans);
    if (!ok)
      puts("IMPOSSIBLE");
    else
      printf("%d\n", ans);
  }
  return 0;
}
