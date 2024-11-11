#include <bits/stdc++.h>
using namespace std;
unsigned long long pow2[64];
void calcpow() {
  for (int i = 0; i < 64; i++) {
    pow2[i] = 1;
    pow2[i] <<= i;
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  calcpow();
  unsigned long long A, B, X, Y;
  cin >> A >> B;
  X = B;
  Y = 0;
  for (int i = 63; i >= 0; i--) {
    unsigned long long k = (X ^ pow2[i]) + (Y ^ pow2[i]);
    if (k <= A && k > (X + Y)) {
      X = (X ^ pow2[i]);
      Y = (Y ^ pow2[i]);
    } else if (k >= A && k < (X + Y)) {
      X = (X ^ pow2[i]);
      Y = (Y ^ pow2[i]);
    }
  }
  if ((X + Y) == A)
    cout << X << " " << Y;
  else
    cout << -1;
}
