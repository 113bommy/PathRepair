#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string t_s, t_e;
  for (int i = 0; i <= s.size(); i++) {
    t_s = "";
    for (int k = 0; k < i; k++) t_s += s[k];
    for (int j = i; j < s.size(); j++) {
      t_e = "";
      for (int k = j; k < s.size(); k++) t_e += s[k];
      if (t_s + t_e == "CODEFORCES") {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
