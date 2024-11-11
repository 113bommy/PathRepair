#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 6;
vector<vector<long long>> A = {{2, 1, 1, 0, 1, 0}, {1, 2, 0, 1, 1, 0},
                               {1, 1, 1, 0, 1, 0}, {1, 1, 0, 1, 1, 0},
                               {0, 0, 0, 0, 1, 1}, {0, 0, 0, 0, 0, 1}};
vector<long long> init, ans(6);
long long n, sx, sy, dx, dy, t;
vector<vector<long long>> mul(vector<vector<long long>> A,
                              vector<vector<long long>> B) {
  vector<vector<long long>> C(6);
  for (long long i = 0; i < MAXN; i++) {
    C[i].resize(6);
    for (long long j = 0; j < MAXN; j++) {
      for (long long k = 0; k < MAXN; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
      C[i][j] = (C[i][j] - 1) % n + 1;
    }
  }
  return C;
}
vector<vector<long long>> pw(vector<vector<long long>> A, long long k) {
  vector<vector<long long>> B(6);
  for (long long i = 0; i < MAXN; i++) {
    B[i].resize(6);
    B[i][i] = 1;
  }
  for (long long i = 1; i <= k; i <<= 1) {
    if (i & k) B = mul(B, A);
    A = mul(A, A);
  }
  return B;
}
signed main() {
  cin >> n >> sx >> sy >> dx >> dy >> t;
  A = pw(A, t);
  init = {sx, sy, dx, dy, 0, 1};
  for (long long i = 0; i < MAXN; i++) {
    for (long long j = 0; j < MAXN; j++) {
      ans[i] += A[i][j] * init[j];
    }
    ans[i] = (ans[i] - 1) % n + 1;
  }
  cout << ans[0] << " " << ans[1] << "\n";
}
