#include <bits/stdc++.h>
using namespace std;
int hcf(int a, int b) {
  int small = a > b ? b : a;
  int great = a > b ? a : b;
  if (small == 0) return great;
  if (great % small == 0) return small;
  return hcf(small, great % small);
}
int main() {
  int A, B, N;
  cin >> A >> B >> N;
  for (int i = 1;; i++) {
    if (i % 2 != 0) {
      int gcd = hcf(A, N);
      N -= gcd;
    } else {
      int gcd = hcf(B, N);
      N -= gcd;
    }
    if (N < 0) {
      if (i % 2 == 0)
        cout << 1;
      else
        cout << 0;
      break;
    }
  }
  return 0;
}
