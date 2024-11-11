#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string s;
  while (t) {
    t--;
    cin >> s;
    for (int i = 0; i < s.length() - 1; i++) {
      if (s[i] == s[i + 1]) {
        cout << s[i];
        i++;
      } else
        cout << s[i];
    }
  }
  cout << s[s.length() - 1] << endl;
}
