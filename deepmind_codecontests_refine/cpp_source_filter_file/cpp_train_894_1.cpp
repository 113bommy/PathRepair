#include <bits/stdc++.h>
using namespace std;
bool p[1000] = {};
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
int main() {
  ios::sync_with_stdio(0);
  int n, f, j;
  float aob = 0, tt, a = 0, b = 0, c, d;
  cin >> n;
  for (f = sqrt(n); f < n / 2 + 1; f += 1) {
    for (j = f + 1; j + f < n + 1; j += 1) {
      if (gcd(f, j) == 1 && j + f == n) {
        c = f;
        d = j;
        tt = c / d;
        if (aob < tt) {
          aob = tt;
          a = f;
          b = j;
        }
      }
    }
  }
  cout << a << " " << b << endl;
  return 0;
}
