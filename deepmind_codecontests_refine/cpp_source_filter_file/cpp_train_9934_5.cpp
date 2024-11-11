#include <bits/stdc++.h>
using namespace std;
int main() {
  string x;
  string y;
  cin >> x;
  cin >> y;
  int v = 0;
  int v1 = 0;
  int m = 0;
  int m1 = 0;
  v += 10 * (int(x[0]) - 48) + 1 * (int(x[1]) - 48);
  m += 10 * (int(x[3]) - 48) + 1 * (int(x[4]) - 48);
  v1 += 10 * (int(y[0]) - 48) + 1 * (int(y[1]) - 48);
  m1 += 10 * (int(y[3]) - 48) + 1 * (int(y[4]) - 48);
  if (v <= v1) {
    v += 24;
    if (m < m1) {
      v = v - 1;
      m += 60;
    }
  }
  if (m < m1) {
    v = v - 1;
    m += 60;
  }
  if (v - v1 == 24) {
    if (m - m1 < 10) {
      cout << "00" << ':' << '0' << m - m1;
    } else {
      cout << "00" << ':' << m - m1;
    }
  } else {
    if (m - m1 < 10 && v - v1 < 10) {
      cout << '0' << v - v1 << ':' << '0' << m - m1;
    }
    if (v - v1 < 10 && m - m1 >= 10) {
      cout << '0' << v - v1 << ':' << m - m1;
    }
    if (v - v1 > 10 && m - m1 > 10) {
      cout << v - v1 << ':' << m - m1;
    }
    if (v - v1 > 10 && m - m1 < 10) {
      cout << v - v1 << ':' << '0' << m - m1;
    }
  }
}
