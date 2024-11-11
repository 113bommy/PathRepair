#include <bits/stdc++.h>
using namespace std;
int main() {
  char c[9], t;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> c[i * 3 + j];
    }
  }
  bool flag = true;
  for (int i = 1; i < 5; ++i) {
    if (c[i] != c[8 - i]) {
      flag = false;
      break;
    }
  }
  if (flag)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
