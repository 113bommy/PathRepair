#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int i = s.length() - 1; i > 0; i--) {
      string s1 = s.substr(i);
      if (s1 == "po") {
        cout << "FILIPINO";
        break;
      } else if (s1 == "desu" || s1 == "masu") {
        cout << "JAPANESE";
        break;
      } else if (s1 == "mnida") {
        cout << "KOREAN";
        break;
      }
    }
    cout << endl;
  }
}
