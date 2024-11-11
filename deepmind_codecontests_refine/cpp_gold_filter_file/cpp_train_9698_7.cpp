#include <bits/stdc++.h>
using namespace std;
int Int() {
  int x;
  scanf("%d", &x);
  return x;
}
long long Long() {
  long long x;
  scanf("%lld", &x);
  return x;
}
double Double() {
  double x;
  scanf("%lf", &x);
  return x;
}
const int N = 3 * (int)1e5 + 5;
const long long MOD = (int)1e9 + 7;
int Set(int a, int x) { return (a |= (1 << x)); }
int Reset(int a, int x) { return (a &= ~(1 << x)); }
bool Isset(int a, int x) { return (bool)(a & (1 << x)); }
int boy[N];
int girl[N];
int main() {
  int n = Int(), m = Int();
  int bmax = 0, gmin = INT_MAX;
  long long ans = 0LL;
  bool can = false;
  for (int i = 0; i < n; i++) {
    boy[i] = Int();
    ans += (boy[i] * 1LL * m);
    bmax = max(bmax, boy[i]);
  }
  for (int i = 0; i < m; i++) {
    girl[i] = Int();
    gmin = min(gmin, girl[i]);
    if (bmax == girl[i]) can = true;
  }
  if ((bmax > gmin) or ((m == 1) and (gmin != bmax)) or ((n == 1) and (!can)))
    return puts("-1"), 0;
  sort(boy, boy + n, [](int a, int b) { return a > b; });
  sort(girl, girl + m, [](int a, int b) { return a > b; });
  for (int i = 0; i < m; i++) {
    ans += (girl[i] - boy[0]) * 1LL;
  }
  if (bmax != gmin) {
    ans -= (girl[m - 1] - boy[0]) * 1LL;
    ans += (girl[m - 1] - boy[1]) * 1LL;
  }
  cout << ans << '\n';
  return 0;
}
