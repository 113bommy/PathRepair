#include <bits/stdc++.h>
using namespace std;
bool cmpa(pair<int, int>& a, pair<int, int>& b) { return a.first < b.first; }
bool cmpd(pair<int, int>& a, pair<int, int>& b) { return a.first > b.first; }
const int T = 1005;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> v(T);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v[a / 1000].emplace_back(make_pair(b, i));
  }
  bool b = true;
  for (int i = 0; i < T; i++) {
    if (b)
      sort(v[i].begin(), v[i].end(), &cmpa);
    else
      sort(v[i].begin(), v[i].end(), &cmpd);
    b = !b;
  }
  for (int i = 0; i < T; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      cout << v[i][j].second + 1 << ' ';
    }
  }
  return 0;
}
