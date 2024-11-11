#include <bits/stdc++.h>
using namespace std;
const int inf = 100000005;
int err, ln;
int gcd(int a, int b) {
  if (b != 0) err += (a / b - ((a < b) ? 0 : 1)), ln += a / b;
  return b ? gcd(b, a % b) : a;
}
char buf[1000005];
int len;
int errs(int r, int i) {
  int j = 0;
  while (true) {
    if (r >= i) {
      r -= i;
      buf[++j] = 'T';
    } else {
      i -= r;
      buf[++j] = 'B';
    }
    if (r == 0 && i == 1) break;
  }
  reverse(buf + 1, buf + j + 1);
  int res = 0;
  len = j;
  for (int f = 1; f < j; f++) res += buf[f] == buf[f + 1];
  if (buf[0] == 'B') res = inf;
  return res;
}
int main() {
  int n, r, i, j, m, g = -1, mn = 1000005, x, y;
  cin >> n >> r;
  for (i = 2; i < r; i++) {
    err = ln = 0;
    if (gcd(r, i) == 1) {
      if (ln == n) {
        int e = errs(r, i);
        if (e < mn) mn = e, x = r, y = i;
      }
    }
  }
  for (i = 2; i < r; i++) {
    err = ln = 0;
    if (gcd(i, r) == 1) {
      if (ln == n) {
        int e = errs(i, r);
        if (e < mn) mn = e, x = i, y = r;
      }
    }
  }
  if (mn = 1000005) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  cout << errs(x, y) << endl;
  for (i = 1; i <= len; i++) cout << buf[i];
  return 0;
}
