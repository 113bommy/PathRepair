#include <bits/stdc++.h>
using namespace std;
int main() {
  long int len, check = 1, c, i, y, a[10];
  cin >> y;
  y++;
  while (check) {
    c = y;
    for (i = 0; c > 0; i++) {
      a[i] = c % 10;
      c /= 10;
    }
    sort(a, a + (i));
    len = i;
    for (i = 0; i < len; i++) {
      if (a[i] == a[i + 1])
        break;
      else if (i == len - 1) {
        cout << y;
        check = 0;
      }
    }
    y++;
  }
  return 0;
}
