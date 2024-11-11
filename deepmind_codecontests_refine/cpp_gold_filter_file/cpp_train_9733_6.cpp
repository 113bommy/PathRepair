#include <bits/stdc++.h>
using namespace std;
int mn[10], mx[10];
int main() {
  int n, q1 = 0, q2 = 0, q3 = 0, mn1 = 0, mx1 = 0;
  cin >> n;
  for (int i = 1; i <= 3; i++) {
    cin >> mn[i];
    cin >> mx[i];
    mx1 += mx[i];
    mn1 += mn[i];
  }
  if (abs(n - mn1) <= abs(n - mx1)) {
    q3 = mn[3];
    q2 = mn[2];
    q1 = mn[1];
    while ((q3 + q2 + q1) < n && q1 < mx[1]) {
      q1++;
    }
    while ((q3 + q2 + q1) < n && q2 < mx[2]) {
      q2++;
    }
    while ((q3 + q2 + q1) < n && q3 < mx[3]) {
      q3++;
    }
  } else {
    q3 = mx[3];
    q2 = mx[2];
    q1 = mx[1];
    while ((q3 + q2 + q1) > n && q3 > mn[3]) {
      q3--;
    }
    while ((q3 + q2 + q1) > n && q2 > mn[2]) {
      q2--;
    }
    while ((q3 + q2 + q1) > n && q1 > mn[1]) {
      q1--;
    }
  }
  cout << q1 << " " << q2 << " " << q3;
  return 0;
}
