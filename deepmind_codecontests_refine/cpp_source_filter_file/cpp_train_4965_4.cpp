#include <bits/stdc++.h>
using namespace std;
struct oly {
  int a, b;
};
int main() {
  long long n;
  cin >> n;
  long long l, r;
  l = 1;
  r = n;
  long long p;
  long long f;
  long long z, z1;
  while (r - l > 1) {
    p = (l + r + 1) / 2;
    f = n;
    z = 0;
    z1 = 0;
    while (f != 0) {
      if (p > f) {
        z += f;
        break;
      }
      z += p;
      f -= p;
      z1 += f / 9;
      f -= f / 9;
    }
    f = n;
    if (f % 2 == 1) f += 1;
    if (z >= f / 2) {
      r = p;
    } else {
      l = p;
    }
  }
  p = l;
  f = n;
  z = 0;
  z1 = 0;
  while (f != 0) {
    if (p > f) {
      z += f;
      break;
    }
    z += p;
    f -= p;
    z1 += f / 9;
    f -= f / 9;
  }
  f = n;
  if (f % 2 == 1) ++f;
  if (z >= f / 2)
    cout << l;
  else
    cout << r;
  return 0;
}
