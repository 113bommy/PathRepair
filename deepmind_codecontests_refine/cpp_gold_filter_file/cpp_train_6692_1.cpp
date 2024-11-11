#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  int z;
  int k;
  int i[4] = {1, 11, 111, 1111};
  cin >> t;
  for (int y = 0; y <= t - 1; y++) {
    int k = 0;
    cin >> z;
    for (int a = 1; a <= 9; a++) {
      if ((a * i[0]) != z) {
        k += 1;
      } else {
        k += 1;
        break;
      }
      if ((a * i[1]) == z) {
        k += 2;
        break;
      } else {
        k += 2;
      }
      if ((a * i[2]) == z) {
        k += 3;
        break;
      } else {
        k += 3;
      }
      if ((a * i[3]) == z) {
        k += 4;
        break;
      } else {
        k += 4;
      }
    }
    cout << k << endl;
  }
  return 0;
}
