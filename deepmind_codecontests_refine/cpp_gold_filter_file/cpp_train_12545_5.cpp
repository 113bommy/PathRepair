#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream& operator<<(ostream& out, vector<T>& v) {
  out << "[";
  for (auto k : v) out << k << " ";
  out << "]"
      << "\n";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, set<T> s) {
  out << "{";
  for (auto k : s) out << k << " ";
  out << "}"
      << "\n";
  return out;
}
template <class T, class U>
ostream& operator<<(ostream& out, pair<T, U> p) {
  out << "[ " << p.first << " , " << p.second << " ] ";
  return out;
}
template <class T, class U>
istream& operator>>(istream& in, pair<T, U>& p) {
  in >> p.first >> p.second;
  return in;
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int k;
  cin >> k;
  set<char> ss;
  for (int i = 0; i < int(k); i++) ss.insert(char('a' + i));
  string s;
  cin >> s;
  for (auto k : s) ss.erase(k);
  int l = s.size() - 1;
  for (int i = int(((s.size() + 1) / 2)) - 1; i >= 0; i--) {
    if (s[i] == '?' && s[l - i] == '?') {
      if (ss.size()) {
        s[i] = s[l - i] = *ss.rbegin();
        ss.erase(*ss.rbegin());
      } else
        s[i] = s[l - i] = 'a';
    } else if (s[i] == '?')
      s[i] = s[l - i];
    else if (s[l - i] == '?')
      s[l - i] = s[i];
    else if (s[i] != s[l - i]) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  }
  if (ss.size())
    cout << "IMPOSSIBLE\n";
  else
    cout << s << "\n";
  return 0;
}
