#include <bits/stdc++.h>
using namespace std;
int mod;
long long l, r, k;
vector<long long> vt;
struct Matrix {
  int a[2][2];
  void ToZero() { memset(a, 0, sizeof(a)); }
  Matrix operator*(Matrix t) {
    Matrix res;
    int i, j, k;
    res.ToZero();
    for (i = 0; i < 2; ++i) {
      for (j = 0; j < 2; ++j) {
        if (a[i][j] != 0) {
          for (k = 0; k < 2; ++k)
            res.a[i][k] =
                (res.a[i][k] + (long long)a[i][j] * t.a[j][k] % mod) % mod;
        }
      }
    }
    return res;
  }
  Matrix operator^(long long p) {
    Matrix res, x(*this);
    res.ToZero();
    res.a[0][0] = res.a[1][1] = 1;
    for (; p != 0; p >>= 1) {
      if (p & 1) res = res * x;
      x = x * x;
    }
    return res;
  }
} qkm;
void GetData() { scanf("%d%lld%lld%lld", &mod, &l, &r, &k); }
void Solve() {
  long long n = 1;
  for (long long i = 1; i * i <= r; ++i) {
    vt.push_back(i);
    vt.push_back(r / i);
  }
  for (int i = 0; i < (int)vt.size(); ++i) {
    if (r / vt[i] - (l - 1) / vt[i] >= k) n = max(n, vt[i]);
  }
  qkm.a[0][0] = qkm.a[0][1] = qkm.a[1][0] = 1;
  qkm.a[1][1] = 0;
  qkm = qkm ^ (n - 1);
  printf("%d\n", qkm.a[0][0] % mod);
}
int main() {
  GetData();
  Solve();
  return 0;
}
