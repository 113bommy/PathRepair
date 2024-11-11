#include <bits/stdc++.h>
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
using namespace std;
int main() {
  string s;
  cin >> s;
  set<string> all;
  for (char c = 'a'; c <= 'z'; ++c) {
    for (int i = 0; i <= s.size(); ++i) {
      string t = "";
      for (int j = 0; j < i; ++j) {
        t += s[i];
      }
      t += c;
      for (int j = i; j < s.size(); ++j) {
        t += s[i];
      }
      all.insert(t);
    }
  }
  cout << all.size() << '\n';
  return 0;
}
