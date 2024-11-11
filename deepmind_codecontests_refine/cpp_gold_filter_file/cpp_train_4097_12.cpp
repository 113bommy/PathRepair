#include <bits/stdc++.h>
using namespace std;
bool com(pair<char, int> &x, pair<char, int> &y) {
  if (x.first > y.first) {
    return 1;
  }
  if (x.first < y.first) {
    return 0;
  }
  return x.second < y.second;
}
int main() {
  string s;
  cin >> s;
  vector<pair<char, int>> v;
  for (int i = 0; i < s.size(); i++) {
    v.push_back(make_pair(s[i], i));
  }
  sort(v.begin(), v.end(), com);
  string str = "";
  int chk = -1;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].second > chk) {
      str = str + v[i].first;
      chk = v[i].second;
    }
  }
  cout << str;
  return 0;
}
