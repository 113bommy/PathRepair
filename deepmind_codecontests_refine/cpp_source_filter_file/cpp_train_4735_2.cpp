#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  bool f = true;
  getline(cin, s);
  getline(cin, t);
  size_t pos = -1;
  size_t pos2 = string ::npos;
  for (int i = 0, ie = (int(s.size())); i < ie; ++i) {
    string temp = "";
    temp += s[i];
    if (t.find(temp, pos + 1) != string ::npos) {
      pos = t.find(temp, pos + 1);
    } else {
      f = false;
      break;
    }
  }
  reverse(s.begin(), s.end());
  for (int i = 0, ie = (int(s.size())); i < ie; ++i) {
    string temp = "";
    temp += s[i];
    if (t.rfind(temp, pos2 - 1) != string ::npos) {
      pos2 = t.rfind(temp, pos2);
    } else {
      f = false;
      break;
    }
  }
  if (f && pos2 > pos)
    cout << pos2 - pos;
  else
    cout << 0;
}
