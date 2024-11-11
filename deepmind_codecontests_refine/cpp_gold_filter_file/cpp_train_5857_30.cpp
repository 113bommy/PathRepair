#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, r;
    cin >> n >> r;
    long long ans = 1;
    if (r >= n) {
      ans += 1LL * (n - 1) * n / 2;
    } else {
      n = r + 1;
      ans += 1LL * (n - 1) * n / 2;
      ans--;
    }
    cout << ans << endl;
  }
  return 0;
}
