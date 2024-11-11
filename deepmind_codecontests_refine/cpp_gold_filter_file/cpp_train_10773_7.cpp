#include <bits/stdc++.h>
using namespace std;
inline long double min(long double a, long double b) {
  if (a < b) return a;
  return b;
}
inline long double max(long double a, long double b) {
  if (a < b) return b;
  return a;
}
string s;
long long calc(string s) {
  long long cnt = 0, m = 1, ret = 0;
  s += '+';
  for (int i = 0; i < s.size(); i++) {
    if (isdigit(s[i])) cnt = cnt * 10 + (s[i] - '0');
    if (s[i] == '+') {
      m *= cnt;
      ret += m;
      m = 1;
      cnt = 0;
    }
    if (s[i] == '*') {
      m *= cnt;
      cnt = 0;
    }
  }
  return ret;
}
int main() {
  cin >> s;
  s = "1*" + s;
  s = s + "*1";
  vector<int> plus;
  for (int(i) = (0); (i) < (s.size()); ++(i)) {
    if (s[i] == '*') plus.push_back(i);
  }
  long long res = 0;
  if (plus.size() == 0)
    res = calc(s);
  else {
    vector<int> left;
    vector<int> right;
    for (int(i) = (0); (i) < (plus.size()); ++(i)) {
      left.push_back(plus[i] + 1);
      right.push_back(plus[i] - 1);
    }
    for (int(i) = (0); (i) < (left.size()); ++(i)) {
      for (int(j) = (0); (j) < (right.size()); ++(j)) {
        int L = left[i];
        int R = right[j];
        if (L > R) continue;
        long long add = calc(s.substr(L, R - L + 1));
        string temp = s.substr(0, L) + to_string(add) + s.substr(R + 1);
        long long hh = calc(temp);
        res = max(res, hh);
      }
    }
  }
  cout << res << endl;
  return 0;
}
