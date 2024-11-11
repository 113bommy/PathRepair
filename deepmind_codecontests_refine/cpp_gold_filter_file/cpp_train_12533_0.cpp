#include <bits/stdc++.h>
using namespace std;
int main(void) {
  string s;
  getline(cin, s);
  vector<uint8_t> c('J' - 'A' + 1);
  uint64_t r1 = 1;
  for (size_t i = 0; i < s.size(); i++) {
    if (s[i] == '?') {
      r1 *= 10;
    } else if (s[i] >= 'A' && s[i] <= 'J') {
      c[s[i] - 'A'] = 1;
    }
  }
  if (r1) {
    if (s[0] == '?') {
      if (r1 == 1) {
        r1 = 9;
      } else {
        r1 = r1 / 10 * 9;
      }
    }
  }
  uint64_t cq = 0;
  for (size_t i = 0; i < c.size(); i++) {
    if (c[i]) {
      cq++;
    }
  }
  uint64_t r2 = 1;
  if (cq) {
    if (s[0] >= 'A' && s[0] <= 'J') {
      if (cq == 1) {
        r2 = 9;
      } else {
        cq--;
        r2 = 9;
        uint64_t k = 9;
        while (cq--) {
          r2 *= k;
          k--;
        }
      }
    } else {
      uint64_t k = 10;
      while (cq--) {
        r2 *= k;
        k--;
      }
    }
  }
  if (r1 == 1 && r2 == 1) {
    cout << 1;
  } else if (r1 != 1 && r2 == 1) {
    cout << r1;
  } else if (r1 == 1 & r2 != 1) {
    cout << r2;
  } else {
    cout << (r1 * r2);
  }
  return 0;
}
