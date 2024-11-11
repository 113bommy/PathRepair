#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int main() {
  cin >> n >> m >> k;
  if (m <= k) {
    cout << 1;
    return 0;
  }
  double ans = 1;
  for (int i = 0; i <= k; i++) ans *= 1.0 * (m - k + i) / (n + 1 + i);
  cout << max(0.0, 1.0 - ans);
  return 0;
}
