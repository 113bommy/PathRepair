#include <bits/stdc++.h>
using namespace std;
int b[1000][2];
int s[1000][2];
int main() {
  int n, ss;
  cin >> n >> ss;
  char d1;
  int d2, d3;
  int z = 0;
  int q = 0;
  for (int i = 0; i < n; i++) {
    cin >> d1 >> d2 >> d3;
    if (d1 == 'B') {
      b[z][0] = d2;
      b[z++][1] = d3;
    } else {
      s[q][0] = d2;
      s[q++][1] = d3;
    }
  }
  for (int i = 0; i < z - 1; i++) {
    for (int j = i + 1; j < z; j++) {
      if (b[i][0] < b[j][0]) {
        swap(b[i][0], b[j][0]);
        swap(b[i][1], b[j][1]);
      } else if (b[i][0] == b[j][0]) {
        b[i][1] = b[i][1] + b[j][1];
        b[j][0] = -1;
      }
    }
  }
  for (int i = 0; i < q - 1; i++) {
    for (int j = i + 1; j < q; j++) {
      if (s[i][0] > s[j][0]) {
        swap(s[i][0], s[j][0]);
        swap(s[i][1], s[j][1]);
      } else if (s[i][0] == s[j][0]) {
        s[i][1] = s[i][1] + s[j][1];
        s[j][0] = 1000000;
      }
    }
  }
  if (ss >= q) {
    for (int i = q; i >= 0; i--) {
      if (s[i][0] != 1000000) {
        cout << "S " << s[i][0] << " " << s[i][1] << endl;
      }
    }
  } else {
    for (int i = ss - 1; i >= 0; i--) {
      if (s[i][0] != 1000000) {
        cout << "S " << s[i][0] << " " << s[i][1] << endl;
      }
    }
  }
  if (ss >= z) {
    for (int i = 0; i < z; i++) {
      if (b[i][0] == -1) {
        break;
      }
      cout << "B " << b[i][0] << " " << b[i][1] << endl;
    }
  } else {
    for (int i = 0; i < ss; i++) {
      if (b[i][0] == -1) {
        break;
      }
      cout << "B " << b[i][0] << " " << b[i][1] << endl;
    }
  }
  return 0;
}
