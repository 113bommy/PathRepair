#include <bits/stdc++.h>
using namespace std;
long long f(long long x) {
  if (x <= 1) {
    return 0;
  }
  long long kek = 1;
  while (kek < x) kek *= 2;
  return f(kek - x) + 1;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n;
  cin >> n;
  vector<long long> A(n);
  for (long long i = 0; i < n; i++) {
    cin >> A[i];
  }
  vector<long long> B = A;
  long long ans = 0;
  long long x1 = 0, y1 = 0;
  for (long long _ = 0; _ < 40; _++) {
    long long mxeven = (long long)-1e9, mxodd = (long long)-1e9;
    long long mxeven1 = (long long)-1e9, mxodd1 = (long long)-1e9;
    long long x0 = 0, y0 = 0;
    long long x2 = 0, y2 = 0;
    for (long long i = 0; i < n; i++) {
      long long x = B[i];
      if (x % 2 == 0) {
        if (A[i] % 2 == 0) {
          if (mxeven <= f(A[i])) {
            mxeven = f(A[i]);
            x0 = i;
          }
        } else {
          if (mxeven1 <= f(A[i])) {
            mxeven1 = f(A[i]);
            x2 = i;
          }
        }
      } else {
        if (A[i] % 2 == 0) {
          if (mxodd <= f(A[i])) {
            mxodd = f(A[i]);
            y0 = i;
          }
        } else {
          if (mxodd1 <= f(A[i])) {
            mxodd1 = f(A[i]);
            y2 = i;
          }
        }
      }
    }
    if (ans < mxeven + mxodd) {
      ans = f(A[x0]) + f(A[y0]);
      x1 = x0;
      y1 = y0;
    }
    if (ans < mxeven1 + mxodd1) {
      ans = f(A[x2]) + f(A[y2]);
      x1 = x2;
      y1 = y2;
    }
    if (ans < mxeven + mxodd1 + 1) {
      ans = f(A[x0]) + f(A[y2]) + 1;
      x1 = x0;
      y1 = y2;
    }
    if (ans < mxeven1 + mxodd + 1) {
      ans = f(A[x2]) + f(A[y0]) + 1;
      x1 = x2;
      y1 = y0;
    }
    for (auto &x : B) {
      x /= 2;
    }
  }
  cout << x1 + 1 << ' ' << y1 + 1 << ' ' << ans << '\n';
}
