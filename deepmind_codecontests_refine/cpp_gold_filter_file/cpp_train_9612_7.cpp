#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int D = 0;
long long a[4][4] = {{0, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 0}};
long long b[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
void fexp(int n) {
  while (n != 0) {
    if (n & 1) {
      long long c[4][4] = {0};
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          for (int k = 0; k < 4; k++) {
            c[i][j] += a[i][k] * b[k][j];
            c[i][j] %= MOD;
          }
        }
      }
      memcpy(b, c, sizeof(b));
    }
    long long c[4][4] = {0};
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 4; k++) {
          c[i][j] += a[i][k] * a[k][j];
          c[i][j] %= MOD;
        }
      }
    }
    memcpy(a, c, sizeof(a));
    n >>= 1;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  fexp(n);
  cout << b[D][D] << "\n";
}
