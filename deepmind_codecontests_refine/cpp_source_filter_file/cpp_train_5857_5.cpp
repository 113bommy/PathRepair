#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, k, ans;
  cin >> n >> k;
  if (n > k) {
    ans = (k * (k - 1)) / 2;
  } else {
    ans = (n * (n - 1)) / 2;
  }
  cout << ans << endl;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
