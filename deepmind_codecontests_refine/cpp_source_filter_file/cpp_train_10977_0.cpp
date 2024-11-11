#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  double m, n;
  cin >> m >> n;
  double ans = 0;
  for (int i = 1; i <= m; i++)
    ans += i * (pow(1.0 * i / m, n) - pow(1.0 * (i - 1) / m, n));
  cout << fixed << setprecision(10) << m - ans << endl;
  return 0;
}
