#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n < 7) {
    if (n == 4)
      cout << "4";
    else
      cout << -1;
    ;
  }
  int sn = n / 7, fn = 0;
  int left = n % 7;
  if (left == 1) {
    sn -= 1;
    fn += 2;
  } else if (left == 2) {
    sn -= 2;
    fn += 4;
  } else if (left == 3) {
    sn -= 3;
    fn += 6;
  } else if (left == 4) {
    fn += 1;
  } else if (left == 5) {
    sn -= 1;
    fn += 3;
  } else if (left == 6) {
    sn -= 2;
    fn += 5;
  }
  if (sn < 0) {
    if (n % 4 == 0) {
      int tt = n / 4;
      for (int i = 1; i <= tt; i++) cout << 4;
    } else
      cout << -1;
  } else {
    for (int i = 1; i <= fn; i++) cout << 4;
    for (int i = 1; i <= sn; i++) cout << 7;
  }
  return 0;
}
