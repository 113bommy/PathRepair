#include <bits/stdc++.h>
using namespace std;
long long int a1, b1, a2, b2;
int d1 = 0, d2 = 0, s1 = 0, s2 = 0;
int ans = 0;
bool g(long long int a, long long int b) {
  while (a % 2 == 0) {
    a /= 2;
    d1++;
  }
  while (a % 3 == 0) {
    a /= 3;
    s1++;
  }
  while (b % 2 == 0) {
    b /= 2;
    d2++;
  }
  while (b % 3 == 0) {
    b /= 3;
    s2++;
  }
  if (a == b) return true;
  return false;
}
bool q() { return a1 * b1 == a2 * b2; }
int main() {
  cin >> a1 >> b1;
  cin >> a2 >> b2;
  long long int f = a1 * b1;
  long long int s = a2 * b2;
  if (g(f, s) == false) {
    cout << -1 << endl;
    return 0;
  }
  while (s2 != s1) {
    if (s2 > s1) {
      if (a2 % 3 == 0) {
        a2 /= 3;
        a2 *= 2;
      } else if (b2 % 3 == 0) {
        b2 /= 3;
        b2 *= 2;
      }
      s2--;
      d2++;
      ans++;
      if (q()) {
        cout << ans << endl;
        cout << a1 << " " << b1 << endl << a2 << " " << b2 << endl;
        return 0;
      }
    } else {
      if (a1 % 3 == 0) {
        a1 /= 3;
        a1 *= 2;
      } else if (b1 % 3 == 0) {
        b1 /= 3;
        b1 *= 2;
      }
      s1--;
      d2++;
      ans++;
      if (q()) {
        cout << ans << endl;
        cout << a1 << " " << b1 << endl << a2 << " " << b2 << endl;
        return 0;
      }
    }
  }
  while (d2 != d1) {
    if (d2 > d1) {
      if (a2 % 2 == 0)
        a2 /= 2;
      else if (b2 % 2 == 0)
        b2 /= 2;
      d2--;
      ans++;
      if (q()) {
        cout << ans << endl;
        cout << a1 << " " << b1 << endl << a2 << " " << b2 << endl;
        return 0;
      }
    } else {
      if (a1 % 2 == 0)
        a1 /= 2;
      else if (b1 % 2 == 0)
        b1 /= 2;
      d1--;
      ans++;
      if (q()) {
        cout << ans << endl;
        cout << a1 << " " << b1 << endl << a2 << " " << b2 << endl;
        return 0;
      }
    }
  }
  cout << ans << endl;
  cout << a1 << " " << b1 << endl << a2 << " " << b2 << endl;
  return 0;
}
