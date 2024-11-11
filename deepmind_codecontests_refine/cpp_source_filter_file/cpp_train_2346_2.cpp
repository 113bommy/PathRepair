#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  int score, r;
  string s;
  cin >> n >> m;
  vector<pair<int, string> > v[m];
  for (long long int i = 0; i < n; i++) {
    cin >> s >> r >> score;
    v[r - 1].push_back(make_pair(score, s));
  }
  for (long long int i = 0; i < m; i++) {
    sort(v[i].begin(), v[i].end(), greater<pair<int, string> >());
    if (v[i].size() >= 2 && v[i][0].first == v[i][1].first) {
      cout << "?\n";
    } else {
      cout << v[i][0].second << ' ' << v[i][1].second << '\n';
    }
  }
  return 0;
}
