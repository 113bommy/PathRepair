#include <bits/stdc++.h>
using namespace std;
int a[4], b[4];
int main() {
  string d;
  cin >> d;
  int x = 0, y = 0;
  int l = 0;
  for (int i = 0; d[i]; i++) {
    int ll = d[i] - '0';
    if (d[i] != ':') {
      b[l] = ll;
      a[l++] = ll;
    }
  }
  int z = 1;
  while (z) {
    if (a[0] == a[3] && a[1] == a[2]) {
      z = 0;
      break;
    }
    a[3]++;
    if (a[3] >= 10) {
      a[3] = 0;
      a[2]++;
    }
    if (a[2] >= 6) {
      a[2] = 0;
      a[1]++;
    }
    if (a[0] == 2 && a[1] >= 4) {
      a[0] = 0;
      a[1] = 0;
    }
    if (a[1] >= 10) {
      a[1] = 0;
      a[0]++;
    }
    x++;
  }
  z = 1;
  while (z) {
    if (b[0] == b[3] && b[1] == b[2]) {
      z = 0;
      break;
    }
    b[3]--;
    if (b[3] < 0) {
      b[3] = 0;
      b[2]--;
    }
    if (b[2] < 0) {
      b[2] = 5;
      b[1]--;
    }
    if (b[0] == 0 && b[1] < 0) {
      b[0] = 2;
      b[1] = 3;
    }
    if (b[1] < 0) {
      b[1] = 9;
      b[0]--;
    }
    y++;
  }
  cout << min(x, y) << endl;
}
