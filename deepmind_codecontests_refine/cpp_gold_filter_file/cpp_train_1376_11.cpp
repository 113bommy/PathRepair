#include <bits/stdc++.h>
using namespace std;
int t;
string F = "FILIPINO", J = "JAPANESE", K = "KOREAN", s;
int main() {
  cin >> t;
  while (t--) {
    cin >> s;
    int ans = -1;
    if (s.size() >= 2) {
      if (s.substr(s.size() - 2, 2) == "po") {
        ans = 0;
      }
    }
    if (s.size() >= 4) {
      if (s.substr(s.size() - 4, 4) == "desu" ||
          s.substr(s.size() - 4, 4) == "masu") {
        ans = 1;
      }
    }
    if (s.size() >= 5) {
      if (s.substr(s.size() - 5, 5) == "mnida") {
        ans = 2;
      }
    }
    if (ans == 0) {
      cout << F << endl;
    } else if (ans == 1) {
      cout << J << endl;
    } else {
      cout << K << endl;
    }
  }
  return 0;
}
