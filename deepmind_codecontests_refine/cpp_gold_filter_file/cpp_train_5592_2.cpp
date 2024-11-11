#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  int n, m;
  int ret = 0;
  int a, b;
  bool v = false;
  bool up = false;
  int ind;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '.') {
      ind = i;
      if (s[i - 1] == '9') {
        v = true;
      }
      if (s[i + 1] >= '5') {
        up = true;
      }
    }
  }
  if (v) {
    cout << "GOTO Vasilisa.";
  } else if (up == false) {
    for (int i = 0; i < ind; i++) {
      cout << s[i];
    }
  } else {
    for (int i = 0; i < ind - 1; i++) {
      cout << s[i];
    }
    cout << s[ind - 1] - '0' + 1;
  }
}
