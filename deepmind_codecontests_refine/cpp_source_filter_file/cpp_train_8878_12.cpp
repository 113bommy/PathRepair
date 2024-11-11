#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, k, sum, sum2, i, num[25];
  while (cin >> a >> b) {
    if (a < b) {
      cout << b << endl;
      continue;
    }
    for (i = a;; i++) {
      int j = 0;
      sum = i;
      sum2 = 0;
      while (sum) {
        k = sum % 10;
        if (k == 4 || k == 7) num[j++] = k;
        sum /= 10;
      }
      for (k = j - 1; k >= 0; k--) sum2 = sum2 * 10 + num[k];
      if (sum2 == b) break;
    }
    cout << i << endl;
  }
  return 0;
}
