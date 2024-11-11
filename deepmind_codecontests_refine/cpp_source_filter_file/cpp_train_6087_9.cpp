#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 7) + 7, mod = 1e9 + 7;
struct mat {
  int n, a[N][N];
  mat(int nn, int b = 0) {
    n = nn;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) a[i][j] = (i == j) * b;
  }
  int* operator[](int x) { return a[x]; }
};
mat operator*(mat x, mat y) {
  mat t(x.n);
  for (int i = 0; i < x.n; i++)
    for (int j = 0; j < y.n; j++)
      for (int k = 0; k < x.n; k++)
        t[i][j] = (t[i][j] + x[i][k] * 1ll * y[k][j]) % mod;
  return t;
}
mat operator^(mat a, int x) {
  mat t(a.n, 1);
  if (x == 0) return t;
  t = a ^ (x / 2);
  if (x & 1)
    return t * t * a;
  else
    return t * t;
}
int pre[N * 2], tmp[N * 2];
int32_t main() {
  pre[1] = 1;
  for (int i = 0; i < 7; i++) {
    int o;
    cin >> o;
    mat t(1 << (i + 1));
    for (int bit1 = 0; bit1 < (1 << (i + 1)); bit1++)
      for (int bit2 = 0; bit2 < (1 << (i + 1)); bit2++)
        for (int mid = 0; mid < (1 << i); mid++) {
          int x = ((mid + (1 << i)) << 1) | 1, is = 1;
          for (int j = 0; j <= i; j++)
            if ((bit1 >> j & 1) && (bit2 >> j & 1) && (x >> j & 1) &&
                (x >> (j + 1)) & 1) {
              is = 0;
              break;
            }
          t[bit1][bit2] += is;
        }
    t = t ^ o;
    memset(tmp, 0, sizeof tmp);
    for (int j = 0; j < (1 << (i + 1)); j++)
      for (int k = 0; k < (1 << (i + 1)); k++)
        tmp[j] = (tmp[j] + pre[k] * 1ll * t[k][j]);
    memset(pre, 0, sizeof pre);
    for (int j = 0; j < (1 << (i + 1)); j++) pre[j + (1 << (i + 1))] = tmp[j];
  }
  cout << pre[(1 << 8) - 1] << endl;
}
