#include <bits/stdc++.h>
using namespace std;
long n, m;
long a, b;
long gcd(int a, int b) {
  int c;
  while (a != 0) {
    c = a;
    a = b % a;
    b = c;
  }
  return b;
}
int main() {
  cin >> m >> n;
  cout << (5 + 6 * m - 6) * n << endl;
  cout << 1 * n << ' ' << 2 * n << ' ' << 3 * n << ' ' << 5 * n << endl;
  long pizd = 4, t = 7;
  for (int k = 1; k <= m - 1; ++k) {
    while (gcd(pizd, t) != 1 || gcd(pizd, t + 2) != 1 || gcd(pizd, t + 4) != 1)
      pizd += 2;
    cout << n * pizd << ' ' << n * t << ' ' << n * (t + 2) << ' ' << n * (t + 4)
         << endl;
    pizd += 2;
    t += 6;
  }
  return 0;
}
