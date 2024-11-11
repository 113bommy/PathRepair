#include <bits/stdc++.h>
using namespace std;
long long MOD;
vector<long long> b;
long long s0 = 0;
long long powmod(long long n, long long exp) {
  long long r = 1;
  long long a = (long long)n;
  while (exp) {
    if (exp & 1) {
      r = (r * a) % MOD;
    }
    a = (a * a) % MOD;
    exp >>= 1;
  }
  return r;
}
long long sum(long long i) {
  if (i < 1) return 0LL;
  long long r = 0;
  if (i & 1) {
    r = powmod(3, i - 1);
  }
  i >>= 1;
  return (r + (powmod(3, i) + 1) * sum(i) % MOD) % MOD;
}
long long s(long long i, long long x) {
  long long q = powmod(3, i);
  return (q * s0 % MOD - (long long)sum(i) % MOD * (b[0] + x) % MOD + MOD) %
         MOD;
}
vector<vector<long long> > mult(vector<vector<long long> > A,
                                vector<vector<long long> > B) {
  vector<vector<long long> > C(2, vector<long long>(2));
  for (int i = 0; i < A.size(); ++i)
    for (int j = 0; j < B[0].size(); ++j)
      for (int k = 0; k < B.size(); ++k)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j] % MOD) % MOD;
  return C;
}
long long fib(long long i) {
  if (i < 2) return max(i, 0LL);
  vector<vector<long long> > M(2, vector<long long>(2));
  vector<vector<long long> > I(2, vector<long long>(2));
  M[0][0] = M[0][1] = M[1][0] = 1LL;
  I[0][0] = I[1][1] = 1LL;
  long long exp = i - 1;
  vector<vector<long long> > r = I;
  vector<vector<long long> > a = M;
  while (exp) {
    if (exp & 1) {
      r = mult(r, a);
    }
    a = mult(a, a);
    exp >>= 1;
  }
  return r[0][0];
}
int main() {
  int n;
  long long x, y, r;
  cin >> n >> x >> y >> MOD;
  for (int i = 0; i < n; ++i) {
    cin >> r;
    b.push_back(r);
    s0 = (r + s0) % MOD;
  }
  s0 = s(x, b[b.size() - 1]);
  if (b.size() == 1)
    cout << b[0] << endl;
  else
    cout << s(y,
              (b[b.size() - 1] * fib(x + 1) % MOD + b[b.size() - 2] * fib(x)) %
                  MOD)
         << endl;
  return 0;
}
