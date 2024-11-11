#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, dif;
  cin >> n;
  int a[n];
  bool oper[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = n - 1; i >= 0; i--) {
    if (dif < 0) {
      oper[i] = true;
      dif += a[i];
    } else {
      oper[i] = false;
      dif -= a[i];
    }
  }
  if (dif < 0) {
    for (int i = 0; i < n; i++) {
      if (oper[i] == true)
        cout << '-';
      else
        cout << '+';
    }
  } else {
    for (int i = 0; i < n; i++) {
      if (oper[i] == true)
        cout << '+';
      else
        cout << '-';
    }
  }
  return 0;
}
