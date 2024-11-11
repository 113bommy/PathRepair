#include <bits/stdc++.h>
using namespace std;
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (b == 0) return a;
  if (a < b) swap(a, b);
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  unsigned long long a, b;
  unsigned long long ta, tb;
  unsigned long long c, in;
  cin >> n >> a >> b;
  c = gcd(a, b);
  ta = b / c;
  tb = a / c;
  while (n--) {
    cin >> in;
    int ans = -1;
    unsigned long long l = 0;
    unsigned long long r = in * a * b / c;
    while (l <= r) {
      unsigned long long m = (l + r) / 2;
      unsigned long long aa = m / ta;
      unsigned long long bb = m / tb;
      if (aa + bb >= in) {
        if (m - aa * ta < m - bb * tb) {
          ans = 1;
        } else if (m - aa * ta > m - bb * tb) {
          ans = 2;
        } else {
          ans = 0;
        }
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    if (ans == 1) {
      cout << "Vanya" << endl;
    } else if (ans == 2) {
      cout << "Vova" << endl;
    } else if (ans == 0) {
      cout << "Both" << endl;
    } else {
      cout << "error" << endl;
    }
  }
}
