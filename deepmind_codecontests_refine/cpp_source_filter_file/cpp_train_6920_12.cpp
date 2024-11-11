#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, ans = 0;
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    int teams = i;
    int left_exp = n - i;
    int left_new = m - 2 * i;
    if (left_new >= 0) {
      teams += min(left_exp, left_new / 2);
      ans = max(ans, teams);
    }
  }
  cout << ans;
  return 0;
}
