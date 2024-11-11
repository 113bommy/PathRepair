#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
inline void chmin(A &a, B b) {
  if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b) {
  if (a < b) a = b;
}
long long N;
long long A[111111];
long long L[111111], lv[111111];
long long R[111111], rv[111111];
signed main() {
  cin >> N;
  for (long long i = 0; i < (N); i++) cin >> A[i];
  L[0] = 0;
  lv[0] = A[0];
  for (long long i = 1; i < N; i++) {
    if (lv[i - 1] < A[i]) {
      lv[i] = A[i];
      L[i] = L[i - 1];
    } else {
      lv[i] = lv[i - 1] + 1;
      L[i] = L[i - 1] + lv[i] - A[i];
    }
  }
  R[N - 1] = 0;
  rv[N - 1] = A[N - 1];
  for (long long i = N - 2; i >= 0; i--) {
    if (rv[i + 1] < A[i]) {
      rv[i] = A[i];
      R[i] = R[i + 1];
    } else {
      rv[i] = rv[i + 1] + 1;
      R[i] = R[i + 1] + rv[i] - A[i];
    }
  }
  long long ans = LLONG_MAX;
  for (long long i = 0; i < (N); i++) {
    long long cost = L[i] + R[i] - (lv[i] - A[i]) - (rv[i] - A[i]);
    cost += max(lv[i], rv[i]) - A[i];
    chmin(ans, cost);
  }
  cout << ans << endl;
  return 0;
}
