#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, j, len, f[6] = {1, 2, 3, 4, 6, 12}, u, k, i1, i2, flag = 0,
                    count1 = 0, u1, count2 = 0, k1 = 0, u2, array1[100],
                    array2[100], k2;
  char a[1000];
  cin >> t;
  for (i = 0; i < t; i++) {
    scanf("%s", a);
    k = 1;
    k1 = 0;
    count1 = 0;
    count2 = 0;
    for (u1 = 0; u1 < 12; u1++) {
      if (a[u1] == 'X') {
        count1++;
      }
    }
    if (count1 == 0) {
      cout << "0" << endl;
    } else if (count1 == 12) {
      cout << "6 1x12 2x6 3x4 4x3 6x2 12x1" << endl;
    } else {
      for (i1 = f[k]; k < 6; k++) {
        i1 = f[k];
        flag = 0;
        for (i2 = 0; i2 < i1; i2++) {
          flag = 0;
          for (j = i2; j < 12; j = j + i1) {
            if (a[j] != 'X') {
              flag = 1;
              break;
            }
          }
          if (flag == 0) {
            count2++;
            array1[k1] = i1;
            array2[k1] = 12 / i1;
            k1++;
            break;
          }
        }
      }
      cout << count2 << " ";
      for (u2 = k1 - 1; u2 >= 0; u2--) {
        cout << array2[u2] << "x" << array1[u2] << " ";
      }
      cout << endl;
    }
  }
}
