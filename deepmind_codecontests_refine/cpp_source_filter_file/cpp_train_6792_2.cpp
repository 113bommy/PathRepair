#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int x, y, ans;
    set<pair<pair<int, int>, pair<int, int>>> visited = {
        make_pair(make_pair(0, 0), make_pair(0, 0))};
    x = y = ans = 0;
    for (char c : s) {
      pair<int, int> p = make_pair(x, y);
      if (c == 'S')
        --y;
      else if (c == 'N')
        ++y;
      else if (c == 'W')
        --x;
      else
        ++x;
      if (visited.find(make_pair(p, make_pair(x, y))) != visited.end() ||
          visited.find(make_pair(make_pair(y, x), p)) != visited.end())
        ans++;
      else {
        ans += 5;
        visited.insert(make_pair(p, make_pair(x, y)));
        visited.insert(make_pair(make_pair(x, y), p));
      }
    }
    cout << ans << endl;
  }
  return 0;
}
