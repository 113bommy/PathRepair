#include <bits/stdc++.h>
using namespace std;
int main() {
  int num_test_cases;
  cin >> num_test_cases;
  for (int tc = 0; tc < num_test_cases; tc++) {
    int n;
    cin >> n;
    long long ans = 0;
    for (long long i = 1; i <= n; i += 2) ans += (4 * (i - 1)) * (i / 2);
    cout << ans << '\n';
  }
  return 0;
}
