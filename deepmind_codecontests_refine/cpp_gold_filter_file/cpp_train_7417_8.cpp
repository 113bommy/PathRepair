#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string s1;
    for (int i = 0; i < s.length(); i += 2) {
      s1 = s1 + s[i];
    }
    cout << s1 + s[s.length() - 1] << endl;
  }
  return 0;
}
