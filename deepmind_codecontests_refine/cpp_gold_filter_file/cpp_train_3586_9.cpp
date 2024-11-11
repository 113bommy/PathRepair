#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  long long k;
  while (cin >> n >> m >> k) {
    long long lo = 1, hi = 1LL * n * m;
    if (k == 1)
      cout << 1 << endl;
    else {
      while (hi - lo > 1) {
        long long mid = (lo + hi) / 2, cnt = 0;
        for (int i = 1; i <= n; i++) {
          long long x = min((long long)m, mid / i);
          cnt += x;
        }
        if (cnt < k)
          lo = mid;
        else
          hi = mid;
      }
      cout << hi << endl;
    }
  }
  return 0;
}
