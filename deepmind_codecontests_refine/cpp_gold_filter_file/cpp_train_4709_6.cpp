#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  bool flag = true;
  for (int i = 1; i < a.length(); i++) {
    if (islower(a[i])) {
      flag = 0;
    }
    if (!flag) {
      break;
    }
  }
  if (!flag && a.length() > 1) {
    cout << a;
  } else {
    for (int i = 0; i < a.length(); i++) {
      if (islower(a[i])) {
        cout << char(toupper(a[i]));
      } else {
        cout << char(tolower(a[i]));
      }
    }
  }
  return 0;
}
