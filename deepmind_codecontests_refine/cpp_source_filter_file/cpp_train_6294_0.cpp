#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[3], b[3], c[3];
  int k[3] = {0}, l[3] = {0}, t = 0;
  for (int i = 0; i < 3; i++) {
    cin >> a[i] >> b[i] >> c[i];
    if (b[i] == '<') {
      swap(a[i], c[i]);
    }
    k[a[i] - 65]++;
    l[c[i] - 65]++;
  }
  if (k[0] == 1 || k[1] == 1 || k[2] == 1) {
    if (k[0] == 1) {
      if (l[0] == 1) {
        if (k[1] == 2 && l[1] == 0 && k[2] == 0 && l[2] == 2) {
          t = 1;
          cout << "CAB";
        }
        if (k[1] == 0 && l[1] == 2 && k[2] == 2 && l[2] == 0) {
          t = 1;
          cout << "BAC";
        }
      }
    }
    if (k[1] == 1) {
      if (l[1] == 1) {
        if (k[0] == 2 && l[0] == 0 && k[2] == 0 && l[2] == 2) {
          t = 1;
          cout << "CBA";
        }
        if (k[1] == 0 && l[1] == 2 && k[2] == 2 && l[2] == 0) {
          t = 1;
          cout << "ABC";
        }
      }
    }
    if (k[2] == 1) {
      if (l[2] == 1) {
        if (k[0] == 2 && l[0] == 0 && k[1] == 0 && l[1] == 2) {
          t = 1;
          cout << "BCA";
        }
        if (k[0] == 0 && l[0] == 2 && k[1] == 2 && l[1] == 0) {
          t = 1;
          cout << "ACB";
        }
      }
    }
  }
  if (t == 0) {
    cout << "Impossible";
  }
}
