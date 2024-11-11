#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 100 + 5;
int matrix[maxn][maxn], s[maxn][maxn];
int n, b, k, x;
int cnt[10], tmp[maxn][maxn];
void mul(int a[][maxn], int b[][maxn]) {
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < x; ++j) {
      int t(0);
      for (int k = 0; k < x; ++k) {
        t = (t + 1LL * a[i][k] * b[k][j]) % mod;
      }
      tmp[i][j] = t;
    }
  }
  for (int i = 0; i < x; ++i)
    for (int j = 0; j < x; ++j) a[i][j] = tmp[i][j];
}
int main() {
  while (~scanf("%d%d%d%d", &n, &b, &k, &x)) {
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      cnt[x]++;
    }
    for (int i = 0; i < x; ++i)
      for (int j = 0; j < 10; ++j) {
        matrix[i][(i * 10 + j) % x] += cnt[j];
      }
    for (int i = 0; i < x; ++i) s[i][i] = 1;
    while (b) {
      if (b & 1) mul(s, matrix);
      mul(matrix, matrix);
      b /= 2;
    }
    printf("%d\n", s[0][k]);
  }
}
