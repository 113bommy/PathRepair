#include <bits/stdc++.h>
using namespace std;
int A, B, X0, Y0, X1, Y1;
int floor(int a, int b) {
  if (a > 0)
    return a / b;
  else
    return -a / b - 1;
}
int main() {
  scanf("%d %d %d %d %d %d", &A, &B, &X0, &Y0, &X1, &Y1);
  int k0, h0, k1, h1;
  k0 = floor(Y0 + X0, 2 * A);
  h0 = floor(Y0 - X0, 2 * B);
  k1 = floor(Y1 + X1, 2 * A);
  h1 = floor(Y1 - X1, 2 * B);
  cout << max(abs(k1 - k0), abs(h0 - h1)) << endl;
  return 0;
}
