#include <bits/stdc++.h>
using namespace std;
using INT = long long;
const int NN = 5e5 + 10;
char s[NN];
int a[NN];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf(" %c %d", s + i, a + i);
  }
  int sor = 0, sand = (1 << 10) - 1, sxor = 0;
  for (int i = 0; i < 10; i++) {
    int st1 = (1 << i);
    int st0 = 0;
    for (int j = 1; j <= n; j++) {
      int x = 0;
      if ((a[j] >> i) & 1) x = (1 << i);
      if (s[j] == '|') st1 |= x, st0 |= x;
      if (s[j] == '&') st1 &= x, st0 &= x;
      if (s[j] == '^') st1 ^= x, st0 ^= x;
    }
    if (st1 and st0) {
      sor ^= (1 << i);
    }
    if (!st1 and st0) {
      sxor ^= (1 << i);
    }
    if (st1 and !st0) {
      sand ^= (1 << i);
    }
  }
  cout << 3 << endl;
  cout << "|" << ' ' << sor << endl;
  cout << "&" << ' ' << sand << endl;
  cout << "^" << ' ' << sxor << endl;
}
