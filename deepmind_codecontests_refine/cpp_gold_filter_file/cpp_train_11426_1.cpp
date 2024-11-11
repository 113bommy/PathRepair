#include <bits/stdc++.h>
using namespace std;
bool pa(string s) {
  bool is_palin = true;
  int sz = s.size();
  for (int i = 0; i < sz / 2; i++) {
    if (s[i] != s[sz - i - 1]) {
      return false;
    }
  }
  return true;
}
int main() {
  string s;
  cin >> s;
  int sz = s.size();
  bool is_palin = true;
  for (int i = 0; i < sz / 2; i++) {
    if (s[i] != s[sz - i - 1]) {
      is_palin = false;
    }
  }
  if (!is_palin) {
    cout << sz << "\n";
    return 0;
  }
  for (int i = 0; i < sz / 2; i++) {
    string st;
    ;
    bool c = true;
    for (int j = i; j < s.size() - 1; j++) {
      st += s[j];
    }
    if (!pa(st)) {
      cout << st.size() << "\n";
      return 0;
    }
    st = "";
    for (int j = i + 1; j < s.size(); j++) {
      st += s[j];
    }
    if (!pa(st)) {
      cout << st.size() << "\n";
      return 0;
    }
  }
  cout << 0 << "\n";
}
