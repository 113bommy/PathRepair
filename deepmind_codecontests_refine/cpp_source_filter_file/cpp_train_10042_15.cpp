#include <bits/stdc++.h>
using namespace std;
int main() {
  int f[30];
  f[0] = 1;
  f[1] = 3;
  f[2] = 6;
  for (int i = 3; i < 30; i++) {
    f[i] = f[i - 3] + (3 * (i + 1)) - 3;
  }
  int n = 0;
  cin >> n;
  int x = 0;
  for (int i = 0; i < 30; i++) {
    if (n == f[i]) {
      x++;
      break;
    }
  }
  if (x == 1) {
    cout << "YES";
  }
  if (x == 0) {
    cout << "NO";
  }
}
