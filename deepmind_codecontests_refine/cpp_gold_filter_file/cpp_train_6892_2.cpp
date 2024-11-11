#include <bits/stdc++.h>
using namespace std;
long long t1, t2, x1, x2, t0;
bool ansInit = 0;
long long glAnsOut1, glAnsOut2;
long long ansUp, ansDown;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
bool ls(long long ch1, long long zn1, long long ch2, long long zn2) {
  return ch1 * zn2 < ch2 * zn1;
}
bool eq(long long ch1, long long zn1, long long ch2, long long zn2) {
  return ch1 * zn2 == ch2 * zn1;
}
void updateAns(long long ansOut1, long long ansOut2, long long up,
               long long down) {
  long long tmp = gcd(up, down);
  if (tmp == 0) return;
  up /= tmp;
  down /= tmp;
  if (!ansInit) {
    glAnsOut1 = ansOut1;
    glAnsOut2 = ansOut2;
    ansUp = up;
    ansDown = down;
    ansInit = 1;
  } else {
    if (ls(up, down, ansUp, ansDown)) {
      ansUp = up;
      ansDown = down;
      glAnsOut1 = ansOut1;
      glAnsOut2 = ansOut2;
    } else if (eq(up, down, ansUp, ansDown)) {
      if (ansOut1 + ansOut2 > glAnsOut1 + glAnsOut2) {
        ansUp = up;
        ansDown = down;
        glAnsOut1 = ansOut1;
        glAnsOut2 = ansOut2;
      }
    }
  }
}
bool good(long long y1, long long y2) {
  return t0 * (y1 + y2) <= t1 * y1 + t2 * y2;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> t1 >> t2 >> x1 >> x2 >> t0;
  for (int i = 0; i <= x1; i++) {
    if (good(i, x2)) updateAns(i, x2, i * t1 + x2 * t2, i + x2);
  }
  for (int i = 0; i <= x2; i++) {
    if (good(x1, i)) updateAns(x1, i, x1 * t1 + i * t2, i + x1);
  }
  for (int i = 0; i <= x1; i++) {
    if (!good(i, x2)) continue;
    int l = 0;
    int r = x2;
    while (r - l > 1) {
      int m = (r + l) >> 1;
      if (t0 * (i + m) <= i * t1 + m * t2) {
        r = m;
      } else {
        l = m;
      }
    }
    if (good(i, r)) updateAns(i, r, i * t1 + r * t2, i + r);
  }
  cout << glAnsOut1 << " " << glAnsOut2;
  return 0;
}
