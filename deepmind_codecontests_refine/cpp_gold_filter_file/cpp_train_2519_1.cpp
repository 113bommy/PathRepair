#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  long long div = d / c;
  d -= (c * min(a, div));
  if (b >= d)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  for (cin >> t; t; t--) solve();
}
