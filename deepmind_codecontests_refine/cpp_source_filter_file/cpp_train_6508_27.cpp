#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10, MAXM = 1e6 + 10;
const int INF = INT_MAX, SINF = 0x3f3f3f3f;
const long long llINF = LLONG_MAX;
const int MOD = 1e9 + 7, mod = 998244353;
const int inv2 = 5e8 + 4;
int n, b, k, x;
struct Matrix {
  int a[105][105];
  Matrix operator*(const Matrix &rhs) const {
    Matrix res;
    memset(res.a, 0, sizeof(res.a));
    for (int i = 0; i < x; i++)
      for (int j = 0; j < x; j++)
        for (int k = 0; k < x; k++)
          (res.a[i][j] += a[i][k] * rhs.a[k][j]) %= MOD;
    return res;
  }
};
Matrix ksm(Matrix base, int v) {
  Matrix res;
  memset(res.a, 0, sizeof(res.a));
  res.a[0][0] = 1;
  while (v) {
    if (v & 1) (res = res * base);
    base = base * base;
    v >>= 1;
  }
  return res;
}
int cnt[MAXN];
int main() {
  scanf("%d%d%d%d", &n, &b, &k, &x);
  for (int i = 1; i <= n; i++) {
    int p;
    scanf("%d", &p);
    cnt[p % x]++;
  }
  Matrix base;
  memset(base.a, 0, sizeof(base.a));
  for (int i = 0; i < x; i++)
    for (int j = 0; j < x; j++) {
      base.a[i][(i * 10 + j) % x] += cnt[j];
    }
  Matrix res = ksm(base, b);
  cout << res.a[0][k];
  return 0;
}
