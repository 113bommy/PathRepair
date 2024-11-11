#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int b = 0;
    int c = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'A' || s[i] == 'C') {
        c++;
      } else {
        b++;
      }
    }
    if (b == c) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
