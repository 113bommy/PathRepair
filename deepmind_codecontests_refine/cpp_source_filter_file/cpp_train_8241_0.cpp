#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= 9; ++i)
      ans += (n - m * i + m * 10) / m * 10 * (m * i % 10);
    cout << ans << "\n";
  }
  return 0;
}
