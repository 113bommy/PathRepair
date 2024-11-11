#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    map<char, int> valid;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      if (i != s.size() - 1 && (s[i] == s[i + 1] && !valid[s[i]])) {
        valid[s[i]] = -1;
        i++;
      } else {
        valid[s[i]] = 1;
      }
    }
    for (char i = 'a'; i <= 'z'; i++) {
      if (valid[i] == 1) {
        cout << i;
      }
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
