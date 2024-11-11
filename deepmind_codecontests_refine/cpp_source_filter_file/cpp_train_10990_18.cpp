#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, d, i, j, k;
  cin >> m >> d;
  int ans;
  if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
    if (d == 1)
      ans = 5;
    else if (d == 2)
      ans = 5;
    else if (d == 3)
      ans = 5;
    else if (d == 4)
      ans = 5;
    else if (d == 5)
      ans = 5;
    else if (d == 6)
      ans = 6;
    else if (d == 7)
      ans = 6;
  } else if (m == 2) {
    if (d == 1)
      ans = 5;
    else if (d == 2)
      ans = 5;
    else if (d == 3)
      ans = 5;
    else if (d == 4)
      ans = 5;
    else if (d == 5)
      ans = 5;
    else if (d == 6)
      ans = 5;
    else if (d == 7)
      ans = 5;
  } else if (m == 4 || m == 6 || m == 9 || m == 11) {
    if (d == 1)
      ans = 5;
    else if (d == 2)
      ans = 5;
    else if (d == 3)
      ans = 5;
    else if (d == 4)
      ans = 5;
    else if (d == 5)
      ans = 5;
    else if (d == 6)
      ans = 5;
    else if (d == 7)
      ans = 6;
  }
  cout << ans;
  return 0;
}
