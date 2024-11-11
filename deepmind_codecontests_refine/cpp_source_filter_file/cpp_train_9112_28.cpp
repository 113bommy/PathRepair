#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  double k;
  cin >> n >> k;
  k = (100.0 - k) / 100.0;
  double a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  double begin = 0.00000001;
  double end = *max_element(a, a + n);
  while (end - begin > 0.00000001) {
    double left = (end + begin) / 2.0;
    double inpiu = 0, inmeno = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > left) {
        inpiu += a[i] - left;
      } else {
        inmeno = left - a[i];
      }
    }
    if (inpiu * k >= inmeno) {
      begin = left;
    } else {
      end = left;
    }
  }
  cout << setprecision(10) << fixed << begin;
}
