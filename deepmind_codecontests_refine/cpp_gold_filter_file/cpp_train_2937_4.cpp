#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, c;
  cin >> r >> c;
  if (r == 1 && c == 1) {
    cout << "0";
    return 0;
  }
  if (r == 1) {
    for (int i = 2; i <= c + 1; i++) {
      cout << i << " ";
    }
    return 0;
  }
  if (c == 1) {
    for (int i = 2; i <= r + 1; i++) {
      cout << i << endl;
    }
    return 0;
  }
  for (int i = 1; i <= r; i++) {
    for (int j = r + 1; j <= c + r; j++) {
      cout << i * j << " ";
    }
    cout << endl;
  }
  return 0;
}
