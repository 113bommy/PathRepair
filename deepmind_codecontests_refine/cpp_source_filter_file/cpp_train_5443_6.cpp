#include <bits/stdc++.h>
using namespace std;
using pi = pair<long long, long long>;
using vi = vector<long long>;
using li = vector<long long>;
using vvi = vector<vector<long long> >;
const long long p = 1e9 + 7;
const double PI = acos(-1);
void solve() {
  long long l, r;
  cin >> l >> r;
  if (r % (2 * l) >= l)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
