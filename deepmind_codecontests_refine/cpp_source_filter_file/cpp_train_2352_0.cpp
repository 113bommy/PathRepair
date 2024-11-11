#include <bits/stdc++.h>
using namespace std;
int n, m, k, x;
int main() {
  int res = 1e7;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    if (x > 0 && x < k) res = min(res, abs((m - i) * 10));
  }
  cout << res << endl;
  return 0;
}
