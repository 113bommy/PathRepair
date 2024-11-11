#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, sum = 0, k = 0, min = 100;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> j;
    if (j % 2 != 0) {
      k++;
      if (j < min) {
        min = j;
      }
    }
    sum += j;
  }
  if (k == 0) {
    cout << 0;
  } else {
    if (k % 2 != 0) {
      sum -= min;
    }
    cout << sum;
  }
  return 0;
}
