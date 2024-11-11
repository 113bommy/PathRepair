#include <bits/stdc++.h>
using namespace std;
int a[9];
int A(int n) {
  int s = 1;
  for (int i = 1; i <= n; s *= i++)
    ;
  return s;
}
int main() {
  int i, n, t;
  string s;
  cin >> s;
  for (i = 0; i < 6; i++) {
    char c = s[i];
    switch (c + 32) {
      case 'b':
        a[1]++;
        break;
      case 'g':
        a[2]++;
        break;
      case 'o':
        a[3]++;
        break;
      case 'r':
        a[4]++;
        break;
      case 'v':
        a[5]++;
        break;
      case 'y':
        a[6]++;
        break;
    }
  }
  sort(a, a + 9, greater<int>());
  if (a[0] == 1 && a[1] == 1 && a[2] == 1 && a[3] == 1 && a[4] == 1 &&
      a[5] == 1) {
    cout << 30 << endl;
  } else if (a[0] == 2 && a[1] == 1 && a[2] == 1 && a[3] == 1 && a[4] == 1 &&
             a[5] == 0) {
    cout << 3 + 6 * 2 << endl;
  } else if (a[0] == 2 && a[1] == 2 && a[2] == 1 && a[3] == 1 && a[4] == 0 &&
             a[5] == 0) {
    cout << 1 + 1 * 2 + 4 << endl;
  } else if (a[0] == 2 && a[1] == 2 && a[2] == 2 && a[3] == 0 && a[4] == 0 &&
             a[5] == 0) {
    cout << 1 + 3 * 1 + 2 << endl;
  } else if (a[0] == 3 && a[1] == 1 && a[2] == 1 && a[3] == 1 && a[4] == 0 &&
             a[5] == 0) {
    cout << 3 + 2 << endl;
  } else if (a[0] == 3 && a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 0 &&
             a[5] == 0) {
    cout << 3 << endl;
  } else if (a[0] == 4 && a[1] == 1 && a[2] == 1) {
    cout << 2 << endl;
  } else if (a[0] == 4 && a[1] == 2) {
    cout << 2 << endl;
  } else if (a[0] == 5 && a[1] == 1) {
    cout << 1 << endl;
  } else if (a[0] == 3 && a[1] == 3) {
    cout << 2 << endl;
  } else if (a[0] == 6) {
    cout << 1 << endl;
  }
  return 0;
}
