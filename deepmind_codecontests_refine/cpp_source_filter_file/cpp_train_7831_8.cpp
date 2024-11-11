#include <bits/stdc++.h>
using namespace std;
const long long md = 1e9 + 7;
long long a[1000005], n;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n_tc;
  cin >> n_tc;
  for (int c_tc = 0; c_tc++ < n_tc;) {
    string t;
    cin >> t;
    map<char, int> mp;
    for (int i = 0; i < t.size(); ++i) ++mp[t[i]];
    if (mp.size() == 1)
      cout << t << '\n';
    else {
      for (int i = 0; i < 2 * t.size(); ++i) cout << '0' + i % 2;
      cout << '\n';
    }
  }
}
