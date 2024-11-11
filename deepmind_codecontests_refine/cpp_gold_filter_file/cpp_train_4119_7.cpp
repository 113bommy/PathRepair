#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n, x;
  cin >> n >> x;
  vector<double> v(x + 1);
  for (long long i = 0; i <= x; i++) cin >> v[i];
  double V[31][128];
  for (long long i = 0; i < 31; i++) {
    for (long long j = 0; j < 128; j++) V[i][j] = 0;
  }
  for (long long i = 0; i <= x; i++) V[0][i] = v[i];
  for (long long i = 1; i < 31; i++) {
    for (long long j = 0; j < 128; j++) {
      for (long long k = 0; k < 128; k++) {
        V[i][j ^ k] += V[i - 1][j] * V[i - 1][k];
      }
    }
  }
  cout.precision(30);
  double Ans[128];
  for (long long j = 0; j < 128; j++) Ans[j] = 0;
  bool th = false;
  for (long long i = 30; i >= 0; i--) {
    long long ba = n & (1LL << i);
    if (ba == 0) continue;
    if (!th) {
      for (long long j = 0; j < 128; j++) Ans[j] = V[i][j];
      th = true;
      continue;
    }
    double A[128];
    for (long long j = 0; j < 128; j++) A[j] = 0;
    for (long long j = 0; j < 128; j++) {
      for (long long k = 0; k < 128; k++) {
        A[j ^ k] += Ans[j] * V[i][k];
      }
    }
    for (long long j = 0; j < 128; j++) Ans[j] = A[j];
  }
  cout << (double)1 - Ans[0] << endl;
  return 0;
}
