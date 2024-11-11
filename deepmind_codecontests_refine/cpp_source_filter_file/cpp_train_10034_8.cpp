#include <bits/stdc++.h>
using namespace std;
int _, __, ___[9], i, n;
vector<string> possible;
string rev(int now, string s) {
  reverse(s.begin(), s.end());
  string lm;
  lm.erase();
  for (int o = now; o < s.size(); o++) lm += s[o];
  return lm;
}
bool check_one(string s) {
  bool ansf;
  for (int k = 0; k < _; k++) {
    ansf = false;
    for (int o = 0; o < s.size(); o++)
      if (s[o] != '.' && ___[k + 1] + '0' == s[o]) ansf = true;
    if (!ansf) return false;
  }
  return true;
}
void check(string now, string s, int tmp, int lmp) {
  if (tmp == s.size() && lmp != 4) return;
  if (lmp == 4 && tmp != s.size()) return;
  if (tmp == s.size() && lmp == 4) {
    possible.push_back(now);
    return;
  }
  if (tmp != 0) now += ".";
  int klp = 0;
  string g;
  int e = tmp;
  g.clear();
  while (tmp < s.size() && klp <= 256) {
    klp = klp * 10 + s[tmp] - '0';
    if (klp > 256) break;
    g += s[tmp];
    check(now + g, s, tmp + 1, lmp + 1);
    if (e == tmp && s[tmp] == '0') break;
    tmp++;
  }
}
void build(string s) {
  if (s.size() == __) {
    if (check_one(s)) {
      check("", s + rev(0, s), 0, 0);
      check("", s + rev(1, s), 0, 0);
    }
    return;
  }
  for (int p = 1; p <= _; p++) build(s + char('0' + ___[p]));
}
string k;
int main() {
  cin >> _;
  if (_ > 6) {
    cout << 0 << endl;
    return 0;
  }
  for (__ = 1; __ <= _; __++) cin >> ___[__];
  for (__ = 2; __ <= 6; __++) build("");
  cout << possible.size() << endl;
  for (__ = 0; __ < possible.size(); __++) cout << possible[__] << endl;
}
