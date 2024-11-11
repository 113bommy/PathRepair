#include <bits/stdc++.h>
using namespace std;
void solve() {
  int x = 0, y = 0;
  set<pair<int, int> > x1, y1;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'N') {
      y++;
      x1.insert(make_pair(x, y));
    } else if (s[i] == 'S') {
      y--;
      x1.insert(make_pair(x, y + 1));
    } else if (s[i] == 'W') {
      x++;
      y1.insert(make_pair(x, y));
    } else if (s[i] == 'E') {
      x--;
      y1.insert(make_pair(x + 1, y));
    }
  }
  int ans = x1.size() + y1.size();
  cout << ans * 5 + (s.size() - ans) << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
