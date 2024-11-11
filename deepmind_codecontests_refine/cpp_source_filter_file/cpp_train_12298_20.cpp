#include <bits/stdc++.h>
using namespace std;
int P1, P2, P3, T1, T2;
int interval(int r, int l) {
  int t = l - r;
  int sum = 0;
  if (t > T1) {
    sum = T1 * P1;
    t = t - T1;
    if (t > T2) {
      sum = T2 * P2 + sum;
      t = t - T2;
      sum = sum + t * P3;
    } else {
      sum = sum + t * P2;
    }
  } else
    sum = T1 * t;
  return sum;
}
int main() {
  int n;
  cin >> n >> P1 >> P2 >> P3 >> T1 >> T2;
  int left[n], right[n];
  for (int i = 0; i < n; i++) {
    cin >> left[i] >> right[i];
  }
  int sum = 0;
  for (int i = 0;; i++) {
    sum = sum + P1 * (right[i] - left[i]);
    if (i == n - 1)
      break;
    else {
      sum = sum + interval(right[i], left[i + 1]);
    }
  }
  cout << sum;
}
