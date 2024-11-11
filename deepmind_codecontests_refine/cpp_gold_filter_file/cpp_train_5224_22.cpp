#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a[10] = {0};
  cin >> n;
  string c;
  cin >> c;
  int i = 0;
  while (i < n) {
    if (c[i] == 'L') {
      for (int j = 0; j <= 9; j++)
        if (a[j] == 0) {
          a[j] = 1;
          break;
        }
    } else if (c[i] == 'R') {
      for (int j = 9; j >= 0; j--)
        if (a[j] == 0) {
          a[j] = 1;
          break;
        }
    } else {
      int k = c[i] - 48;
      a[k] = 0;
    }
    i++;
  }
  for (i = 0; i < 10; i++) cout << a[i];
}
