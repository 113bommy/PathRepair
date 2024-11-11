#include <bits/stdc++.h>
using namespace std;
int mon[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
map<string, int> mp;
vector<pair<int, string> > vis;
int isCorrect(string s) {
  int year, month, day;
  if (s[0] == '-' || s[1] == '-' || s[3] == '-' || s[4] == '-' || s[6] == '-' ||
      s[7] == '-' || s[8] == '-' || s[9] == '-')
    return 0;
  if (s[2] != '-' || s[5] != '-') return 0;
  day = (s[0] - '0') * 10 + s[1] - '0';
  month = (s[3] - '0') * 10 + s[4] - '0';
  year = 0;
  for (int i = 0; i < 4; i++) year = year * 10 + s[6 + i] - '0';
  if (year >= 2013 && year <= 2015 && month >= 1 && month <= 12 && day >= 1 &&
      day <= 31 && day <= mon[month])
    return 1;
  else
    return 0;
}
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.length() - 9; i++) {
    string s1(s, i, 10);
    if (isCorrect(s1)) mp[s1]++;
  }
  for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
    vis.push_back(make_pair(it->second, it->first));
  sort(vis.begin(), vis.end());
  cout << vis[vis.size() - 1].second << endl;
  return 0;
}
