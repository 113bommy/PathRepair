#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (int i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i != v.size() - 1) os << ", ";
  }
  os << "]\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "[";
  for (auto it : v) {
    os << it;
    if (it != *v.rbegin()) os << ", ";
  }
  os << "]\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v) {
  for (auto it : v) os << it.first << " : " << it.second << "\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  os << "(";
  os << v.first << ", " << v.second << ")";
  return os;
}
void go() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  go();
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int turn = 1;
    while (1) {
      int ok = 0;
      if (s.size() == 1) break;
      for (int i = 1; i < s.size(); i++) {
        if ((s[i] == '1' and s[i - 1] == '0') or
            (s[i] == '0' and s[i - 1] == '1')) {
          string newstr = "";
          turn++;
          ok = 1;
          for (int j = 0; j <= i - 2; j++) {
            newstr += string(1, s[j]);
          }
          for (int j = i + 1; j < s.size(); j++) {
            newstr += string(1, s[j]);
          }
          s = newstr;
          break;
        }
      }
      if (ok == 0) break;
    }
    cout << (turn % 2 == 0 ? "DA" : "NET") << '\n';
  }
}
