#include <bits/stdc++.h>
using namespace std;
long long MOD;
void print(vector<long long> &A) {
  cout << A[0] << " " << A[1] << " " << A[2] << " " << A[3] << endl;
}
vector<long long> mul(vector<long long> &A, vector<long long> &B) {
  vector<long long> C(4, 0);
  C[0] = (A[0] * B[0] + A[1] * B[2]) % MOD;
  C[1] = (A[0] * B[1] + A[1] * B[3]) % MOD;
  C[2] = (A[2] * B[0] + A[3] * B[2]) % MOD;
  C[3] = (A[2] * B[1] + A[3] * B[3]) % MOD;
  return C;
}
vector<long long> pow(vector<long long> &M, long long p) {
  if (p == 1) {
    return M;
  }
  if (p % 2) {
    vector<long long> R = pow(M, p - 1);
    return mul(R, M);
  }
  vector<long long> R = pow(M, p / 2);
  return mul(R, R);
}
int main() {
  long long m, l, r, k;
  cin >> m >> l >> r >> k;
  MOD = m;
  long long res = 1;
  for (long long i = 1; i * i <= r; i++) {
    if (res < i && r / i - (l - 1) / i >= k) res = i;
    long long x = r / i;
    if (res < x && r / x - (l - 1) / x >= k) res = x;
  }
  vector<long long> A(4, 0);
  A[0] = A[1] = A[2] = 1;
  A[3] = 0;
  vector<long long> B = pow(A, res);
  cout << B[1] % m << endl;
  return 0;
}
