#include <bits/stdc++.h>
using namespace std;
int n, x, c, i, j, cif, p, c1;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    x = i;
    c = 0;
    while (x != 0) {
      c++;
      x = x / 10;
    }
    j = j + c;
    cif = c;
    if (j >= n) {
      c = cif - (n - c1) + 1;
      p = 1;
      while (c != 0) {
        p = p * 10;
        c--;
      }
      cout << (i % p) / (p / 10);
      break;
    }
    c1 = j;
  }
}
