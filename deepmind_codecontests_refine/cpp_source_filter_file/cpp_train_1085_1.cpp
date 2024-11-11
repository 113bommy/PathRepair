#include <bits/stdc++.h>
using namespace std;
int n, first, m, second;
int main() {
  cin >> n >> first >> m >> second;
  second = abs(second - first);
  long long ans = 1;
  for (int i = 1; i <= m; ++i)
    if (i + second >= n) ++ans;
  for (int i = 1; i <= n; ++i) {
    if (i + m > second && i < second + 1) {
      int high = min(m, second + i - 1);
      int low = second - i + 1;
      ans += 2 * (high - low + 1) - 1;
    } else if (i + m > second && i < second + m) {
      int high = min(m, second + i);
      int low = i - second;
      ans += 2 * (high - low + 1) - 1;
    }
    ++ans;
  }
  cout << ans << endl;
}
