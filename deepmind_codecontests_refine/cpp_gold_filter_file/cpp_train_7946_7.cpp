#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t1, t2, k;
  cin >> n >> t1 >> t2 >> k;
  int a[n][2];
  double ans[n];
  int mk[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i][0] >> a[i][1];
    mk[i] = i + 1;
  }
  for (int i = 0; i < n; i++) {
    double b1, b2;
    b1 = 0.0;
    b2 = 0.0;
    b1 = (a[i][0] * t1 * 1.0);
    double d1 = 0.0;
    d1 = (b1 * k) / 100.0;
    if (d1 > b1)
      b1 = 0.0;
    else {
      b1 -= d1;
    }
    b1 += a[i][1] * t2;
    b2 = (a[i][1] * t1 * 1.0);
    double d2 = 0.0;
    d2 = (b2 * k) / 100.0;
    if (d2 > b2)
      b2 = 0.0;
    else {
      b2 -= d2;
    }
    b2 += a[i][0] * t2;
    if (b1 > b2) {
      ans[i] = b1;
    } else {
      ans[i] = b2;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (ans[i] < ans[j]) {
        double temp;
        temp = ans[i];
        ans[i] = ans[j];
        ans[j] = temp;
        int tt;
        tt = mk[i];
        mk[i] = mk[j];
        mk[j] = tt;
      }
      if (ans[i] == ans[j]) {
        if (mk[i] > mk[j]) {
          double temp;
          temp = ans[i];
          ans[i] = ans[j];
          ans[j] = temp;
          int tt;
          tt = mk[i];
          mk[i] = mk[j];
          mk[j] = tt;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << mk[i] << " ";
    printf("%.2f", ans[i]);
    cout << "\n";
  }
  return 0;
}
