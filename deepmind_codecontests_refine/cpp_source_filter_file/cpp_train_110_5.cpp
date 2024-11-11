#include <bits/stdc++.h>
using namespace std;
void good() {
  printf("YES\n");
  exit(0);
}
long long A[3][2];
int main() {
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 2; ++j) scanf("%lld", &A[i][j]);
  swap(A[1][0], A[2][0]);
  swap(A[1][1], A[2][1]);
  for (int i = 0; i < 4; ++i) {
    long long int y = A[0][1];
    long long int x = A[0][0];
    A[0][0] = y;
    A[0][1] = -x;
    long long k = A[2][0] - A[0][0];
    long long q = A[2][1] - A[0][1];
    long long tt = A[1][0] * A[1][0] + A[1][1] * A[1][1];
    if (tt != 0) {
      bool f1 = (A[1][0] * q + A[1][1] * k) % tt == 0;
      bool f2 = (A[1][0] * k - A[1][1] * q) % tt == 0;
      if (f1 && f2) good();
    } else {
      if (k == 0 && q == 0) good();
    }
  }
  printf("NO\n");
  return 0;
}
