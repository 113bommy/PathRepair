#include <bits/stdc++.h>
using namespace std;
const int maxN = 100 + 10;
const int maxM = 100000 + 10;
inline void smax(long double& a, long double b) { a = max(a, b); }
long double a[maxN];
long double z[maxN], lz[maxN], rz[maxN];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n, greater<int>());
  for (int i = 0; i < n; i++) {
    a[i] /= 100.l;
    z[i] = 1;
  }
  long double ans = 0;
  lz[0] = rz[n - 1] = 1;
  long double last = 0;
  for (int i = 1; i < maxM; i++) {
    for (int j = 0; j < n; j++) lz[j + 1] = lz[j] * (1 - z[j]);
    for (int j = n - 1; j > 0; j--) rz[j - 1] = rz[j] * (1 - z[j]);
    pair<long double, int> mx = {0, 0};
    for (int i = 0; i < n; i++)
      mx = max(mx,
               pair<long double, int>(lz[i] * (1 - z[i] * (1 - a[i])) * rz[i],
                                      (z[i] == 1) * n + i));
    ans += (mx.first - last) * i;
    last = mx.first;
    mx.second %= n;
    z[mx.second] *= 1 - a[mx.second];
  }
  cout << fixed << setprecision(9) << ans << endl;
}
