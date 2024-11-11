#include <bits/stdc++.h>
using namespace std;
long long A, B, C, xx, yy;
long long gcd(long long x, long long y) {
  long long l, r, i, j;
  l = x / y;
  r = x % y;
  if (r == 0) {
    xx = 0;
    yy = 1;
    return y;
  } else {
    i = gcd(y, r);
    j = yy;
    yy = xx - l * yy;
    xx = j;
    return i;
  }
}
long long Abs(long long x) {
  if (x < 0)
    return -x;
  else
    return x;
}
int main() {
  cin >> A >> B >> C;
  long long p, q;
  if (C == 0)
    printf("0 0\n");
  else if (A == 0 && B == 0)
    printf("-1\n");
  else if (A == 0) {
    p = Abs(C);
    q = Abs(B);
    if (p % q == 0)
      cout << 0 << ' ' << (-C / B) << endl;
    else
      printf("-1\n");
  } else if (B == 0) {
    p = Abs(C);
    q = Abs(A);
    if (p % q == 0)
      cout << (-C / A) << ' ' << 0 << endl;
    else
      cout << -1 << endl;
  } else {
    p = Abs(A);
    q = Abs(B);
    if (p < q) swap(p, q);
    long long w = gcd(p, q);
    p = Abs(C);
    if (p % w == 0) {
      xx *= p / w;
      yy *= p / w;
      if (C > 0) {
        if (Abs(A) > Abs(B)) {
          if (A > 0) xx *= -1;
          if (B > 0) yy *= -1;
          cout << xx << ' ' << yy << endl;
        } else {
          if (B > 0) xx *= -1;
          if (A > 0) yy *= -1;
          cout << yy << ' ' << xx << endl;
        }
      } else {
        if (Abs(A) > Abs(B)) {
          if (A < 0) xx *= -1;
          if (B < 0) yy *= -1;
          cout << xx << ' ' << yy << endl;
        } else {
          if (B > 0) xx *= -1;
          if (A > 0) yy *= -1;
          cout << yy << ' ' << xx << endl;
        }
      }
    } else
      cout << -1 << endl;
  }
  return 0;
}
