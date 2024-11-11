#include <bits/stdc++.h>
using namespace std;
int days[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool validity(string s) {
  for (int i = 0; i < 10; i++) {
    if (i == 2 || i == 5) {
      if (s[i] == '-')
        continue;
      else
        return false;
    }
    if (s[i] >= '0' || s[i] <= '9')
      continue;
    else
      return false;
  }
  int d = (s[0] - '0') * 10 + (s[1] - '0');
  int m = (s[3] - '0') * 10 + (s[4] - '0');
  int y = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 +
          (s[9] - '0');
  if (y < 2013 || y > 2015) return false;
  if (m < 1 || m > 12) return false;
  if (d < 1 || d > days[m]) return false;
  return true;
}
int main() {
  map<string, int> m;
  map<string, int>::iterator it;
  int max = 0;
  string s, tmp, proph;
  cin >> s;
  int len = s.length();
  for (int i = 0; i + 10 <= len; i++) {
    tmp = s.substr(i, 10);
    bool f = validity(tmp);
    if (f) {
      it = m.find(tmp);
      if (it == m.end()) {
        m.insert(make_pair(tmp, 1));
        if (max == 0) {
          max = 1;
          proph = tmp;
        }
      } else {
        int f = it->second;
        f++;
        if (f > max) {
          max = f;
          proph = tmp;
        }
        m.erase(it);
        m.insert(make_pair(tmp, f));
      }
    }
  }
  cout << proph << endl;
}
