#include <bits/stdc++.h>
using namespace std;
bool is_poss(int &ccw, int &cw, long long int &l, long long int &t) {
  if (ccw <= cw) return (cw - ccw) <= t;
  return ((l - ccw) + cw) <= t;
}
int main() {
  long long int n, len, t;
  cin >> n >> len >> t;
  t *= 2;
  double ans = 0.25 * (t / len) * n * (n - 1);
  t %= len;
  int A[n];
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  int coll = 0, l = 0, r = 0;
  do {
    while (is_poss(A[l], A[r], len, t)) {
      r = (r + 1) % n;
      coll++;
      if (r == l) break;
    }
    ans += 0.25 * (coll - 1);
    coll--;
    l = (l + 1) % n;
  } while (l != 0);
  cout.precision(9);
  cout << fixed << ans << "\n";
  return 0;
}
