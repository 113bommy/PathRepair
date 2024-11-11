#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void solve() {
  long long int n, k;
  cin >> n >> k;
  long long int ans = 0;
  if (n <= k) {
    ans = (n * (n - 1)) / 2;
    ans += 1;
  } else {
    ans = (k * (k + 1)) / 2;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
