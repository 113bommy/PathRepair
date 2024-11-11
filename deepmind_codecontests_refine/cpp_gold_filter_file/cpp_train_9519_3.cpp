#include <bits/stdc++.h>
using namespace std;
long long int depth = 0;
int32_t main() {
  long long int c, d, n, m, k;
  cin >> c >> d >> n >> m >> k;
  if (n * m <= k) {
    cout << 0 << endl;
    return 0;
  }
  long long int x = n * m - k;
  long long int cost[x + 1];
  cost[0] = 0;
  for (long long int i = 1; i <= x; i++) {
    if (i >= n) {
      cost[i] = min(cost[i - n] + c, cost[i - 1] + d);
    } else {
      cost[i] = min(cost[i - 1] + d, c);
    }
  }
  cout << cost[x] << endl;
  return 0;
}
