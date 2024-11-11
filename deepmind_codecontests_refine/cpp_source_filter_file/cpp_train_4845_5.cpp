#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  while (n--) {
    string s, l;
    cin >> s;
    int len = s.length() - 4;
    for (int i = 4; i < s.length(); i++) {
      l.push_back(s[i]);
    }
    if (len == 1) {
      if (l == "9")
        cout << "1989" << endl;
      else
        cout << "199" << l << endl;
    }
    if (len == 2) {
      if (l == "99")
        cout << "1999" << endl;
      else
        cout << "20" << l << endl;
    }
    if (len == 3) {
      if (l <= "099")
        cout << "3" << l << endl;
      else
        cout << "2" << l << endl;
    }
    if (len == 4) {
      if (l <= "3099")
        cout << "1" << l << endl;
      else
        cout << l << endl;
    }
    if (len == 5) {
      if (l <= "13099")
        cout << "1" << l << endl;
      else
        cout << l << endl;
    }
    if (len == 6) {
      if (l <= "113099")
        cout << "1" << l << endl;
      else
        cout << l << endl;
    }
    if (len == 7) {
      if (l <= "1113099")
        cout << "1" << l << endl;
      else
        cout << l << endl;
    }
    if (len == 8) {
      if (l <= "1113099")
        cout << "1" << l << endl;
      else
        cout << l << endl;
    }
    if (len == 9) {
      if (l <= "11113099")
        cout << "1" << l << endl;
      else
        cout << l << endl;
    }
  }
  return 0;
}
