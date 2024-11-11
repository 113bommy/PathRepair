#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 10;
int main() {
  std::ios::sync_with_stdio(false);
  int n, k, t;
  cin >> n >> k >> t;
  if (t <= k) {
    cout << t << endl;
  } else if (t >= k && t <= n) {
    cout << k << endl;
  } else {
    cout << n + k - t << endl;
  }
  return 0;
}
