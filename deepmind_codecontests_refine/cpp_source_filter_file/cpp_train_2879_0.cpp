#include <bits/stdc++.h>
using namespace std;
long calc(long a, long op, long b) {
  if (op == '+') {
    long sub = -5, bb = b;
    while (bb >= 10) {
      sub *= 10;
      bb /= 10;
    }
    return a + b + sub;
  }
  if (op == '-') {
    long add = 3, bb = b;
    while (bb >= 10) {
      add *= 10;
      bb /= 10;
    }
    return a - b + add;
  }
}
int main(void) {
  string s;
  cin >> s;
  long numprev = -1, numnow = 0;
  long op = 0;
  for (const auto &ch : s) {
    if ('0' <= ch && ch <= '9') {
      numnow = numnow * 10 + ch - '0';
    } else if (ch == '+') {
      if (op)
        numprev = calc(numprev, op, numnow);
      else
        numprev = numnow;
      op = '+';
      numnow = 0;
    } else if (ch == '-') {
      if (op)
        numprev = calc(numprev, op, numnow);
      else
        numprev = numnow;
      op = '-';
      numnow = 0;
    }
  }
  if (op)
    numprev = calc(numprev, op, numnow);
  else
    numprev = numnow;
  op = '-';
  numnow = 0;
  cout << numprev << endl;
}
