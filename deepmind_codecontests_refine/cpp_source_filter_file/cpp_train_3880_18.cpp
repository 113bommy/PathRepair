#include <bits/stdc++.h>
using namespace std;
int s1[10] = {0}, s2[10] = {0}, c[10], d[10];
string s;
int n;
vector<pair<int, int>> res, zero;
void ini() {
  memset(s1, 0, sizeof(s1));
  memset(s2, 0, sizeof(s2));
  n = s.size();
  for (int i = 0; i < n; i++) {
    s1[s[i] - '0']++;
    s2[s[i] - '0']++;
  }
}
pair<int, int> ten = {-1, -1};
int main() {
  cin >> s;
  ini();
  for (int i = 0; i <= 9; i++) {
    while (s1[i] && s2[9 - i]) {
      s1[i]--;
      s2[9 - i]--;
      c[i]++;
      d[9 - i]++;
    }
  }
  for (int i = 0; i <= 9; i++)
    if (s1[i] && s2[10 - i]) ten.first = i, ten.second = 10 - i;
  if (ten.first < 0) {
    for (int i = 0; i <= 9; i++)
      if (s1[i] && d[10 - i]) ten.first = i, ten.second = 10 - i;
    for (int i = 0; i <= 9; i++)
      if (s1[i] && c[10 - i]) ten.first = i, ten.second = 10 - i;
  }
  if (ten.first < 0)
    for (int i = 0; i <= 9; i++)
      if (c[i] && d[10 - i]) ten.first = i, ten.second = 10 - i;
  if (ten.first < 0) {
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    cout << s << endl << s << endl;
    return 0;
  }
  ini();
  res.push_back({ten.first, ten.second});
  s1[ten.first]--;
  s2[ten.second]--;
  for (int i = 0; i <= 9; i++) {
    while (s1[i] && s2[9 - i]) {
      s1[i]--;
      s2[9 - i]--;
      res.push_back({i, 9 - i});
    }
  }
  while (s1[0] && s2[0]) {
    s1[0]--;
    s2[0]--;
    zero.push_back({0, 0});
  }
  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) {
      if (s1[i] && s2[j]) {
        res.push_back({i, j});
        s1[i]--;
        s2[j]--;
      }
    }
  }
  reverse(res.begin(), res.end());
  for (int i = 0; i < zero.size(); i++) {
    res.push_back({0, 0});
  }
  for (int i = 0; i < res.size(); i++) {
    cout << res[i].first;
  }
  cout << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i].second;
  }
  cout << endl;
}
