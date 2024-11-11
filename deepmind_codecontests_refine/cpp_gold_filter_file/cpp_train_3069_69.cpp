#include <bits/stdc++.h>
using namespace std;
long long int x[1000007], y[1000007], z[1000007], n;
string s, S;
int main() {
  {
    long long int a = 0, b = 0, cb = 0, d, e, f, g, i, j, k, l, m, p, q, r, u,
                  w, t, tc, in, mod, loc, diff, val, sz, lo, hi, mid,
                  mn = 2134567891, mx = 0, sum = 0, ans = 0;
    char c;
    for (i = 0; i < 8; i++) {
      for (j = 0; j < 8; j++) {
        cin >> c;
        if (c == 'q') a += 9;
        if (c == 'r') a += 5;
        if (c == 'b') a += 3;
        if (c == 'n') a += 3;
        if (c == 'p') a += 1;
        if (c == 'Q') b += 9;
        if (c == 'R') b += 5;
        if (c == 'B') b += 3;
        if (c == 'N') b += 3;
        if (c == 'P') b += 1;
      }
    }
    if (a == b)
      cout << "Draw\n";
    else if (a > b)
      cout << "Black\n";
    else
      cout << "White\n";
  }
  return 0;
}
