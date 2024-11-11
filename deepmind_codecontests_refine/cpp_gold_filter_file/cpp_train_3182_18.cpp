#include <bits/stdc++.h>
using namespace std;
template <class S, class T>
istream& operator>>(istream& is, pair<S, T>& p) {
  return is >> p.first >> p.second;
}
const double EPS = 1e-10;
const double PI = acos(-1.0);
const long long MOD = 1e9 + 7;
bool isvowel(char c) { return string("aiueoy").find(c) != string::npos; }
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> xs(N);
  for (int i = (0); i < (N); ++i) cin >> xs[i];
  cin.ignore();
  bool ok = true;
  for (int i = (0); i < (N); ++i) {
    string line;
    getline(cin, line);
    stringstream ss(line);
    int lb = 0, ub = 0;
    while (!ss.eof()) {
      int num = 0;
      string s;
      ss >> s;
      for (int j = (0); j < (int((s).size())); ++j)
        if (isvowel(s[j])) ++num;
      if (num > 0) ++lb;
      ub += num;
    }
    if (ub != xs[i]) ok = false;
  }
  cout << (ok ? "YES" : "NO") << endl;
  return 0;
}
