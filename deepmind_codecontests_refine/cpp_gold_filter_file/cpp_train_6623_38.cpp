#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, k, x, t, ans;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k >> x;
  ans = k * x;
  for (int i = 0; i < n - k; ++i) {
    cin >> t;
    ans += t;
  }
  cout << ans << endl;
  return 0;
}
