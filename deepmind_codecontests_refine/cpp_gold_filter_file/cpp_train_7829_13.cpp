#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[9];
  char c;
  for (int i = 0; i < 9; i++) {
    cin >> c;
    if (c == 'X') {
      a[i] = 1;
    } else {
      a[i] = 0;
    }
  }
  for (int i = 0; i < 9; i++) {
    if (a[i] != a[8 - i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
