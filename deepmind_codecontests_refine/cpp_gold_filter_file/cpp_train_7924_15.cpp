#include <bits/stdc++.h>
using namespace std;
vector<int> vi;
void f(long long int x) {
  if (x > 1e9) return;
  vi.push_back(x);
  f(x * 10 + 4);
  f(x * 10 + 7);
}
long long int f(int vl, int vr, int pl, int pr, int k) {
  long long int ret = 0;
  for (int i = 0; i + k - 1 < (int)vi.size(); i++) {
    int xlow = vl, xhigh, ylow, yhigh = pr;
    if (i) xlow = max(vl, vi[i - 1] + 1);
    xhigh = min(vr, vi[i]);
    ylow = max(pl, vi[i + k - 1]);
    if (i + k < (int)vi.size()) yhigh = min(pr, vi[i + k] - 1);
    if (xlow <= xhigh && ylow <= yhigh)
      ret += max(0ll, 1ll * (xhigh - xlow + 1) * (yhigh - ylow + 1));
  }
  return ret;
}
int main() {
  for (int i = 1; i < 10; i++) {
    for (int j = 0; j < (1 << i); j++) {
      int x = 0;
      for (int k = 0; k < i; k++) {
        x *= 10;
        if (j & (1 << k))
          x += 7;
        else
          x += 4;
      }
      vi.push_back(x);
    }
  }
  sort(vi.begin(), vi.end());
  int vl, vr, pr, pl, k;
  long long int total, x;
  cin >> pl >> pr >> vl >> vr >> k;
  total = (vr - vl + 1ll) * (pr - pl + 1);
  x = f(pl, pr, vl, vr, k) + f(vl, vr, pl, pr, k);
  if (k == 1 && max(pl, vl) <= min(vr, pr))
    x -= (upper_bound(vi.begin(), vi.end(), min(vr, pr)) -
          lower_bound(vi.begin(), vi.end(), max(pl, vl)) + 0.0);
  printf("%.10f\n", (double)x / total);
  return 0;
}
