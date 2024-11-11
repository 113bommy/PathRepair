#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int bills[5] = {100, 20, 10, 5, 1};
  int con = 0;
  int total = 0;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  while (true) {
    if (con == 6) {
      con = 0;
    }
    if (n <= 1) {
      cout << total;
      return 0;
    }
    if ((n % bills[con]) == 0 || n > bills[con]) {
      total = total + int(n / bills[con]);
      n = n - (bills[con] * ((int)n / bills[con]));
      con++;
    } else {
      if ((n % 5) != 0) {
        n--;
        total++;
      } else {
        con++;
      }
    }
  }
}
