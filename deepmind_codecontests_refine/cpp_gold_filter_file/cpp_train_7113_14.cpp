#include <bits/stdc++.h>
int n, k;
inline void oil_read(std::istream& r) { r >> n >> k; }
inline int oil_eval(int v) {
  int result = 0;
  int dev = v;
  while (dev > 0) {
    result += dev;
    dev /= k;
  }
  return result;
}
inline void oil_print(std::ostream& w, int i) { w << i << std::endl; }
inline void oil_solve(std::istream& r, std::ostream& w) {
  int high, low, mid;
  int result = 0;
  oil_read(r);
  if (n < k) {
    oil_print(w, n);
    return;
  }
  high = n + 1;
  low = k - 1;
  while (result != n) {
    if (mid == low) {
      oil_print(w, mid);
      break;
    }
    mid = (high - low) / 2 + low;
    result = oil_eval(mid);
    if (result == n) {
      oil_print(w, mid);
      break;
    } else if (result > n) {
      high = mid - 1;
    } else if (result < n) {
      low = mid + 1;
    }
  }
  return;
}
int main() {
  using namespace std;
  oil_solve(cin, cout);
  return 0;
}
