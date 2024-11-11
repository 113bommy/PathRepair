#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<ll>;
using VB = vector<bool>;
using V2I = vector<VI>;
using V3I = vector<V2I>;
const ll mod{(ll)1e9 + 7};
const long double pi = 2 * acos(0.0);
void solve() {
  string s, t;
  cin >> s >> t;
  if ((ll)s.size() != (ll)t.size()) {
    cout << "NO";
    return;
  }
  if (s == t) {
    cout << "YES";
    return;
  }
  ll oneS{}, oneT{};
  for (char c : s) oneS += (c == '1');
  for (char c : t) oneT += (c == '1');
  if (!oneS && !oneT) {
    cout << "NO";
  } else
    cout << "YES";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
