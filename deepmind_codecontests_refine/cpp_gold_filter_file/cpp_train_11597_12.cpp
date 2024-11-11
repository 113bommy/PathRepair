#include <bits/stdc++.h>
using namespace std;
int runGCJ(istream& in, ostream& out) {
  int T;
  in >> T;
  for (int t = 1; t <= T; ++t) {
    long long res = 0;
    out << "Case #" << t << ": " << res << endl;
  }
  return 0;
}
bool cmpf(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
int runCF(istream& in, ostream& out) {
  int n;
  in >> n;
  vector<pair<int, int> > s(n);
  vector<pair<int, int> > a(n);
  vector<pair<int, int> > b(n);
  for (int i = 0; i < (int)n; ++i) {
    in >> s[i].first;
    s[i].second = i;
    a[i].second = i;
    b[i].second = i;
  }
  sort(s.begin(), s.end());
  int m = (n + 2) / 3;
  for (int i = 0; i < (int)m; ++i) {
    a[s[i].second].first = i;
    b[s[i].second].first = s[i].first - i;
  }
  for (int i = m; i < (int)min(2 * m, n); ++i) {
    b[s[i].second].first = i;
    a[s[i].second].first = s[i].first - i;
  }
  for (int i = 2 * m; i < (int)n; ++i) {
    b[s[i].second].first = n - 1 - i;
    a[s[i].second].first = s[i].first - b[s[i].second].first;
  }
  out << "YES" << endl;
  sort(a.begin(), a.end(), cmpf);
  sort(b.begin(), b.end(), cmpf);
  for (int i = 0; i < (int)n; ++i) out << a[i].first << " ";
  out << endl;
  for (int i = 0; i < (int)n; ++i) out << b[i].first << " ";
  cout << endl;
  return 0;
}
int main() {
  ifstream in("input");
  ofstream out("output");
  runCF(cin, cout);
  return 0;
}
