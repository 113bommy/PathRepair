#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")
const int infi = 1e9 + 7;
const long long infl = 1e18;
const long double eps = 1e-9;
const long double eps1 = 1e-6;
const int mod = (1e9 + 7);
const long long mod1 = 1e9 + 7;
const long long mod2 = 1e9 + 9;
long long rec(long long h, long long i, char c) {
  if (h == 0) {
    return 0;
  }
  long long st1 = 1LL << h;
  long long st = 1LL << (h - 1);
  if (i <= st) {
    if (c == 'L') {
      return rec(h - 1, i, c) + st1 - 1 + 1;
    } else {
      return rec(h - 1, i, 'L') + 1;
    }
  } else {
    i -= st;
    if (c == 'L') {
      return rec(h - 1, i, 'R') + 1;
    } else {
      return rec(h - 1, i, 'R') + 1 + st1 - 1;
    }
  }
}
int main() {
  long long h, n;
  cin >> h >> n;
  cout << rec(h, n, 'R');
  return 0;
}
