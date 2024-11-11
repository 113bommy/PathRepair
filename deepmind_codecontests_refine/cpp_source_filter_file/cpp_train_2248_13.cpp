#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
const int M = 1000000007;
const double PI = atan(1) * 4;
const int oo = 1000000000;
int n, d;
vector<string> v;
string s;
bool can(int md) {
  int cur = 1, ln = 0;
  for (int i = 0; i < v.size(); ++i) {
    if (v[i].size() > md) return false;
    if (ln + v[i].size() > md) {
      ++cur;
      ln = 0;
    }
    ln += v[i].size();
  }
  return cur <= d;
}
bool is(char x) {
  if (x >= 'a' && x <= 'z') return true;
  return x >= 'A' && x <= 'Z';
}
int main() {
  cin >> d;
  getchar();
  getline(cin, s);
  int i = 0, j = 0;
  while (i < s.size()) {
    while (j < s.size() && is(s[j])) ++j;
    if (j == s.size()) {
      v.push_back(s.substr(i, j - i));
      break;
    }
    string cur = s.substr(i, j - i);
    if (s[j] == ' ')
      cur += '.';
    else
      cur += '-';
    v.push_back(cur);
    i = j = j + 1;
  }
  int lo = 0, hi = s.size(), md, bst = s.size();
  while (lo <= hi) {
    md = (lo + hi) / 2;
    if (can(md)) {
      bst = min(bst, md);
      hi = md - 1;
    } else
      lo = md + 1;
  }
  cout << md << endl;
}
