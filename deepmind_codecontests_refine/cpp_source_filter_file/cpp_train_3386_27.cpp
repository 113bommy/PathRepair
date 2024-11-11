#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long n, a[N], sum[N], sum2[N], ans;
struct convexHull {
  vector<long long> A, B;
  bool increasing;
  convexHull(bool increasing = 0) : increasing(increasing) {
    A.clear();
    B.clear();
  }
  bool bad(long long l1, long long l2, long long l3) {
    if (increasing)
      return B[l3] - B[l1] * (A[l1] - A[l2]) <
             (A[l1] - A[l3]) * (B[l2] - B[l1]);
    else
      return B[l3] - B[l1] * (A[l1] - A[l2]) <
             (A[l1] - A[l3]) * (B[l2] - B[l1]);
  }
  void add(long long a, long long b) {
    while (!A.empty() && A.back() == a && B.back() <= b)
      A.pop_back(), B.pop_back();
    A.push_back(a);
    B.push_back(b);
    while (A.size() >= 3 && bad(A.size() - 3, A.size() - 2, A.size() - 1)) {
      A.erase(A.end() - 2);
      B.erase(B.end() - 2);
    }
  }
  long long query(long long x) {
    if (!A.size()) return -1e9;
    long long l = 0, r = A.size() - 1;
    while (l < r) {
      long long mid = l + r >> 1;
      long long val1 = A[mid] * x + B[mid], val2 = A[mid + 1] * x + B[mid + 1];
      if (val1 >= val2)
        r = mid;
      else
        l = mid + 1;
    }
    return A[l] * x + B[l];
  }
} ch;
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; ++i)
    cin >> a[i], sum[i] = sum[i - 1] + a[i], sum2[i] = sum2[i - 1] + a[i] * i;
  ans = sum2[n];
  ch = convexHull(0);
  for (long long i = n; i; --i) {
    ans = max(ans, sum2[n] + sum[i] - a[i] * i + ch.query(a[i]));
    ch.add(i, -sum[i]);
  }
  ch = convexHull(1);
  for (long long i = 1; i <= n; ++i) {
    ans = max(ans, sum2[n] + sum[i - 1] - a[i] * i + ch.query(a[i]));
    ch.add(i, -sum[i - 1]);
  }
  cout << ans;
  return 0;
}
