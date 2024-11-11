#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;
    vector<int> v(26, 0);
    for (int j = 0; j < s.length(); j++) {
      if (s[j] == s[j + 1]) {
        j++;
      } else {
        v[s[j] - 'a'] = 1;
      }
    }
    if (s.length() == 1) {
      v[s[0] - 'a'] = 1;
    }
    for (int j = 0; j < 26; j++) {
      if (v[j] == 1) {
        cout << (char)(97 + j);
      }
    }
    cout << endl;
  }
}
