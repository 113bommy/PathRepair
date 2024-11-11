#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (n + m - 2 < k) {
    cout << -1 << endl;
    return 0;
  }
  long long res = 0;
  int target_y = n;
  while (target_y > 1) {
    int y_cnt = n / target_y - 1;
    target_y = n / (y_cnt + 1);
    int new_target_y = n / (n / target_y + 1);
    int target_x = m / max(1, k - y_cnt + 1);
    res = max(res, target_y * (long long)target_x);
    target_y = new_target_y;
  }
  cout << res << endl;
  return 0;
}
