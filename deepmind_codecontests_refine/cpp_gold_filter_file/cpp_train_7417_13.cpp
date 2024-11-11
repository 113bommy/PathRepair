#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;
    string s1;
    s1[0] = s[0];
    for (int j = 1; j < (s.length() - 2); j++) {
      if (s[j] == s[j + 1]) {
        s1 = s1 + s[j];
        j++;
      }
    }
    s1 = s1 + s[s.length() - 1];
    s1 = s[0] + s1;
    cout << s1 << endl;
  }
}
