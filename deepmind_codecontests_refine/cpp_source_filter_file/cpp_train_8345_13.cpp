#include <bits/stdc++.h>
using namespace std;
string s;
double ans = -1;
inline void make_good() {
  string s_ = "";
  for (int i = 0; i < s.size(); ++i) {
    s_ += s[i];
    if (i < s.size() - 1 && s[i] != 'X' && s[i + 1] == s[i]) s_ += 'X';
  }
  s = s_;
}
inline long double solve(string p) {
  long double nol = 0;
  long double nog = 0;
  int cnt = 0;
  int cur = 0;
  for (int i = 0; i < p.size(); ++i) {
    char now;
    if ((int)nol % 2 == 0)
      now = 'L';
    else
      now = 'R';
    if (p[i] == 'X')
      nol++;
    else if (now == p[i]) {
      nol++;
      nog++;
      cur = 0;
    } else {
      nol += 2;
      nog++;
      cnt += cur;
      cur = 1 - cur;
    }
  }
  if ((int)nol % 2 == 1) {
    nol++;
    cnt += cur;
  }
  if (nog * 2 > nol) {
    nog -= cnt;
    nol -= 2 * cnt;
  }
  return nog / nol;
}
int main() {
  cin >> s;
  make_good();
  if (s[0] == s[s.size() - 1] && s[0] != 'X')
    ans = max(solve(s + 'X'), solve('X' + s));
  else
    ans = solve(s);
  ans /= floor(ans * 1e8) / 1e8;
  printf("%0.6lf\n", ans * 100);
  return 0;
}
