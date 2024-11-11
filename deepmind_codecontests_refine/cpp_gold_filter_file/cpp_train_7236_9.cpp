#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
long long powmod(long long a, long long b) {
  long long res = 1;
  if (a >= mod) a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    if (res >= mod) res %= mod;
    a = a * a;
    if (a >= mod) a %= mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long x1, x2, x3, y1, y2, y3, xmax, xmin, ymax, ymin;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  if (x1 == x2 && x1 == x3)
    cout << "1";
  else if (y1 == y2 && y1 == y3)
    cout << "1";
  else if (x1 == x2) {
    ymax = max(y1, y2);
    ymin = min(y1, y2);
    if (y3 >= ymax || y3 <= ymin)
      cout << "2";
    else
      cout << "3";
  } else if (y1 == y2) {
    xmax = max(x1, x2);
    xmin = min(x1, x2);
    if (x3 >= xmax || x3 <= xmin)
      cout << "2";
    else
      cout << "3";
  } else if (x3 == x2) {
    ymax = max(y3, y2);
    ymin = min(y3, y2);
    if (y1 >= ymax || y1 <= ymin)
      cout << "2";
    else
      cout << "3";
  } else if (y3 == y2) {
    xmax = max(x3, x2);
    xmin = min(x3, x2);
    if (x1 >= xmax || x1 <= xmin)
      cout << "2";
    else
      cout << "3";
  } else if (x1 == x3) {
    ymax = max(y1, y3);
    ymin = min(y1, y3);
    if (y2 >= ymax || y2 <= ymin)
      cout << "2";
    else
      cout << "3";
  } else if (y1 == y3) {
    xmax = max(x1, x3);
    xmin = min(x1, x3);
    if (x2 >= xmax || x2 <= xmin)
      cout << "2";
    else
      cout << "3";
  } else
    cout << "3";
}
