#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, i, j = 0, n;
  cin >> a;
  cin >> b;
  n = 4 * 60;
  n = n - b;
  for (i = 1; i <= a; i++) {
    if (n >= 5 * i) {
      n = n - 5 * i;
      j = j + 1;
    } else {
      break;
    }
  }
  if (j == a) {
    cout << j << endl;
  } else {
    cout << j;
  }
  return 0;
}
