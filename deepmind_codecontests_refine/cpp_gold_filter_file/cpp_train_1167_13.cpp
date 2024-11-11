#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, a, b, x, y, c, d, g;
  cin >> t;
  while (t--) {
    vector<char> s;
    x = 0, y = 0, g = 0;
    vector<pair<int, int> > v;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a >> b;
      v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
      c = v[i].first - x;
      x = v[i].first;
      for (int j = 0; j < c; j++) s.push_back('R');
      if (v[i].second - y >= 0) {
        d = v[i].second - y;
        y = v[i].second;
        for (int j = 0; j < d; j++) s.push_back('U');
      } else {
        cout << "NO" << endl;
        g++;
        break;
      }
    }
    if (g == 0) {
      cout << "YES" << endl;
      for (int i = 0; i < s.size(); i++) cout << s[i];
      cout << endl;
    }
  }
}
