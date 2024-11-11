#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int p1 = 0, p2 = 0, c = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '1') {
        p1 = i;
        break;
      }
    }
    for (int i = s.length(); i >= p1; i--) {
      if (s[i] == '1') {
        p2 = i;
        break;
      }
    }
    for (int i = p1; i < p2; i++) {
      if (s[i] == '0') c++;
    }
    cout << c << endl;
  }
}
