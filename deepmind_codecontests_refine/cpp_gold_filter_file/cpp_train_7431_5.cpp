#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int numOne;
int main() {
  int parity = 0;
  cin >> s1 >> s2;
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] == '1') {
      parity ^= 1;
      numOne++;
    }
  }
  numOne += parity;
  parity = numOne & 1;
  for (int i = 0; i < s2.size(); i++) {
    if (s2[i] == '0') {
      if (parity == 0) {
        continue;
      } else if (numOne) {
        numOne--;
        parity ^= 1;
      } else {
        printf("NO\n");
        return 0;
      }
    } else {
      if (parity == 1) {
        parity ^= 1;
      } else if (numOne) {
        numOne--;
      } else {
        printf("NO\n");
        return 0;
      }
    }
  }
  printf("YES\n");
  return 0;
}
