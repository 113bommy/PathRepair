#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return (!b) ? a : gcd(b, a % b); }
int main() {
  long long n, m, q;
  cin >> n >> m >> q;
  long long qiang = gcd(n, m);
  while (q--) {
    long long a, b, c, d, l1, l2;
    cin >> a >> b >> c >> d;
    if (a == 1) {
      l1 = (b - 1) / (n / qiang);
    }
    if (a == 2) {
      l1 = (b - 1) / (m / qiang);
    }
    if (c == 1) {
      l2 = (d - 1) / (m / qiang);
    }
    if (c == 2) {
      l2 = (d - 1) / (m / qiang);
    }
    if (l1 == l2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
