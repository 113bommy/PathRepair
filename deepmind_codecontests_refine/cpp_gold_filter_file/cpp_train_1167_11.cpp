#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      m[x].push_back(y);
    }
    int a = 0, b = 0;
    int e = 0, d = 0;
    for (auto i = m.begin(); i != m.end(); i++) {
      sort(m[(*i).first].begin(), m[(*i).first].end());
      if (m[(*i).first][0] >= d)
        d = m[(*i).first][m[(*i).first].size() - 1];
      else {
        e = 1;
        break;
      }
    }
    if (e == 0) {
      cout << "YES" << endl;
      string s;
      for (auto i = m.begin(); i != m.end(); i++) {
        for (int k = a; k < (*i).first; k++) {
          s += 'R';
        }
        a = (*i).first;
        for (int j = 0; j < m[(*i).first].size(); j++) {
          for (int k = b; k < m[(*i).first][j]; k++) {
            s += 'U';
          }
          b = m[(*i).first][j];
        }
      }
      cout << s << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
