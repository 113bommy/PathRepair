#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int a = 0;
  bool o = false;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '1') o = true;
    if (o && s[i] == '0') ++a;
  }
  cout << (a >= 5 ? "yes" : "no") << endl;
}
