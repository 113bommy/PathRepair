#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long n, a[N], sum[N], sum2[N], ans;
struct ConvexHullTrick {
  vector<long long> A, B;
  bool increasing_slope, need_tenary;
  long long curit;
  bool bad(long long l1, long long l2, long long l3) {
    if (increasing_slope)
      return (B[l3] - B[l1]) * (A[l1] - A[l2]) <
             (A[l1] - A[l3]) * (B[l2] - B[l1]);
    return (B[l3] - B[l1]) * (A[l1] - A[l2]) >
           (A[l1] - A[l3]) * (B[l2] - B[l1]);
  }
  void init(bool _increasing_slope, bool _need_tenary) {
    increasing_slope = _increasing_slope;
    need_tenary = _need_tenary;
    A.clear();
    B.clear();
    curit = 0;
  }
  void add(long long x, long long y) {
    if (!A.empty()) {
      if (A.back() == x && B.back() <= y) A.pop_back(), B.pop_back(), curit--;
    }
    A.push_back(x);
    B.push_back(y);
    while (A.size() > 2 && bad(A.size() - 3, A.size() - 2, A.size() - 1)) {
      A.erase(A.end() - 2);
      B.erase(B.end() - 2);
      curit--;
    }
  }
  long long query(long long x) {
    if (!need_tenary) {
      if (curit < 0) curit = 0;
      while (curit != A.size() - 1 && A[curit] * 1LL * x + B[curit] <=
                                          A[curit + 1] * 1LL * x + B[curit + 1])
        curit++;
      return A[curit] * 1LL * x + B[curit];
    }
    long long l = 0, r = (long long)(A.size()) - 1;
    while (r - l > 2) {
      long long mid1 = (l * 2 + r) / 3;
      long long mid2 = (l + 2 * r) / 3;
      long long val1 = A[mid1] * x + B[mid1];
      long long val2 = A[mid2] * x + B[mid2];
      if (val1 == val2)
        l = mid1, r = mid2;
      else if (val1 < val2)
        l = mid1;
      else
        r = mid2;
    }
    long long ret = -1e18;
    for (long long i = l; i <= r; i++) ret = max(ret, A[i] * x + B[i]);
    return ret;
  }
} ch;
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; ++i)
    cin >> a[i], sum[i] = sum[i - 1] + a[i], sum2[i] = sum2[i - 1] + a[i] * i;
  ans = sum2[n];
  ch.init(0, 1);
  for (long long i = n; i; --i) {
    ans = max(ans, sum2[n] + sum[i] - a[i] * i + ch.query(a[i]));
    ch.add(i, -sum[i]);
  }
  ch.init(1, 1);
  for (long long i = 1; i <= n; ++i) {
    ans = max(ans, sum2[n] + sum[i - 1] - a[i] * i + ch.query(a[i]));
    ch.add(i, -sum[i - 1]);
  }
  cout << ans;
  return 0;
}
