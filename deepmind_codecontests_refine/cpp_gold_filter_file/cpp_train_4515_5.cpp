#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  ifstream fin("Text.txt");
  int i, j, k;
  long long a, x, b = 0, n, c = 0, f, d, m, t, matched, nmatched, begin, end;
  cin >> n;
  if (n == 1 || n == 2) {
    cout << n << endl;
    return 0;
  }
  if (n & 1) {
    cout << n * (n - 1) * (n - 2) << endl;
  } else {
    m = (n - 1) * (n - 3);
    x = m;
    for (i = n; i >= 2; i--) {
      x = max(x, (m * i) / gcd(m, i));
    }
    cout << x << endl;
  }
  return 0;
}
