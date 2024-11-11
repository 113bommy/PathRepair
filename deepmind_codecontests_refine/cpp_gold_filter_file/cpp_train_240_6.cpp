#include <bits/stdc++.h>
using namespace std;
bool gcd(long long a, long long b) {
  if (b == 0 || a == 0) return 0;
  if (b % a == 0) return 1;
  if (!gcd(b % a, a)) return 1;
  if (a & 1) {
    if ((b / a) % 2) return 0;
    return 1;
  }
  b /= a;
  if (b % (a + 1) == 0) return 1;
  b %= a + 1;
  if (b % 2 == 0) return 1;
  return 0;
}
int main() {
  long long a, b;
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (a == 0 || b == 0)
      cout << "Second\n";
    else {
      if (a >= b) {
        long long t = a;
        a = b, b = t;
      }
      if (gcd(a, b))
        cout << "First\n";
      else
        cout << "Second\n";
    }
  }
}
