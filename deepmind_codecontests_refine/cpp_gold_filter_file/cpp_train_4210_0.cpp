#include <bits/stdc++.h>
using namespace std;
const int maxs = 83, mod = 1e9 + 7;
const long long mod2 = (long long)(mod)*mod;
typedef int Mat[maxs][maxs];
inline int Add(int x) { return x >= mod ? x - mod : x; }
inline void Add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
inline int Mul(int x, int y) { return (long long)(x)*y % mod; }
int size;
void Print(const Mat a) {
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      printf("%d ", a[i][j]);
    }
    putchar('\n');
  }
  putchar('\n');
}
void MatMul(Mat a, const Mat b) {
  static long long c[maxs][maxs];
  for (int i = 0; i < size; ++i) {
    memset(c[i], 0, size * sizeof(long long));
  }
  for (int i = 0; i < size; ++i) {
    for (int k = 0; k < size; ++k) {
      if (a[i][k]) {
        for (int j = 0; j < size; ++j) {
          c[i][j] += (long long)(a[i][k]) * b[k][j];
          if (c[i][j] >= mod2) c[i][j] -= mod2;
        }
      }
    }
  }
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      a[i][j] = c[i][j] % mod;
    }
  }
}
void MatPow(Mat a, long long y) {
  static Mat b;
  for (int i = 0; i < size; ++i) {
    memset(b[i], 0, size * sizeof(int));
    b[i][i] = 1;
  }
  for (; y; y >>= 1) {
    if (y & 1) MatMul(b, a);
    MatMul(a, a);
  }
  for (int i = 0; i < size; ++i) {
    memcpy(a[i], b[i], size * sizeof(int));
  }
}
Mat tran;
long long n;
int k, binom[maxs][maxs];
int main(void) {
  for (int i = 0; i < maxs; ++i) {
    binom[i][0] = binom[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      binom[i][j] = Add(binom[i - 1][j - 1] + binom[i - 1][j]);
    }
  }
  scanf("%lld%d", &n, &k);
  size = (k + 1) * 2 + 1;
  for (int i = 0; i <= k; ++i) {
    for (int j = 0; j <= k; ++j) {
      if (i < j) continue;
      tran[i][j] = binom[i][j];
      tran[i][j + k + 1] = Mul(binom[i][j], (1LL << i - j) % mod);
    }
    tran[i + k + 1][i] = 1;
  }
  tran[size - 1][size - 1] = tran[size - 1][k] = 1;
  MatPow(tran, n);
  int ans = 0;
  for (int i = 0; i <= k + 1; ++i) {
    Add(ans, tran[size - 1][i]);
  }
  printf("%d\n", ans);
  return 0;
}
