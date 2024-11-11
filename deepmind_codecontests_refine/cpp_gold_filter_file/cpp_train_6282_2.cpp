#include <bits/stdc++.h>
using namespace std;
int gcd(int u, int v);
int main() {
  int n, m, x, u, v, temp, sign;
  cin >> n >> m;
  int a[n + 1], b[m + 1];
  for (int i = 0; i < n + 1; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m + 1; i++) {
    cin >> b[i];
  }
  if (n > m) {
    if ((a[0] > 0 && b[0] > 0) || (a[0] < 0 && b[0] < 0)) {
      cout << "Infinity" << endl;
      return 0;
    } else {
      cout << "-Infinity" << endl;
      return 0;
    }
  } else if (n < m) {
    cout << "0/1" << endl;
    return 0;
  } else {
    if ((a[0] > 0 && b[0] > 0) || (a[0] < 0 && b[0] < 0)) {
      if (a[0] < 0) {
        u = -a[0];
        v = -b[0];
      } else {
        u = a[0];
        v = b[0];
      }
      x = gcd(u, v);
      sign = 1;
    } else {
      if (a[0] > 0 && b[0] < 0) {
        u = a[0];
        v = -b[0];
      } else {
        u = -a[0];
        v = b[0];
      }
      x = gcd(u, v);
      sign = 0;
    }
  }
  if (sign) {
    cout << u / x << "/" << v / x << endl;
  } else {
    cout << "-" << u / x << "/" << v / x << endl;
  }
  return 0;
}
int gcd(int u, int v) {
  int temp;
  while (v != 0) {
    temp = u % v;
    u = v;
    v = temp;
  }
  return u;
}
