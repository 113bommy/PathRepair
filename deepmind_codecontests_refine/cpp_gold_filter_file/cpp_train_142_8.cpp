#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1;
  while (cin >> s1) {
    string s2 = "";
    for (int i = 0; i < s1.size(); i++) {
      if (s1[i] != '+') s2 += s1[i];
    }
    sort(s2.begin(), s2.end());
    for (int i = 0; i < s2.size(); i++) {
      if (i) cout << '+';
      cout << s2[i];
    }
    cout << '\n';
  }
  return 0;
}
