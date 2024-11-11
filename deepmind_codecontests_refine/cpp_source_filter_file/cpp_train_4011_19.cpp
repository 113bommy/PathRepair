#include <bits/stdc++.h>
using namespace std;
long long int s, x, a, aXORb, aANDb, xorBits[41], andBits[41], xorSize, andSize,
    ans = 1;
int main() {
  cin >> s >> x;
  aANDb = (s - x) / 2;
  aXORb = x;
  a = aANDb;
  if (aANDb * 2 + x != s)
    cout << "0" << endl;
  else {
    while (aXORb) {
      xorBits[xorSize++] = aXORb % 2;
      aXORb /= 2;
    }
    while (aANDb) {
      andBits[andSize++] = aANDb % 2;
      aANDb /= 2;
    }
    for (int i = 0; i < max(xorSize, andSize); ++i) {
      if (xorBits[i] == 0) {
        ans *= 1;
      } else {
        if (andBits[i] == 0) {
          ans *= 2;
        } else {
          ans = 0;
          break;
        }
      }
    }
    if (ans == 0)
      cout << ans << endl;
    else {
      if (x == 0)
        cout << "1" << endl;
      else if (a == 0)
        cout << (ans - 2) << endl;
      else
        cout << ans << endl;
    }
  }
  return 0;
}
