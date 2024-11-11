#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
const long long int infP = 1e18;
void solve() {
  string s;
  cin >> s;
  map<pair<long long int, long long int>, long long int> mp;
  long long int x = 0, y = 0;
  mp[{x, y}]++;
  for (auto ss : s) {
    if (ss == 'D')
      y++;
    else if (ss == 'U')
      y--;
    else if (ss == 'L')
      x--;
    else
      x++;
    if (mp[{x, y}] + mp[{x - 1, y}] + mp[{x + 1, y}] + mp[{x, y - 1}] +
            mp[{x, y + 1}] ==
        2) {
      cout << "BUG";
      return;
    }
    mp[{x, y}]++;
  }
  cout << "OK";
}
void debug(long long int tt) {}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
