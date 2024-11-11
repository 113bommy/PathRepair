#include <bits/stdc++.h>
using namespace std;
long long int m, l, r, k;
long long int d;
void fib_mat(long long int exp, long long int res[2][2]) {
  if (exp == 0) {
    res[0][0] = 1;
    res[0][1] = 0;
    res[1][0] = 0;
    res[1][1] = 1;
  } else if (exp == 1) {
    res[0][0] = 1;
    res[0][1] = 1;
    res[1][0] = 1;
    res[1][1] = 0;
  } else {
    long long int tmp[2][2];
    long long int halfsq[2][2];
    fib_mat(exp / 2, tmp);
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        halfsq[i][j] = 0;
        for (int k = 0; k < 2; k++) {
          halfsq[i][j] += tmp[i][k] * tmp[k][j];
          halfsq[i][j] %= m;
        }
      }
    }
    fib_mat(exp % 2, tmp);
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        res[i][j] = 0;
        for (int k = 0; k < 2; k++) {
          res[i][j] += tmp[i][k] * halfsq[k][j];
          res[i][j] %= m;
        }
      }
    }
  }
}
long long int fib(long long int n) {
  long long int m[2][2];
  fib_mat(n, m);
  return m[0][1];
}
int main() {
  cin >> m >> l >> r >> k;
  long long int d = (r - l) / (k - 1);
  while ((r / d) - ((l - 1) / d) < k) {
    if (r / d == r / (d - 1) && (l - 1) / d == (l - 1) / (d - 1)) {
      long long int exp = d;
      while (d <= exp ||
             !(r / d == r / (d - exp) && (l - 1) / d == (l - 1) / (d - exp)))
        exp /= 2;
      d -= exp;
    } else
      d--;
  }
  cout << fib(d) % m;
  return 0;
}
