#include <bits/stdc++.h>
using namespace std;
long long n, l, r, k;
long long n1, n2, k1;
bool check_x(long long x) {
  if (x < 0 || x > n) return false;
  long long ost = k % (n + x);
  if (ost == 0) ost += n + x;
  long long dob = ost - n1;
  long long x2_max = min(n2, x);
  long long x1_min = x - x2_max;
  long long x1_max = min(n1, x);
  long long dob_min = max(0ll, x1_min - 1);
  long long dob_max = x1_max;
  if (dob < dob_min || dob > dob_max) return false;
  cout << x << endl;
  return true;
}
int main() {
  cin >> n >> l >> r >> k;
  n1 = (r + n - l) % n + 1;
  n2 = n - n1;
  k1 = k - n1;
  if (check_x(n2 + k1 + 1)) return 0;
  if (check_x(n2 + k1)) return 0;
  if (n < 1e7) {
    for (long long x = n; x >= 0; --x)
      if (check_x(x)) return 0;
  } else {
    for (long long c = 1; c <= k / n; ++c) {
      long long k2 = k - c * n - n1;
      long long x2 = min(n2, k2 / c);
      long long x1 = min(n1, (k2 - c * x2 + 1) / (c + 1));
      if (check_x(x1 + x2)) return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
