#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  if (k >= n / 2) {
    cout << 1LL * n * (n - 1) / 2 << "\n";
    return 0;
  }
  long long ans = 1LL * 2 * k * (2 * k - 1) / 2;
  ans += 1LL * 2 * k * (n - 2 * k);
  cout << ans << "\n";
  return 0;
}
