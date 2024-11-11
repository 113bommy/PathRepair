#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  pair<long long, long long> s, e;
  long long t;
  cin >> t;
  cin >> s.first >> s.second >> e.first >> e.second;
  map<char, int> mp;
  string str;
  cin >> str;
  for (int i = 0; i < t; ++i) {
    mp[str[i]]++;
  }
  char dir[] = {"NSWE"};
  map<char, long long> nd;
  for (int j = 0; j < 4; ++j) {
    nd[dir[j]] = 0;
  }
  long long xdiff = abs(s.first - e.first);
  if (s.first < e.first) {
    nd['E'] = xdiff;
  } else if (s.first > e.first) {
    nd['W'] = xdiff;
  }
  long long ydiff = abs(s.second - e.second);
  if (s.second < e.second) {
    nd['N'] = ydiff;
  } else if (s.second > e.second) {
    nd['S'] = ydiff;
  }
  for (int i = 0; i < (int)str.size(); ++i) {
    if (nd[str[i]] > 0) {
      nd[str[i]]--;
    }
    int chck = 0;
    for (int j = 0; j < 4; ++j) chck += nd[dir[j]] == 0;
    if (chck == 0) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
