#include <bits/stdc++.h>
using namespace std;
long int n, m, x, j, a, b, c, p, l, r, s, t, y;
string s1, s2;
int main() {
  cin >> a >> b >> p;
  m = min(a, p);
  long long k, i;
  for (i = 0; i < m; i++) {
    k = (i * 100000000) % p;
    if (k == 0) {
      continue;
    }
    l = p - k;
    if (l > b) {
      cout << 1 << " ";
      cout.width(9);
      cout.fill('0');
      cout << i;
      return 0;
    } else {
      continue;
    }
  }
  cout << 2 << endl;
  return 0;
}
