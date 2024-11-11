#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, ans;
char signs[3];
void r1(long long a) { ans = min(ans, a); }
void r2(long long a, long long b) {
  if (signs[2] == '*') {
    r1(a * b);
  } else {
    r1(a + b);
  }
}
void r3(long long a, long long b, long long c) {
  if (signs[1] == '*') {
    r2(a * b, c);
    r2(a * c, b);
    r2(b * c, a);
  } else {
    r2(a + b, c);
    r2(a + c, b);
    r2(b + c, a);
  }
}
void r4(long long a, long long b, long long c, long long d) {
  if (signs[0] == '*') {
    r3(a * b, c, d);
    r3(a * c, b, d);
    r3(a * d, b, c);
    r3(b * c, a, d);
    r3(b * d, a, c);
    r3(c * d, a, b);
  } else {
    r3(a + b, c, d);
    r3(a + c, b, d);
    r3(a + d, b, c);
    r3(b + c, a, d);
    r3(b + d, a, c);
    r3(c + d, a, b);
  }
}
int main() {
  cin >> a >> b >> c >> d >> signs[0] >> signs[1] >> signs[2];
  ans = 1000000001;
  r4(a, b, c, d);
  cout << ans;
  return 0;
}
