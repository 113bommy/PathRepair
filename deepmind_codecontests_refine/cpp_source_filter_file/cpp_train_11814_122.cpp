#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) {
  int t;
  if (a >= b)
    return a;
  else
    return b;
}
int min(int a, int b) {
  int t;
  if (a <= b)
    return a;
  else
    return b;
}
int main() {
  int m, n;
  int t;
  cin >> m >> n;
  if (m % 2 == 0 || n % 2 == 0) {
    if (m % 2 != 0) {
      t = m;
      m = n;
      n = t;
    }
    t = m / 2 * n;
    cout << t;
    return 0;
  } else {
    if (m == 1 && n == 1) {
      cout << "1";
      return 0;
    } else {
      t = (max(m, n) - 1) / 2 * min(m, n) + (min(m, n) - 1) / 2;
      cout << t;
      return 0;
    }
  }
}
