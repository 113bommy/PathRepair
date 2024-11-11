#include <bits/stdc++.h>
using namespace std;
const long long MAXM = 20;
const long long MAXN = 1 << MAXM;
int z[MAXN][MAXM];
int x[MAXN][MAXM];
long long c[MAXM][MAXM];
long long a[MAXN];
long long e[MAXN];
long long b[MAXM];
long long temp[MAXM];
long long matrix[MAXM];
long long m, Mod;
void mult_to_matrix() {
  for (long long i = 0; i <= m; i++) {
    temp[i] = 0;
    for (long long j = 0; j <= m; j++) {
      for (long long u = 0; u <= m; u++) {
        if ((j + u) < i || ((j + u) & 1) != (i & 1) ||
            min(j, u) < (j + u - i) / 2) {
          continue;
        }
        temp[i] +=
            (((c[m - i][(j + u - i) / 2] * c[i][j - ((j + u - i) / 2)]) % Mod) *
             ((matrix[j] * matrix[u]) % Mod)) %
            Mod;
        temp[i] %= Mod;
      }
    }
  }
  for (long long i = 0; i <= m; i++) {
    matrix[i] = temp[i];
  }
}
void mult_to_b() {
  for (long long i = 0; i <= m; i++) {
    temp[i] = 0;
    for (long long j = 0; j <= m; j++) {
      for (long long u = 0; u <= m; u++) {
        if ((j + u) < i || ((j + u) & 1) != (i & 1) ||
            min(j, u) < (j + u - i) / 2) {
          continue;
        }
        temp[i] +=
            (((c[m - i][(j + u - i) / 2] * c[i][j - ((j + u - i) / 2)]) % Mod) *
             ((matrix[j] * b[u]) % Mod)) %
            Mod;
        temp[i] %= Mod;
      }
    }
  }
  for (long long i = 0; i <= m; i++) {
    matrix[i] = temp[i];
  }
}
void matrix_pw(long long k) {
  if (k == 1) {
    return;
  }
  matrix_pw(k / 2);
  mult_to_matrix();
  if (k & 1) {
    mult_to_b();
  }
}
void generator(long long k, long long u) {
  if (u == 0) {
    z[k][0] = a[k];
    return;
  }
  generator(k, u - 1);
  generator(k + (1 << (u - 1)), u - 1);
  for (long long i = 0; i < (1 << u); i++) {
    for (long long j = 0; j < u; j++) {
      x[k + i][j] = z[k + i][j];
    }
    x[k + i][u] = 0;
  }
  for (long long i = 0; i < (1 << (u - 1)); i++) {
    for (long long j = 0; j < u; j++) {
      x[k + i][j + 1] += z[k + i + (1 << (u - 1))][j];
      x[k + i][j + 1] %= Mod;
      x[k + i + (1 << (u - 1))][j + 1] += z[k + i][j];
      x[k + i + (1 << (u - 1))][j + 1] %= Mod;
    }
  }
  for (long long i = 0; i < (1 << u); i++) {
    for (long long j = 0; j <= u; j++) {
      z[k + i][j] = x[k + i][j];
    }
  }
}
int main() {
  long long t;
  scanf("%I64d %I64d %I64d", &m, &t, &Mod);
  for (long long i = 0; i < (1 << m); i++) {
    scanf("%I64d", &a[i]);
  }
  for (long long i = 0; i <= m; i++) {
    scanf("%I64d", &b[i]);
    matrix[i] = b[i];
  }
  for (long long i = 0; i < MAXM; i++) {
    for (long long j = 0; j < MAXM; j++) {
      if (j == 0 || j == i) {
        c[i][j] = 1;
      } else {
        if (i != 0) {
          c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
          c[i][j] %= Mod;
        }
      }
    }
  }
  matrix_pw(t);
  generator(0, m);
  for (long long i = 0; i <= m; i++) {
    for (long long j = 0; j < (1 << m); j++) {
      e[j] += matrix[i] * z[j][i];
      e[j] %= Mod;
    }
  }
  for (long long i = 0; i < (1 << m); i++) {
    printf("%I64d\n", e[i]);
  }
}
