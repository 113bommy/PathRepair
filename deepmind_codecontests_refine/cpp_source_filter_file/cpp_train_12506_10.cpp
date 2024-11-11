#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    string s;
    cin >> s;
    if (s.length() > 2) {
      cout << "YES" << endl << "2" << endl;
      cout << s[0] << " " << s.substr(1, s.length()) << endl;
    } else {
      if (s[i] == 2) {
        if (s[0] < s[1]) {
          cout << "YES" << endl << "2" << endl << s[0] << " " << s[1] << endl;
        } else {
          cout << "NO" << endl;
        }
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
