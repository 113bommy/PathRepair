#include <bits/stdc++.h>
using namespace std;
int main() {
  int v1, v2, v3, vm;
  int flag;
  while (cin >> v1 >> v2 >> v3 >> vm) {
    flag = 0;
    int i, j, k;
    for (i = 1; i <= 200; i++) {
      for (j = 1; j < i; j++) {
        for (k = 1; k < j; k++) {
          if (2 * v1 >= i && v1 <= i && v2 <= j && 2 * v2 >= j && v3 <= k &&
              2 * v3 >= k && 2 * vm >= k && vm <= k && 2 * vm < j) {
            flag = 1;
            break;
          }
        }
        if (flag) break;
      }
      if (flag) break;
    }
    if (flag) {
      cout << i << endl;
      cout << j << endl;
      cout << k << endl;
    } else {
      cout << "-1" << endl;
    }
  }
  return 0;
}
