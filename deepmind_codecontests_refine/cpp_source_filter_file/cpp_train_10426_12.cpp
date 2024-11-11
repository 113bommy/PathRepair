#include <bits/stdc++.h>
using namespace std;
string s;
inline int gettype(string s) {
  if (s.find("lios") != string::npos && s.find("lios") == s.size() - 4) {
    return 0;
  }
  if (s.find("liala") != string::npos && s.find("liala") == s.size() - 5) {
    return 1;
  }
  if (s.find("etr") != string::npos && s.find("etr") == s.size() - 3) {
    return 2;
  }
  if (s.find("etra") != string::npos && s.find("etra") == s.size() - 4) {
    return 3;
  }
  if (s.find("initis") != string::npos && s.find("initis") == s.size() - 6) {
    return 4;
  }
  if (s.find("inites") != string::npos && s.find("inites") == s.size() - 6) {
    return 5;
  }
  return -1;
}
vector<int> v;
int main() {
  getline(cin, s);
  istringstream sin(s);
  string t;
  bool flag = 0;
  while (sin >> t) {
    int tp = gettype(t);
    if (tp == -1) {
      flag = 1;
      break;
    }
    v.push_back(tp);
  }
  if (flag) {
    puts("NO");
    return 0;
  }
  int n = v.size();
  bool odd = 0, even = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] & 1)
      odd = 1;
    else
      even = 1;
  }
  if (n == 1) {
    puts("YES");
    return 0;
  }
  if (even && odd) {
    puts("NO");
    return 0;
  }
  bool _0to1 = 0, _2to3 = 0, _4to5 = 0;
  int cnt = 0;
  flag = 1;
  for (int i = 0; i < n; i++) {
    if (v[i] / 2 == 0) {
      if (_2to3 || _4to5) {
        flag = 0;
        break;
      }
      _0to1 = 1;
    }
    if (v[i] / 2 == 1) {
      if (_4to5) {
        flag = 0;
        break;
      }
      _2to3 = 1;
      cnt++;
    }
    if (v[i] / 2 == 2) {
      _4to5 = 1;
    }
  }
  if (cnt != 1) flag = 0;
  puts(flag ? "YES" : "NO");
}
