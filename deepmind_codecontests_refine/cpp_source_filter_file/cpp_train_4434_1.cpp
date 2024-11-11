#include <bits/stdc++.h>
using namespace std;
int st(int x, int pos) { return x = x | (1 << pos); }
int Reset(int x, int pos) { return x = x & ~(1 << pos); }
long long x[200006], xx[200006], xc[200006], y[200006], yy[200006], yc[200006];
int main() {
  long long n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &x[i]);
    scanf("%lld", &y[i]);
    xx[i] += x[i] * x[i] + xx[i - 1];
    yy[i] += y[i] * y[i] + yy[i - 1];
    xc[i] += xc[i - 1];
    xc[i] += x[i];
    yc[i] += yc[i - 1];
    yc[i] += y[i];
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (i - 1) * x[i] * x[i] - 2 * x[i] * xc[i - 1] + xx[i - 1];
    ans += (i - 1) * x[i] * x[i] - 2 * x[i] * xc[i - 1] + yy[i - 1];
  }
  cout << ans << endl;
}
