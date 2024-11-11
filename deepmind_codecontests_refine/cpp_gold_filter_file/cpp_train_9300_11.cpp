#include <bits/stdc++.h>
using namespace std;
long long A[70][2][2], B[2][2], C[2][2];
int main() {
  int i, j, k;
  long long n;
  A[0][0][0] = 3, A[0][0][1] = 1;
  A[0][1][0] = 1, A[0][1][1] = 3;
  for (i = 0; i < 65; i++)
    for (j = 0; j < 2; j++)
      for (k = 0; k < 2; k++)
        A[i + 1][j][k] = (A[i][j][0] * A[i][0][k] + A[i][j][1] * A[i][1][k]) %
                         (1000000007ll);
  B[0][0] = 1, B[1][1] = 1;
  cin >> n;
  for (i = 0; i < 60; i++)
    if (n & (1ll << i)) {
      for (j = 0; j < 2; j++)
        for (k = 0; k < 2; k++)
          C[j][k] =
              (B[j][0] * A[i][0][k] + B[j][1] * A[i][1][k]) % (1000000007ll);
      memcpy(B, C, sizeof(C));
    }
  printf("%I64d\n", B[0][0]);
  return 0;
}
