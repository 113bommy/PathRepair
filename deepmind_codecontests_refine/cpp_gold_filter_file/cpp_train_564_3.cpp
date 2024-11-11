#include <bits/stdc++.h>
using namespace std;
bool checkArray(string s, string t) {
  for (unsigned int i = 0; i < t.size(); i++) {
    bool truth = false;
    for (unsigned int j = 0; j < s.size(); j++) {
      if (t[i] == s[j]) {
        truth = true;
        s.erase(s.begin() + j);
        break;
      }
    }
    if (!truth) return false;
  }
  return true;
}
bool checkAuto(string s, string t) {
  unsigned int j = 0;
  for (unsigned int i = 0; i < t.size(); i++, j++) {
    bool truth = false;
    for (; j < s.size(); j++) {
      if (t[i] == s[j]) {
        truth = true;
        break;
      }
    }
    if (!truth) return false;
  }
  return true;
}
string suffix(string s, string t) {
  if (t.size() > s.size()) {
    return "need tree";
  }
  if (t.size() == s.size()) {
    return checkArray(s, t) ? "array" : "need tree";
  }
  return checkAuto(s, t) ? "automaton"
                         : (checkArray(s, t) ? "both" : "need tree");
}
int main() {
  string s, t;
  cin >> s >> t;
  cout << suffix(s, t) << endl;
  return 0;
}
