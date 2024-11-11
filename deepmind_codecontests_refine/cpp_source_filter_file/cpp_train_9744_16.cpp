#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  float sr = 0, a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    sr += a;
  }
  int left = 0, right = 10;
  while (right - left > 1) {
    int mid = left + (right - left) / 2;
    double w = sr + mid * k, e = n + mid;
    double q = w / e;
    if (int(round(q)) >= k) {
      right = mid;
    } else {
      left = mid;
    }
  }
  double w = sr + left * k, e = n + left;
  double q = w / e;
  if (int(round(q)) >= k) {
    cout << left << endl;
  } else {
    cout << right << endl;
  }
  return 0;
}
