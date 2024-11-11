#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1.0);
void fun() {
  long long i, j, flag = 0, d1, d2, maxz = 0, q, a, b, x1, y1;
  string o;
  long long n, p;
  cin >> a >> b;
  for (i = 1; i < a; i++) {
    if (sqrt(a * a - i * i) * sqrt(a * a - i * i) + i * i == a * a) {
      x1 = i;
      y1 = sqrt(a * a - i * i);
      for (j = 1; j < b; j++) {
        if ((x1 * j) % y1 != 0) continue;
        if (j * j + ((x1 * j) / y1) * ((x1 * j) / y1) == b * b && i != j) {
          cout << "YES" << endl;
          cout << "0 0" << endl;
          cout << x1 << " " << y1 << endl;
          cout << j << " " << (x1 * j) / y1 << endl;
          return;
        }
      }
    }
  }
  cout << "NO" << endl;
}
int main() {
  long long t, n, k, i;
  t = 1;
  for (long long i = 1; i <= t; i++) fun();
}
