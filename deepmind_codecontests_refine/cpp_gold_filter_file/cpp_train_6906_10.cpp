#include <bits/stdc++.h>
using namespace std;
string s, t;
bool haveSpell;
bool isAmplifying() {
  for (auto c : s)
    if (!isspace(c)) return c == '#';
  return false;
}
int main() {
  t = "";
  haveSpell = false;
  while (getline(cin, s)) {
    if (isAmplifying()) {
      if (haveSpell) {
        cout << t << endl;
        t = "";
        haveSpell = false;
      }
      cout << s << endl;
    } else {
      string newS = "";
      for (auto c : s)
        if (!isspace(c)) newS.push_back(c);
      t += newS;
      haveSpell = true;
    }
  }
  if (haveSpell) cout << t << endl;
}
