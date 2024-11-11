#include <bits/stdc++.h>
using namespace std;
int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dm(string str) {
  int s;
  s = (int)str[0] - 48;
  s = (s * 10) + (int)str[1] - 48;
  return s;
}
int year(string str) {
  int s;
  s = (int)str[0] - 48;
  s = (s * 10) + (int)str[1] - 48;
  s = (s * 10) + (int)str[2] - 48;
  s = (s * 10) + (int)str[3] - 48;
  return s;
}
bool iscorrect(string str) {
  if (str[2] != '-' || str[5] != '-') return false;
  int d, m, y, cnt = 0;
  for (int i = 0; i < str.size(); i++)
    if (str[i] == '-') cnt++;
  if (cnt > 2) return false;
  y = year(str.substr(6, 4));
  m = dm(str.substr(3, 2));
  d = dm(str.substr(0, 2));
  if (y < 2013 || y > 2015) return false;
  if (m < 1 || m > 12) return false;
  if (d < 1 || d > day[m]) return false;
  return true;
}
int main() {
  map<string, int> mp;
  map<string, int>::iterator it;
  string str, tmp;
  cin >> str;
  mp.clear();
  for (int i = 0; i <= str.size() - 10; i++) {
    tmp = str.substr(i, 10);
    if (iscorrect(tmp)) {
      if (mp.find(tmp) == mp.end())
        mp[tmp] = 1;
      else
        mp[tmp]++;
    }
  }
  int max = -1;
  for (it = mp.begin(); it != mp.end(); ++it) {
    if (it->second > max) {
      max = it->second;
      tmp = it->first;
    }
  }
  cout << tmp << endl;
}
