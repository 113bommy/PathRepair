#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, flat, fone, ftwo, cou = 0, flag = 0;
  cin >> n >> ftwo >> fone;
  n -= 2;
  while (n--) {
    cin >> flat;
    if (fone == 0 && ftwo == 1) {
      if (flat == 1) {
        cou++;
        flag = 1;
      }
    }
    ftwo = fone;
    if (flag == 1) {
      fone = 0;
      flag = 0;
    } else
      fone = flat;
  }
  cout << cou;
  return 0;
}
