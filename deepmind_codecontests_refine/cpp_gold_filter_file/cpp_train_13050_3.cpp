#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64777216")
using namespace std;
const int INF = ~(1 << 31);
const double EPS = 1;
const double PI = 3.141592653589793;
int main() {
  int n, a;
  cin >> n;
  map<int, pair<int, int> > m;
  vector<int> s(n);
  vector<vector<int> > v(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < s[i]; j++) {
      cin >> a;
      v[i].push_back(a);
      m[a] = make_pair(i + 1, j + 1);
    }
  }
  int c = 1;
  vector<pair<pair<int, int>, pair<int, int> > > ans;
  for (int j = 0; j < s[0]; j++) {
    for (int i = 0; i < n; i++) {
      if (v[i][j] != c) {
        ans.push_back(make_pair(make_pair(i + 1, j + 1), m[c]));
        m[v[i][j]] = m[c];
        int ii = m[c].first - 1, jj = m[c].second - 1;
        m[c] = make_pair(i + 1, j + 1);
        swap(v[i][j], v[ii][jj]);
      }
      c++;
      if (i + 1 < n && j >= s[i + 1]) break;
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first.first << ' ' << ans[i].first.second << ' '
         << ans[i].second.first << ' ' << ans[i].second.second << endl;
  }
  return 0;
}
