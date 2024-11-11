#include <bits/stdc++.h>
using namespace std;
long long n, m, A[100005], B[100005];
bool check(long long k) {
  long long mark = 1;
  for (long long i = 1; i <= n; i++) {
    if (B[mark] < A[i]) {
      if (B[mark] < A[i] - k) return false;
      long long tmp = k - (A[i] - B[mark]);
      if (tmp - A[i] + B[mark] <= 0) {
        mark = upper_bound(B + 1, B + m + 1, A[i]) - B;
      } else
        mark = upper_bound(B + 1, B + m + 1, A[i] + tmp - A[i] + B[mark]) - B;
      long long l = mark, r = lower_bound(B + 1, B + m + 1, A[i] + tmp) - B;
      for (long long i = r - 1; i >= mark; i--) {
        if (tmp - 2 * (B[i] - A[1]) >= 0) {
          mark = i + 1;
          break;
        }
      }
    } else {
      int tmp = upper_bound(B + 1, B + m + 1, A[i] + k) - B;
      if (tmp > mark) mark = tmp;
    }
    if (mark > m) return true;
  }
  return mark > m;
}
int main() {
  long long res;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) cin >> A[i];
  for (long long i = 1; i <= m; i++) cin >> B[i];
  long long L = 0, R = abs(A[1] - B[1]) + B[m] - B[1];
  if (A[1] - B[1] > 0) L = A[1] - B[1];
  while (L <= R) {
    long long mid = (L + R) >> 1;
    if (check(mid)) {
      res = mid;
      R = mid - 1;
    } else
      L = mid + 1;
  }
  cout << res << endl;
  return 0;
}
