#include <bits/stdc++.h>
using namespace std;
int a[3000][3000];
int main() {
  int n, i, j, k;
  cin >> n;
  if (n == 1) {
    cout << 2 << "\n";
    cout << 1 << "\n";
    cout << 1;
  } else if (n == 2) {
    cout << 2 << "\n";
    cout << 1 << " " << 2 << "\n";
    cout << 1 << " " << 2 << "\n";
  } else if (n < 6) {
    cout << 3 << "\n";
    cout << 1 << " " << 2 << "\n";
    cout << 1 << " " << 3 << "\n";
    cout << 2 << " " << 3 << "\n";
  } else {
    i = 1;
    while ((i * (i + 1)) / 2 <= n) {
      i++;
    }
    cout << i << "\n";
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 1;
    a[1][1] = 3;
    a[2][0] = 2;
    a[2][1] = 3;
    int p = 4;
    for (j = 3; j < i; j++) {
      for (k = 0; k <= j; k++) {
        a[j][k] = p;
        p++;
      }
    }
    p = 4;
    for (j = 2; j < i - 1; j++) {
      for (k = 0; k < j; k++) {
        a[k][j] = p;
        p++;
      }
    }
    for (j = 0; j < i; j++) {
      for (k = 0; k < i - 1; k++) {
        cout << a[j][k] << " ";
      }
      cout << "\n";
    }
  }
}
