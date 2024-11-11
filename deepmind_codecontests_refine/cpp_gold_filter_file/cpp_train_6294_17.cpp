#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  string b;
  string c;
  cin >> a;
  cin >> b;
  cin >> c;
  long long int i;
  if (a[1] == '<') {
    a[1] = '>';
    char t = a[0];
    a[0] = a[2];
    a[2] = t;
  }
  if (b[1] == '<') {
    b[1] = '>';
    char t = b[0];
    b[0] = b[2];
    b[2] = t;
  }
  if (c[1] == '<') {
    c[1] = '>';
    char t = c[0];
    c[0] = c[2];
    c[2] = t;
  }
  long long int X[3];
  X[0] = 0;
  X[1] = 0;
  X[2] = 0;
  if (a[2] == 'A') {
    X[0] += 1;
  }
  if (a[2] == 'B') {
    X[1] += 1;
  }
  if (a[2] == 'C') {
    X[2] += 1;
  }
  if (b[2] == 'A') {
    X[0] += 1;
  }
  if (b[2] == 'B') {
    X[1] += 1;
  }
  if (b[2] == 'C') {
    X[2] += 1;
  }
  if (c[2] == 'A') {
    X[0] += 1;
  }
  if (c[2] == 'B') {
    X[1] += 1;
  }
  if (c[2] == 'C') {
    X[2] += 1;
  }
  if ((X[0] == 0 && X[1] == 1 && X[2] == 2) ||
      (X[0] == 0 && X[1] == 2 && X[2] == 1) ||
      (X[0] == 1 && X[1] == 0 && X[2] == 2) ||
      (X[0] == 1 && X[1] == 2 && X[2] == 0) ||
      (X[0] == 2 && X[1] == 0 && X[2] == 1) ||
      (X[0] == 2 && X[1] == 1 && X[2] == 0)) {
    for (i = 0; i < 3; i += 1) {
      if (X[i] == 2) {
        cout << (char)('A' + i);
      }
    }
    for (i = 0; i < 3; i += 1) {
      if (X[i] == 1) {
        cout << (char)('A' + i);
      }
    }
    for (i = 0; i < 3; i += 1) {
      if (X[i] == 0) {
        cout << (char)('A' + i);
      }
    }
  } else {
    cout << "Impossible\n";
  }
  return 0;
}
