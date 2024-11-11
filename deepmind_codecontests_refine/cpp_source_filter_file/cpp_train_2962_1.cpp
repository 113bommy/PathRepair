#include <bits/stdc++.h>
using namespace std;
int n, m;
int x[1500];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  double ans = 0;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    ans = max(ans, 1.0 * x[a] + x[b] / c);
  }
  cout << fixed << setprecision(11) << ans;
  return 0;
}
