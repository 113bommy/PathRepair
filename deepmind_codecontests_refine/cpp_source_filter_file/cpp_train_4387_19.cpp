#include <bits/stdc++.h>
using namespace std;
int main() {
  bool mr = false;
  string s, b;
  cin >> b;
  for (int i = 0; i < 5; i++) {
    cin >> s;
    if (b[0] == s[0] || b[1] == s[i]) {
      mr = true;
      break;
    }
  }
  mr ? cout << "YES" : cout << "NO";
}
