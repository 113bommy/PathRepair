#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int n, k;
  cin >> n >> k;
  long long int l = 1;
  long long int r = (1 * 1ll << n) - 1;
  long long int ans = n;
  while (l <= r) {
    long long int m = l + (r - l) / 2;
    if (m == k) {
      break;
    }
    ans--;
    if (m > k) {
      r = m - 1;
    } else if (k > m) {
      l = m + 1;
    }
  }
  cout << ans << endl;
}
