#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int n, l = 0, r = 9;
  cin >> n;
  char str[n];
  cin >> str;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == 'L') {
      for (int j = 0; j < 10; j++) {
        if (a[j] == 0) {
          a[j] = 1;
          break;
        }
      }
    } else if (str[i] == 'R') {
      for (int j = 9; j >= 0; j--) {
        if (a[j] == 0) {
          a[j] = 1;
          break;
        }
      }
    } else {
      int x = str[i] - 48;
      a[x] = 0;
    }
  }
  for (int i = 0; i < 10; i++) cout << a[i];
  return 0;
}
