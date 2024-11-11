#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, m;
  cin >> n >> m;
  double ans = 2e9, x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    ans = min(ans, x / y);
  }
  cout << fixed << setprecision(8) << ans * m;
}
