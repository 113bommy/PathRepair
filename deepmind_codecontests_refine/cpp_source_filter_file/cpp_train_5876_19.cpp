#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  if (s1.size() != s2.size())
    cout << "NO";
  else {
    bool a = true;
    for (int i = 0; i <= s1.size() && a; i++) {
      if (s1[i] != s2[s1.size() - 1 - i]) {
        cout << "NO";
        a = false;
      }
    }
    if (a) cout << "YES";
  }
}
