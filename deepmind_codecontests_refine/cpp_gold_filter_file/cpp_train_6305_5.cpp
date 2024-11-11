#include <bits/stdc++.h>
using namespace std;
int main() {
  long long A, B, C, K;
  cin >> A >> B >> C >> K;
  if (A > B) swap(A, B);
  if (A > C) swap(A, C);
  if (B > C) swap(B, C);
  long long X = 1, Y = 1, Z = 1;
  for (; X + Y + Z < A + B + C && K > 0;) {
    if (X < A) {
      int D = A - X;
      if (3 * D <= K) {
        X += D;
        Y += D;
        Z += D;
        K -= 3 * D;
      } else {
        D = K / 3;
        X += D;
        Y += D;
        Z += D;
        K -= 3 * D;
        if (K > 0) X++, K--;
        if (K > 0) Y++, K--;
      }
    } else if (Y < B) {
      int D = B - Y;
      if (2 * D <= K) {
        Y += D;
        Z += D;
        K -= 2 * D;
      } else {
        D = K / 2;
        Y += D;
        Z += D;
        K -= 2 * D;
        if (K > 0) Y++, K--;
      }
    } else {
      int D = C - Z;
      if (D <= K) {
        Z += D;
        K -= D;
      } else {
        D = K;
        Z += D;
        K -= D;
      }
    }
  }
  cout << X * Y * Z << endl;
  return 0;
}
