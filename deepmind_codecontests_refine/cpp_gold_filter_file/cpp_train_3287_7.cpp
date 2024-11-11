#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long n, m, k;
  cin >> n >> m >> k;
  unsigned long long r = k - 1, l = n - k;
  unsigned long long lo = 1, hi = m - n + 1, mid;
  while (lo < hi) {
    mid = lo + (hi - lo + 1) / 2;
    auto calc = [&mid](unsigned long long w) -> unsigned long long {
      if (w == 0) return 0;
      unsigned long long ret = w + (mid - 1) * (mid - 2) / 2;
      if (w < mid - 1) ret -= (mid - w - 2) * (mid - w - 1) / 2;
      return ret;
    };
    if (calc(r) + calc(l) + mid <= m)
      lo = mid;
    else
      hi = mid - 1;
  }
  cout << lo << endl;
  return 0;
}
