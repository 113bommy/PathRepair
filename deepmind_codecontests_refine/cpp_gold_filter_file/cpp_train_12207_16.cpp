#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const int MOD = 1e9 + 7;
mt19937_64 azino(777);
void solve() {
  int a;
  cin >> a;
  cout << max(1, (a - (a & 1)) / 2);
}
signed main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(NULL);
  int t = 1;
  cin >> t;
  while (t-- > 0) {
    solve();
    cout << '\n';
  }
  return 0;
}
