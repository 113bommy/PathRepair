#include <bits/stdc++.h>
using namespace std;
void solve(long double pro, long double c, long double m, long double p,
           long double v, long double i) {}
int main() {
  long i, n, m, x, y, j, k = 0, a, b, c = 0, ans = 0;
  cin >> n >> m;
  a = 1;
  for (i = 0; i < m; i++) {
    cin >> b;
    if (b >= a)
      ans += b - a;
    else
      ans += n - (a - b);
    a = b;
  }
  cout << ans;
}
