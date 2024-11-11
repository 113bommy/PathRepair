#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i;
  cin >> n >> k;
  if (k == 1 || k == n) {
    cout << 3 * n << endl;
    return 0;
  } else {
    int sum = 0, flag = 0;
    if (k & 1) {
      if (k >= n / 2 + 1) {
        flag = 1;
      }
    } else {
      if (k > n / 2) {
        flag = 1;
      }
    }
    if (flag == 0) {
      int cnt = 0;
      for (i = k; i >= 1; i--) {
        if (cnt == 1) {
          sum += 4;
        } else {
          sum += 3;
        }
        cnt++;
      }
      sum--;
      sum += k;
      for (i = k + 1; i <= n; i++) {
        sum += 3;
      }
      sum--;
      cout << sum << endl;
      return 0;
    } else {
      int cnt = 0;
      for (i = k; i <= n; i++) {
        if (cnt == 1) {
          sum += 4;
        } else {
          sum += 3;
        }
        cnt++;
      }
      sum--;
      sum += (n + 1 - k);
      for (i = k - 1; i >= 1; i--) {
        sum += 3;
      }
      sum--;
      cout << sum << endl;
      return 0;
    }
  }
  return 0;
}
