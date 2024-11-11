#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void solve() {
  vector<int> a(3);
  for (int i = 0; i < 3; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  cout << (a[2] <= a[0] + a[1] ? "Yes\n" : "No\n");
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
