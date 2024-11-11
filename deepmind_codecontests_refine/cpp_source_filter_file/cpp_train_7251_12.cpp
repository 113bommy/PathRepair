#include <bits/stdc++.h>
using namespace std;
int find_gap(pair<int, int> &p1, pair<int, int> &p2) {
  int H = (p2.first - p1.first) * 60;
  int M = p2.second - p1.second;
  return H + M;
}
int main() {
  int n, s;
  cin >> n >> s;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    int h, m;
    cin >> h >> m;
    v[i].first = h;
    v[i].second = m;
  }
  int gap = 2 * s + 3;
  pair<int, int> ans;
  bool flag = 0;
  if (v[0].first != 0 || v[0].second != 0) {
    pair<int, int> zero;
    zero.first = 0;
    zero.second = 0;
    if (find_gap(zero, v[0]) > s) {
      ans.first = 0;
      ans.second = 0;
      goto jump;
    }
  }
  for (int i = 0; i < n - 1; i++) {
    if (find_gap(v[i], v[i + 1]) >= gap) {
      flag = 1;
      ans.first = v[i].first + s / 60;
      ans.second = v[i].second + 1 + s % 60;
      if (ans.second >= 60) {
        ans.second = ans.second % 60;
        ans.first++;
      }
      break;
    }
  }
  if (flag == 0) {
    ans.first = v[n - 1].first + s / 60;
    ans.second = v[n - 1].second + 1 + s % 60;
    if (ans.second >= 60) {
      ans.second = ans.second % 60;
      ans.first++;
    }
  }
jump : { cout << ans.first << " " << ans.second << endl; }
  return 0;
}
