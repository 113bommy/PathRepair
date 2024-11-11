#include <bits/stdc++.h>
using namespace std;
const int MAX = 4;
const int MAX2 = 100;
struct Matrix {
  long long (*an)[MAX];
  int n, m;
  Matrix(long long (*a)[MAX] = 0, int b = 0, int c = 0) : an(a), n(b), m(c) {}
  void print() {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) printf("%lld ", an[i][j]);
      printf("\n");
    }
  }
};
long long re[MAX][MAX];
long long rev[MAX][MAX];
long long buffer[MAX2][MAX][MAX];
long long bnt;
long long n, m, k, l, r;
void multiply(Matrix &a, Matrix &b, Matrix &ret, long long MOD) {
  ret.n = a.n, ret.m = b.m;
  int tmp = a.m;
  for (int i = 1; i <= ret.n; i++) {
    for (int j = 1; j <= ret.m; j++) {
      ret.an[i][j] = 0;
      for (int k = 1; k <= tmp; k++) {
        ret.an[i][j] = (ret.an[i][j] + a.an[i][k] * b.an[k][j]) % MOD;
      }
    }
  }
}
void pow(Matrix &a, long long b, long long MOD, Matrix &ret) {
  if (b == 0) {
    for (int i = (1); i <= (a.n); ++i)
      for (int j = (1); j <= (a.n); ++j) ret.an[i][j] = 0;
    for (int i = (1); i <= (a.n); ++i) ret.an[i][i] = 1;
  } else {
    int oribnt = bnt;
    Matrix tmp(buffer[bnt++], a.n, a.n);
    Matrix tmp2(buffer[bnt++], a.n, a.n);
    pow(a, b / 2, MOD, tmp);
    multiply(tmp, tmp, tmp2, MOD);
    if (b % 2 == 0) {
      for (int i = (1); i <= (a.n); ++i)
        for (int j = (1); j <= (a.n); ++j) ret.an[i][j] = tmp2.an[i][j];
    } else
      multiply(tmp2, a, ret, MOD);
    bnt = oribnt;
  }
}
long long F(long long n, long long m) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1 % m;
  else {
    Matrix a = Matrix(buffer[bnt++], 2, 2);
    a.an[1][1] = 0, a.an[1][2] = 1, a.an[2][1] = 1, a.an[2][2] = 1;
    Matrix start = Matrix(buffer[bnt++], 1, 2);
    start.an[1][1] = 0, start.an[1][2] = 1;
    Matrix ret(buffer[bnt++], 2, 2);
    pow(a, n - 1, m, ret);
    Matrix ans(buffer[bnt++], 1, 2);
    multiply(start, ret, ans, m);
    bnt -= 4;
    return ans.an[1][2];
  }
}
long long ceil(long long a, long long b) {
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}
long long floor(long long a, long long b) { return a / b; }
long long val(long long q) { return floor(r, q) - ceil(l, q) + 1; }
unordered_set<long long> checkPoint;
long long sqceil(long long v) {
  long long ret = 0;
  while (ret * ret <= v) ret++;
  if ((ret - 1) * (ret - 1) == v) ret--;
  return ret;
}
long long sqfloor(long long v) {
  long long ret = 0;
  while (ret * ret < v) ret++;
  if (ret * ret != v) ret--;
  return ret;
}
int main() {
  scanf("%lld%lld%lld%lld", &m, &l, &r, &k);
  long long limit = sqceil(r);
  n = LLONG_MIN;
  for (long long q = 1; q <= limit; q++) {
    long long z = val(q);
    if (z >= k) n = max(n, q);
  }
  long long l1 = sqfloor(r);
  for (long long a = 1; a <= l1; a++) {
    long long v = floor(r, a);
    if (v > limit) checkPoint.insert(v);
    v = floor(r, a + 1) + 1;
    if (v > limit) checkPoint.insert(v);
  }
  long long l2 = sqfloor(l);
  for (long long a = 1; a <= l2; a++) {
    long long v = a - 1 == 0 ? l : ceil(l, a - 1) - 1;
    if (v > limit) {
      checkPoint.insert(v);
    }
    v = ceil(l, a);
    if (v > limit) {
      checkPoint.insert(v);
    }
  }
  for (long long pos : checkPoint) {
    if (pos > n) {
      long long z = val(pos);
      if (z >= k) n = max(n, pos);
    }
  }
  bnt = 0;
  printf("%lld\n", F(n, m));
  return 0;
}
