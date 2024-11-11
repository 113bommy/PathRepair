#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  for (long long z = 0; z < t; ++z) {
    long long n, k;
    cin >> n >> k;
    int ans = -1;
    if (n <= k) {
      ans = 1;
    } else {
      ans = 1 + (n - 2) / k + ((n - 2) % k != 0);
    }
    cout << ans << "\n";
  }
}
