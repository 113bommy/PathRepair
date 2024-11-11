#include <bits/stdc++.h>
using namespace std;
long long t, w, b;
long long q, z, tmp;
long long gcd(long long a, long long c) {
  while (c) {
    a %= c;
    swap(a, c);
  }
  return a;
}
long long lcm(long long a, long long c) { return a / gcd(a, c) * c; }
int main() {
  cin >> t >> w >> b;
  if (w == 1 && b == 1) {
    cout << "1/1\n";
    return 0;
  }
  if (w > t && b > t) {
    cout << "1/1\n";
    return 0;
  }
  if (w > t) {
    z = gcd(b - 1, t);
    q = (b - 1) / z;
    z = t / z;
    cout << q << "/" << z << "\n";
    return 0;
  }
  if (b > t) {
    z = gcd(w - 1, t);
    q = (w - 1) / z;
    z = t / z;
    cout << q << "/" << z << "\n";
    return 0;
  }
  if (w == b) {
    cout << "1/1\n";
    return 0;
  }
  tmp = min(w, b);
  tmp--;
  z = gcd(w, b);
  q = w / z;
  z = b / z;
  if (((5000000000000000000 / z) / w) != 0) {
    long long x = z * w;
    if (t % x == 0) {
      tmp = ((t / x) * (tmp + 1));
    } else
      tmp = ((t / x) * (tmp + 1)) - 1 + min(min(w, b), t % x + 1);
    z = gcd(tmp, t);
    q = tmp / z;
    z = t / z;
    cout << q << "/" << z << "\n";
  } else {
    z = gcd((min(w, b) - 1), t);
    q = (min(w, b) - 1) / z;
    z = t / z;
    cout << q << "/" << z << "\n";
  }
  return 0;
}
