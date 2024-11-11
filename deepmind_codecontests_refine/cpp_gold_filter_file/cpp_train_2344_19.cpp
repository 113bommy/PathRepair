#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
int n, MOD;
long long Left, Right, Sum, x, y, t, res;
int A[1000000];
long long Add(long long a, long long b) { return (a + b) % MOD; }
long long Sub(long long a, long long b) {
  a = a % MOD;
  b = b % MOD;
  long long r = a - b;
  while (r < 0) r += MOD;
  return r;
}
long long Mul(long long a, long long b) { return ((a * b) % MOD); }
long long Pow(long long a, long long b) {
  long long res = 1;
  while (b > 0)
    if (b % 2 == 0) {
      a = Mul(a, a);
      b /= 2;
    } else {
      res = Mul(res, a);
      b--;
    }
  return res;
}
long long F2(long long x) {
  if (x == 0) return 1 % MOD;
  if (x == 1) return 4 % MOD;
  if (x % 2 == 1) {
    long long t = F2(x / 2);
    return Add(t, Mul(Pow(3, x / 2 + 1), t));
  } else
    return Add(F2(x - 1), Pow(3, x));
}
long long F(long long x) {
  if (x == 0) return 1;
  long long a = Pow(3, x);
  long long b = F2(x - 1);
  return Sub(a, b);
}
long long G(long long x) { return Pow(3, x); }
vector<vector<int> > Mul_Matrix(vector<vector<int> > A,
                                vector<vector<int> > B) {
  vector<vector<int> > R;
  R = A;
  for (int(i) = (0); (i) < (2); ++(i))
    for (int(j) = (0); (j) < (2); ++(j)) {
      R[i][j] = 0;
      for (int(k) = (0); (k) < (2); ++(k))
        R[i][j] = Add(R[i][j], Mul(A[i][k], B[k][j]));
    }
  return R;
}
vector<vector<int> > Pow_Matrix(vector<vector<int> > A, long long x) {
  vector<vector<int> > R;
  vector<int> T;
  T.push_back(0);
  T.push_back(0);
  R.push_back(T);
  R.push_back(T);
  R[0][0] = 1;
  R[1][1] = 1;
  while (x > 0)
    if (x % 2 == 0) {
      x /= 2;
      A = Mul_Matrix(A, A);
    } else {
      x--;
      R = Mul_Matrix(R, A);
    }
  return R;
}
long long Fibo(long long f0, long long f1, long long x) {
  if (x == 0) return f1;
  vector<vector<int> > A;
  vector<int> T;
  T.push_back(1);
  T.push_back(1);
  A.push_back(T);
  A.push_back(T);
  A[1][1] = 0;
  A = Pow_Matrix(A, x);
  long long res = Mul(A[0][0], f1);
  res = Add(res, Mul(A[0][1], f0));
  return res;
}
int main() {
  scanf("%d %I64d %I64d %d", &n, &x, &y, &MOD);
  for (int(i) = (0); (i) < (n); ++(i)) scanf("%d", &A[i]);
  if (n == 1) {
    printf("%d\n", A[0] % MOD);
    return 0;
  }
  Left = A[0];
  Right = Fibo(A[n - 2], A[n - 1], x);
  Sum = 0;
  Sum = Add(Sum, Mul(F(x), A[0]));
  Sum = Add(Sum, Mul(F(x), A[n - 1]));
  t = 0;
  for (int(i) = (1); (i) < (n - 1); ++(i)) t = Add(t, A[i]);
  Sum = Add(Sum, Mul(G(x), t));
  res = 0;
  res = Add(res, Mul(Left, F(y)));
  res = Add(res, Mul(Right, F(y)));
  Sum = Sub(Sum, Left);
  Sum = Sub(Sum, Right);
  res = Add(res, Mul(G(y), Sum));
  res = res % MOD;
  printf("%I64d\n", res);
  return 0;
}
