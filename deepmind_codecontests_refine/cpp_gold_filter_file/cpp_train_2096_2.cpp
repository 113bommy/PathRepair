#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long int n;
  cin >> n;
  long long int q = 0;
  long long t1, t2;
  for (int i = 0; i < n; i++) {
    cin >> q;
    long long int g = gcd(180, q);
    t1 = 180;
    t2 = q;
    while ((t1 - t2) < 2) {
      t1 *= 2;
      t2 *= 2;
    }
    while (gcd(t1, t2) != 1 && (t1 - t2) >= 2) {
      g = gcd(t1, t2);
      t1 = t1 / g;
      t2 = t2 / g;
      if (t1 - t2 < 2) {
        t1 = t1 * 2;
        t2 = t2 * 2;
        break;
      }
    }
    cout << t1 % 998244353 << "\n";
  }
  return 0;
}
