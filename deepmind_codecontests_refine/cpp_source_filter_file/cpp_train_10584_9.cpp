#include <bits/stdc++.h>
using namespace std;
bool func(pair<int, int> p1, pair<int, int> p2) {
  if (p1.first < p2.first)
    return true;
  else if (p1.first > p2.first)
    return false;
  else {
    if (p1.second < p2.second) return true;
  }
  return false;
}
int main() {
  int i, a, b, j;
  vector<pair<int, int>> v;
  map<pair<int, int>, int> ma;
  map<pair<int, int>, int> ma1;
  for (i = 0; i < 4; i++) {
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }
  sort(v.begin(), v.end(), func);
  int len = abs(v[1].second - v[0].second);
  int x = v[0].first;
  int y = v[0].first;
  for (i = y; i <= y + len; i++) {
    for (j = x; j <= x + len; j++) {
      ma[make_pair(i, j)] = 2;
    }
  }
  vector<pair<int, int>> v1;
  for (i = 0; i < 4; i++) {
    cin >> a >> b;
    v1.push_back(make_pair(a, b));
  }
  sort(v1.begin(), v1.end(), func);
  len = abs(v1[0].second - v1[1].second);
  x = v1[0].first;
  y = v1[0].second;
  for (i = 0; i < len + 1; i++) {
    a = x;
    b = y;
    for (j = 0; j < len + 1; j++) {
      if (ma[make_pair(a, b)] == 2) {
        cout << "Yes";
        return 0;
      }
      a++;
      b++;
    }
    x++;
    y--;
  }
  cout << "No";
}
