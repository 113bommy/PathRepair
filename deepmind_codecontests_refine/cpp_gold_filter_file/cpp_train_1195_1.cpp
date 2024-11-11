#include <bits/stdc++.h>
using namespace std;
const int con = 10e6;
int main() {
  long long m;
  long long a1, h1;
  long long x1, y1;
  long long a2, h2;
  long long x2, y2;
  cin >> m;
  cin >> h1 >> a1;
  cin >> x1 >> y1;
  cin >> h2 >> a2;
  cin >> x2 >> y2;
  long long dh = h1;
  long long q = -1;
  for (int i = 0; i < con; i++) {
    if (dh == a1) {
      q = i;
      break;
    }
    dh = (x1 * dh + y1) % m;
  }
  if (q == -1) {
    cout << -1;
    return 0;
  }
  dh = h2;
  long long t = -1;
  for (int i = 0; i < con; i++) {
    if (dh == a2) {
      t = i;
      break;
    }
    dh = (x2 * dh + y2) % m;
  }
  if (t == -1) {
    cout << -1;
    return 0;
  }
  dh = a1;
  long long f = 0;
  for (int i = 0; i < con; i++) {
    if ((dh == a1) && (i > 0)) {
      f = i;
      break;
    }
    dh = (x1 * dh + y1) % m;
  }
  dh = a2;
  long long g = 0;
  for (int i = 0; i < con; i++) {
    if ((dh == a2) && (i > 0)) {
      g = i;
      break;
    }
    dh = (x2 * dh + y2) % m;
  }
  if (q == t) {
    cout << q;
    return 0;
  }
  if ((g == 0) && (f == 0)) {
    cout << -1;
    return 0;
  }
  if (f == 0) {
    if ((q - t) % g == 0) {
      long long b = (q - t) / g;
      if (b >= 0)
        cout << b * g + t;
      else
        cout << -1;
    } else
      cout << -1;
    return 0;
  }
  if (g == 0) {
    if ((t - q) % f == 0) {
      long long k = (t - q) / f;
      if (k >= 0)
        cout << k * f + q;
      else
        cout << -1;
    } else
      cout << -1;
    return 0;
  }
  for (long long b = 0; b < con; b++) {
    if ((t - q + b * g) % f == 0) {
      cout << t + b * g;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
