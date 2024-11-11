#include <bits/stdc++.h>
using namespace std;
double EPS = 1e-9;
long long INF = 1e18;
set<char> vowel;
vector<double> mld;
vector<int> vw, ls, rs;
int main() {
  vowel.insert('I');
  vowel.insert('E');
  vowel.insert('A');
  vowel.insert('O');
  vowel.insert('U');
  vowel.insert('Y');
  string s;
  int n;
  double ans;
  getline(cin, s);
  n = (int)s.length();
  s = "*" + s;
  cout << fixed;
  cout.precision(9);
  mld.resize(n + 1);
  vw.resize(n + 1);
  vw[0] = 0;
  for (int i = 1; i <= n; ++i) {
    vw[i] = vw[i - 1];
    if (vowel.find(s[i]) != vowel.end()) {
      vw[i] = vw[i - 1] + 1;
    }
  }
  ls.resize(n + 1);
  rs.resize(n + 1);
  ls[0] = 0;
  rs[0] = 0;
  for (int i = 1; i <= n; ++i) {
    ls[i] = ls[i - 1] + vw[i];
    rs[i] = rs[i - 1] + vw[n - i + 1];
  }
  ans = 0.0;
  for (int len = 1; len <= n; ++len) {
    ans += (double)(rs[len] - ls[len - 1]) / len;
  }
  cout << ans << "\n";
  return 0;
}
