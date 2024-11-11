#include <bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
  int g, i;
  for (i = 1; (i <= x && i <= y); i++) {
    if (x % i == 0 && y % i == 0) g = i;
  }
  return g;
}
int main() {
  int a, b, s, g1, g2, f;
  cin >> a >> b >> s;
  while (s) {
    g1 = gcd(a, s);
    if (g1 <= s) {
      f = 0;
      s = s - g1;
      if (s <= 0) break;
    }
    g2 = gcd(b, s);
    if (g2 <= s) {
      f = 1;
      s = s - g2;
      if (s <= 0) break;
    }
  }
  cout << f;
}
