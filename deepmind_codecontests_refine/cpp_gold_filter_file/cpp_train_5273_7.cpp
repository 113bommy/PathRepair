#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  for (int i = 0; i < s.length(); i++) {
    s[i] = toupper(s[i]);
  }
  for (int i = 0; i < n; ++i) {
    string p;
    cin >> p;
    int t = 0;
    if (s.length() != p.length()) continue;
    for (int j = 0; j < p.length(); ++j) {
      p[j] = toupper(p[j]);
      if (s[j] == p[j] || (s[j] == '0' && p[j] == 'O') ||
          (p[j] == '0' && s[j] == 'O') || (s[j] == 'I' && p[j] == 'L') ||
          (p[j] == 'I' && s[j] == 'L') || (s[j] == 'I' && p[j] == '1') ||
          (p[j] == 'I' && s[j] == '1') || (s[j] == '1' && p[j] == 'L') ||
          (p[j] == '1' && s[j] == 'L')) {
      } else {
        t = 1;
        break;
      }
    }
    if (t == 0) {
      return cout << "No" << endl, 0;
    }
  }
  cout << "Yes" << endl;
}
