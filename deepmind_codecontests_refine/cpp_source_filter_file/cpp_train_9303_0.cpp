#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (k > 1) {
    m -= (k - 1);
  }
  if (m == 1) {
    cout << 0 << endl;
    return 0;
  }
  sort(a.rbegin(), a.rend());
  int ans = -1;
  int port_sum = 0;
  for (int num = 0; num < n; ++num) {
    port_sum += a[num];
    if ((port_sum - num) >= m) {
      ans = num + 1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
