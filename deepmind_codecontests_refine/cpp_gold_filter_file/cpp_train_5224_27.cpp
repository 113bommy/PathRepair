#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a[11] = {0};
  cin >> n;
  for (int i = 0; i < n; i++) {
    char b;
    cin >> b;
    if (b == 'L') {
      for (int j = 0; j < 10; j++) {
        if (a[j] == 0) {
          a[j] = 1;
          break;
        }
      }
    }
    if (b == 'R') {
      for (int j = 9; j >= 0; j--) {
        if (a[j] == 0) {
          a[j] = 1;
          break;
        }
      }
    }
    if (b < 'Z') {
      a[(b - '0')] = 0;
    }
  }
  for (int i = 0; i < 10; i++) {
    cout << a[i];
  }
}
