#include <bits/stdc++.h>
using namespace std;
long long NOD(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return NOD(b, a % b);
}
int main() {
  long long c, k, a, b;
  cin >> c >> a >> b;
  if (c % NOD(a, b) != 0) {
    cout << "NO";
    return 0;
  }
  k = NOD(a, b);
  c /= k;
  a /= k;
  b /= k;
  if (c % b == 0) {
    cout << "YES" << endl << 0 << ' ' << c / b;
    return 0;
  }
  if (c % a == 0) {
    cout << "YES" << endl << c / a << ' ' << 0;
    return 0;
  }
  for (int i = 1; i <= c; i++) {
    if ((c - a * i) % b == 0 && c - a * i >= 0) {
      cout << "YES" << endl << i << ' ' << (c - a * i) / b;
      return 0;
    }
    if ((c - b * i) % a == 0 && c - b * i >= 0) {
      cout << "YES" << endl << (c - b * i) / a << ' ' << i;
      return 0;
    }
  }
  cout << "NO";
}
