#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, flag = 0;
  cin >> n >> m;
  char c;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c;
      if (c == 'C' || c == 'M' || c == 'Y') {
        flag = 1;
        break;
      }
    }
  }
  if (flag != 1)
    cout << "#Black&White";
  else
    cout << "#Color";
  return 0;
}
