#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  bool color = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char ch;
      cin >> ch;
      if (ch == 'M' || ch == 'Y' || ch == 'C') {
        color = true;
        break;
      }
    }
  }
  if (color) {
    cout << "#Color";
  } else {
    cout << "#Black&White";
  }
  return 0;
}
