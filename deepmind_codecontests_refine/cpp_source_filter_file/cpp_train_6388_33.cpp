#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
int main(void) {
  int n, t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    if (n < 3)
      cout << n - 1 << endl;
    else
      cout << n - 2 << endl;
  }
  return 0;
}
