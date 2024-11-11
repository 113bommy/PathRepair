#include <bits/stdc++.h>
using namespace std;
uint64_t log4(uint64_t n) { return log2(n) / 2; }
uint64_t getA(uint64_t triple) {
  if (triple == 0) {
    return 1;
  }
  uint64_t doubleBits;
  if (triple == 1) {
    doubleBits = 1;
  } else {
    doubleBits = log4(triple - 1) + 1;
  }
  uint64_t tripleIndex = triple - (pow(4, doubleBits) - 1) / 3;
  return pow(4, doubleBits) + tripleIndex;
}
uint64_t getB(uint64_t A) {
  uint64_t res = 0;
  uint64_t power = 1;
  while (A > 0) {
    if (A % 4 == 1) {
      res += 2 * power;
    }
    if (A % 4 == 2) {
      res += 3 * power;
    }
    if (A % 4 == 3) {
      res += power;
    }
    power *= 4;
    A /= 4;
  }
  return res;
}
uint64_t getC(uint64_t A) {
  uint64_t res = 0;
  uint64_t power = 1;
  while (A > 0) {
    if (A % 4 == 1) {
      res += 3 * power;
    }
    if (A % 4 == 2) {
      res += power;
    }
    if (A % 4 == 3) {
      res += 2 * power;
    }
    power *= 4;
    A /= 4;
  }
  return res;
}
uint64_t solve(uint64_t n) {
  uint64_t triple = (n - 1) / 3;
  uint64_t A = getA(triple);
  if (n % 3 == 0) {
    return getC(A);
  }
  if (n % 3 == 1) {
    return A;
  }
  return getB(A);
}
int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    uint64_t n;
    cin >> n;
    uint64_t result;
    result = solve(n);
    cout << result << endl;
  }
  return 0;
}
