#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long a[n];
  long long int sum = 0;
  int ev = 0, od = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 0)
      ev++;
    else
      od++;
  }
  if (od == 0 || ev == 0) {
    std::sort(a, a + n);
    for (int i = 0; i < n - 1; i++) {
      sum += a[i];
    }
    cout << sum;
    return 0;
  }
  if (n % 2 == 0 && ev == n / 2) {
    cout << "0";
    return 0;
  } else if (n % 2 != 0 &&
             (ev > od && ev - od == 1 || od > ev && od - ev == 1)) {
    cout << "0";
    return 0;
  } else {
    std::sort(a, a + n);
    int dif = 0;
    if (ev > od) {
      int dif = ev - od;
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0 && cnt < dif - 1) {
          sum += a[i];
          cnt++;
        }
      }
    } else {
      int dif = od - ev;
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0 && cnt < dif - 1) {
          sum += a[i];
          cnt++;
        }
      }
    }
    cout << sum << endl;
    return 0;
  }
}
