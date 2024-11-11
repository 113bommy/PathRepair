#include <bits/stdc++.h>
using namespace std;
long long int k;
long long int mat[1001][1001];
int main() {
  long long int i, j, a, b, c, p, q, cnt, d;
  scanf("%ld", &k);
  p = 3;
  q = INT_MIN;
  cnt = 0;
  while (k > 0) {
    a = 1;
    b = 0;
    while (a * 2 <= k) {
      b++;
      a *= 2;
    }
    q = q > b ? q : b;
    d = q - b;
    if (cnt == 0) {
      if (b == 0) {
        mat[1][2] = mat[2][1] = 1;
      } else {
        for (i = 1; i <= b; ++i) {
          if (i == 1) {
            mat[1][p] = mat[p][1] = 1;
            mat[1][p + 1] = mat[p + 1][1] = 1;
            p += 2;
            continue;
          }
          mat[p - 2][p] = mat[p - 1][p] = mat[p][p - 2] = mat[p][p - 1] = 1;
          mat[p - 2][p + 1] = mat[p - 1][p + 1] = mat[p + 1][p - 2] =
              mat[p + 1][p - 1] = 1;
          p += 2;
        }
        mat[p - 2][2] = mat[2][p - 2] = 1;
        mat[p - 1][2] = mat[2][p - 1] = 1;
      }
    } else {
      c = 2 * d + 3;
      for (i = 1; i <= d; ++i) {
        if (i == 1) {
          mat[1][p] = mat[p][1] = 1;
        } else {
          mat[p][p - 1] = mat[p - 1][p] = 1;
        }
        p++;
      }
      if (d == q) {
        mat[2][p - 1] = mat[p - 1][2] = 1;
      } else {
        mat[c][p - 1] = mat[p - 1][c] = 1;
        mat[c + 1][p - 1] = mat[p - 1][c + 1] = 1;
      }
    }
    k -= (1 << b);
    cnt++;
  }
  c = p - 1;
  cout << c << "\n";
  for (i = 1; i <= c; ++i) {
    for (j = 1; j <= c; ++j) {
      if (mat[i][j] == 1) {
        cout << 'Y';
      } else {
        cout << 'N';
      }
    }
    cout << "\n";
  }
  return 0;
}
