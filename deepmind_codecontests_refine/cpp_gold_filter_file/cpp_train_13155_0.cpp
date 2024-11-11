#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v[2];
int main() {
  int n, c, s;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c >> s;
    v[c].push_back(make_pair(s, i));
  }
  sort(v[0].begin(), v[0].end());
  sort(v[1].begin(), v[1].end());
  for (int i = 0, j = 0; i < (int)v[0].size() && j < (int)v[1].size();) {
    int t = min(v[0][i].first, v[1][j].first);
    cout << v[0][i].second << ' ' << v[1][j].second << ' ' << t << endl;
    v[0][i].first -= t;
    v[1][j].first -= t;
    if (v[0][i].first)
      j++;
    else if (v[1][j].first)
      i++;
    else if (i < (int)v[0].size() - 1)
      i++;
    else
      j++;
  }
  return 0;
}
