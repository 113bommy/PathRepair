#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 9;
const unsigned long long INF = 1e9 + 7;
const int base = 2e5 + 1;
const long long MAX = 1e15 + 1;
const double EPS = 1e-9;
const double PI = acos(-1.);
const int MAXN = 3 * 1e6 + 47;
map<char, int> ca, cb, cc;
pair<int, int> solve(string a, string b, string c) {
  for (auto t : a) ca[t]++;
  for (auto t : b) cb[t]++;
  for (auto t : c) cc[t]++;
  int x = MAXN, y = MAXN;
  for (int i = (0); i < (26); ++i) {
    char t = 'a' + i;
    if (cb[t]) {
      x = min(x, ca[t] / cb[t]);
    }
  }
  int mx = 0;
  pair<int, int> res;
  for (int z = (0); z < (x + 1); ++z) {
    y = MAXN;
    for (int i = (0); i < (26); ++i) {
      char t = 'a' + i;
      if (cc[t]) {
        y = min(y, max(0, (ca[t] - cb[t] * z) / cc[t]));
      }
    }
    if (z + y > mx) {
      mx = z + y;
      res = make_pair(z, y);
    }
  }
  return res;
}
int main() {
  string a, b, c;
  cin >> a >> b >> c;
  pair<int, int> p = solve(a, b, c);
  for (int i = (0); i < (p.first); ++i) cout << b;
  for (int i = (0); i < (p.second); ++i) cout << c;
  for (int i = (0); i < (26); ++i) {
    char t = char('a' + i);
    ca[t] -= p.first * cb[t];
    ca[t] -= p.second * cc[t];
    for (int j = (0); j < (ca[t]); ++j) cout << t;
  }
  return 0;
}
