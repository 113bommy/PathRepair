#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    char tmp = s[0];
    int counter = 0;
    string ans = "";
    for (size_t i = 1; i < s.length(); i++) {
      if (s[i] == tmp)
        counter++;
      else {
        for (size_t j = 0; j < counter / 2 + 1; j++) {
          ans += tmp;
        }
        tmp = s[i];
        counter = 0;
      }
    }
    for (size_t j = 0; j < counter / 2 + 1; j++) {
      ans += tmp;
    }
    cout << ans << endl;
  }
}
