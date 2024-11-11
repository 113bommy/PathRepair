#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, flag = 0, cnt1 = 0, cnt2 = 0, low = 0, high = INT_MAX;
  cin >> n;
  int c[n + 1], d[n + 1];
  for (int i = 1; i <= n; i++) cin >> c[i] >> d[i];
  for (int i = 1; i <= n - 1; i++) {
    if (d[i] == 1) {
      if (c[i] >= 0 && d[i + 1] == 2) {
        cout << "Impossible";
        flag = 1;
        break;
      }
    }
    if (d[i] == 2) {
      if (c[i] <= 0 && d[i + 1] == 1) {
        cout << "Impossible";
        flag = 1;
        break;
      }
    }
  }
  if (flag == 0) {
    for (int i = 1; i <= n; i++) {
      if (d[i] == 1) cnt1++;
    }
    if (cnt1 == n) {
      cout << "Infinity";
      flag = 1;
    }
  }
  if (flag == 0) {
    int ps[n + 1];
    ps[1] = 0;
    for (int i = 2; i <= n; i++) ps[i] = ps[i - 1] + c[i - 1];
    for (int i = 1; i <= n; i++) {
      if (d[i] == 1) {
        low = max(low, 1900 - ps[i]);
      }
      if (d[i] == 2) {
        high = min(high, 1899 - ps[i]);
      }
    }
    if (low <= high) {
      int sum = high;
      for (int i = 1; i <= n; i++) sum += c[i];
      cout << sum;
    } else
      cout << "Impossible";
  }
}
