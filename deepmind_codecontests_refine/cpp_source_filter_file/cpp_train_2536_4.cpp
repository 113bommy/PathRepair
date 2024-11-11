#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int inf = 0x3f3f3f3f;
const long long inf64 = 0x3f3f3f3f3f3f3f3fLL;
const double eps = 1e-6;
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
  return os << p.first << "," << p.second;
}
template <typename A>
ostream& operator<<(ostream& os, const vector<A>& v) {
  for (int i = 0; i < v.size(); i++) {
    os << v[i] << ";";
  }
  return os;
}
template <typename A>
ostream& operator<<(ostream& os, const set<A>& v) {
  for (typename set<A>::const_iterator it = v.begin(); it != v.end(); ++it) {
    os << *it << ";";
  }
  return os;
}
template <typename A, typename B>
ostream& operator<<(ostream& os, const map<A, B>& v) {
  for (typename map<A, B>::const_iterator it = v.begin(); it != v.end(); ++it) {
    os << it->first << "=" << it->second << ";";
  }
  return os;
}
void solve234(string s) {
  int p = s.find("ru");
  cout << s.substr(0, p);
  cout << ".ru";
  if (p + 2 < s.size()) {
    cout << "/" << s.substr(p + 2);
  }
  cout << endl;
}
int main() {
  string s;
  cin >> s;
  if (s.size() > 4 && s[0] == 'h') {
    cout << "http://";
    solve234(s.substr(4));
  } else if (s.size() > 3 && s[0] == 'f') {
    cout << "ftp://";
    solve234(s.substr(3));
  }
  return 0;
}
