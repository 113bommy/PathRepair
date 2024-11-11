#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int X2, X1, X0;
  char a[3];
  X2 = X1 = X0 = 0;
  for (int i = 0; i < n * m; i++) {
    cin >> a;
    if (!strcmp(a, "11"))
      X2++;
    else if (!(strcmp(a, "01") && strcmp(a, "10")))
      X1++;
    else
      X0++;
  }
  int i = 0;
  while (X2 > 0) {
    i++;
    if (i < m) {
      cout << "11 ";
      X2--;
    } else {
      i = 0;
      cout << "11\n";
      X2--;
    }
  }
  while ((X1 > 0) && (i <= m)) {
    i++;
    if (i < m) {
      cout << "10 ";
      X1--;
    } else {
      i++;
      cout << "10\n";
      X1--;
    }
  }
  int f;
  int const_X1 = X1;
  for (f = 1; f < const_X1 / m + 1; f++) {
    for (int j = 1; (j <= m); j++) {
      if (f % 2 == 1) {
        if (j < m) {
          cout << "01 ";
          X1--;
        } else {
          cout << "01\n";
          X1--;
        }
      } else {
        if (j < m) {
          cout << "10 ";
          X1--;
        } else {
          cout << "10\n";
          X1--;
        }
      }
    }
  }
  for (i = 1; (i < m - (X1 % m) + 1) && (X0 != 0); i++) {
    if (i < m) {
      cout << "00 ";
      X0--;
    } else {
      cout << "00\n";
      X0--;
    }
  }
  i = const_X1 / m + 1;
  if (f % 2 == 0) {
    while ((X1 > 0)) {
      if (i < m) {
        cout << "10 ";
        X1--;
        i++;
      } else {
        cout << "10\n";
        X1--;
      }
    }
  } else {
    while ((X1 > 0)) {
      if (i < m) {
        cout << "01 ";
        X1--;
        i++;
      } else {
        cout << "01\n";
        X1--;
      }
    }
  }
  i = 1;
  while (X0 > 0) {
    if (i < m) {
      cout << "00 ";
      X0--;
      i++;
    } else {
      i = 1;
      cout << "00\n";
      X0--;
    }
  }
}
