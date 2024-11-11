#include <bits/stdc++.h>
using namespace std;
int main() {
  size_t n, p1, p2, p3, t1, t2;
  cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
  size_t consumption{0};
  size_t l, r;
  cin >> l >> r;
  consumption += (r - l) * p1;
  size_t last{r};
  for (size_t i{1}; i < n; ++i) {
    cin >> l >> r;
    const size_t interval{l - last};
    if (interval > t1 + t2) {
      consumption += t1 * p1 + t2 * p2 + (interval - t1 - t2) * p3;
    } else if (interval > t1) {
      consumption += t1 + p1 + (interval - t1) * p2;
    } else {
      consumption += interval * p1;
    }
    consumption += (r - l) * p1;
    last = r;
  }
  cout << consumption;
  return 0;
}
