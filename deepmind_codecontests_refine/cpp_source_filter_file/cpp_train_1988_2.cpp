#include <bits/stdc++.h>
using namespace std;
int n;
int f(int x) {
  int a, b;
  cout << "? " << x << endl;
  cin >> a;
  cout << "? " << x + n / 2 << endl;
  cin >> b;
  return a - b;
}
int main() {
  cin >> n;
  int L = 1;
  int R = n / 2;
  int Lf = f(1);
  int Rf = -Lf;
  if (Lf & 1) return cout << "! -1\n", 0;
  if (Lf == 0) return cout << "! 1\n", 0;
  while (L <= R) {
    int m = (L + R + 1) / 2;
    int val = f(m);
    if (val == 0) return cout << "! " << m << "\n", 0;
    if (val == Lf)
      L = m + 1;
    else
      R = m - 1;
  }
  return cout << "! 1\n", 0;
}
