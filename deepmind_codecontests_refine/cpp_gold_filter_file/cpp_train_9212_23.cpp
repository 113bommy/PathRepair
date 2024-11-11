#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x[3], y[3], val[3] = {0, 1, 2};
  long long i, j, z, t;
  for (i = 0; i < 3; i++) {
    cin >> x[i] >> y[i];
    if (x[i] < y[i]) swap(x[i], y[i]);
  }
  if (x[0] == x[1] && x[1] == x[2] && x[0] == y[0] + y[1] + y[2]) {
    cout << x[0] << endl;
    for (z = i = 0; z < 3; z++) {
      for (t = i; i < t + y[z]; i++) {
        for (j = 0; j < x[z]; j++) cout << (char)('A' + val[z]);
        cout << endl;
      }
    }
    return 0;
  }
  t = max_element(x, x + 3) - x;
  swap(x[0], x[t]);
  swap(y[0], y[t]);
  swap(val[0], val[t]);
  int mask[x[0]][x[0]];
  bool f = false;
  for (i = 0; i < y[0]; i++) {
    for (j = 0; j < x[0]; j++) mask[i][j] = val[0];
  }
  if (x[0] == x[1] + x[2] && y[1] == y[2] && y[0] + y[1] == x[0]) {
    f = true;
    for (i = 0; i < y[1]; i++) {
      for (j = 0; j < x[1]; j++) mask[i + y[0]][j] = val[1];
    }
    for (i = 0; i < y[2]; i++) {
      for (j = 0; j < x[2]; j++) mask[i + y[0]][j + x[1]] = val[2];
    }
  } else if (x[0] == y[1] + y[2] && x[1] == x[2] && y[0] + x[1] == x[0]) {
    f = true;
    for (i = 0; i < x[1]; i++) {
      for (j = 0; j < y[1]; j++) mask[i + y[0]][j] = val[1];
    }
    for (i = 0; i < x[2]; i++) {
      for (j = 0; j < y[2]; j++) mask[i + y[0]][j + y[1]] = val[2];
    }
  } else if (x[0] == y[1] + x[2] && x[1] == y[2] && x[1] + y[0] == x[0]) {
    f = true;
    for (i = 0; i < y[2]; i++) {
      for (j = 0; j < x[2]; j++) mask[i + y[0]][j] = val[2];
    }
    for (i = 0; i < x[1]; i++) {
      for (j = 0; j < y[1]; j++) mask[i + y[0]][j + x[2]] = val[1];
    }
  } else if (x[0] == x[1] + y[2] && y[1] == x[2] && x[2] + y[0] == x[0]) {
    f = true;
    for (i = 0; i < y[1]; i++) {
      for (j = 0; j < x[1]; j++) mask[i + y[0]][j] = val[1];
    }
    for (i = 0; i < x[2]; i++) {
      for (j = 0; j < y[2]; j++) mask[i + y[0]][j + x[1]] = val[2];
    }
  }
  if (f) {
    cout << x[0] << endl;
    for (i = 0; i < x[0]; i++) {
      for (j = 0; j < x[0]; j++) cout << (char)('A' + mask[i][j]);
      cout << endl;
    }
  } else
    cout << -1;
  return 0;
}
