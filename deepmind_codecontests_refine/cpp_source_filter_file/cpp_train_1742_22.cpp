#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  int end1 = max(0, n - 11);
  int64_t ans = end1 * 49;
  for (int num50 = max(0, n - 11); num50 <= n; ++num50) {
    int left1 = n - num50;
    int max10 = min(left1, 8);
    int max10before5 = min(max10, 4);
    for (int num10 = 0; num10 <= max10before5; ++num10) {
      int max5 = min(left1 - num10, 8);
      ans += max5 + 1;
    }
    ans += max10 - max10before5;
  }
  cout << ans << endl;
  return 0;
}
