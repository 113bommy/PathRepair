#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 50;
long long n, k, l, m;
vector<vector<long long> > mult(vector<vector<long long> > &A,
                                vector<vector<long long> > &B) {
  vector<vector<long long> > C(A.size(), vector<long long>(B[0].size()));
  for (int i = 0; i < A.size(); i++) {
    for (int k = 0; k < B.size(); k++) {
      for (int j = 0; j < B[0].size(); j++) {
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % m;
      }
    }
  }
  return C;
}
vector<vector<long long> > pow(vector<vector<long long> > A, long long n) {
  vector<vector<long long> > B(A.size(), vector<long long>(A.size()));
  for (int i = 0; i < A.size(); i++) {
    B[i][i] = 1;
  }
  while (n > 0) {
    if (n & 1) B = mult(B, A);
    A = mult(A, A);
    n >>= 1;
  }
  return B;
}
long long quick_pow(long long base, long long exponent) {
  long long ans = 1;
  while (exponent) {
    if (exponent & 1) ans *= base, ans %= m;
    base *= base;
    base %= m;
    exponent >>= 1;
  }
  return ans;
}
long long solve() {
  vector<vector<long long> > A(2, vector<long long>(2));
  A[0][0] = 1, A[0][1] = 1;
  A[1][0] = 1, A[1][1] = 0;
  A = pow(A, n - 1);
  vector<vector<long long> > ans(2, vector<long long>(1));
  ans[0][0] = 1, ans[1][0] = 1;
  ans = mult(A, ans);
  return ans[0][0] + ans[1][0];
}
int main() {
  cin >> n >> k >> l >> m;
  long long zero = solve(), one = ((quick_pow(2, n) - zero) % m + m) % m;
  long long ans = 1;
  for (int i = 0; i < l; i++) {
    if (k & (1ll << i))
      ans *= one;
    else
      ans *= zero;
    ans %= m;
    k = k - (k & (1ll << i));
  }
  if (k)
    cout << 0 << endl;
  else
    cout << ans << endl;
  return 0;
}
