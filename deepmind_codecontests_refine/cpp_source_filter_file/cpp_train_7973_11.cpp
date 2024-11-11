#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  long long int i, j, k, x, y, n, z, a, b, t, c;
  long long int start, mid, end, ans, inc, dec, minc;
  scanf("%d", &q);
  while (q--) {
    scanf("%lld", &n);
    b = t = n - 1;
    start = 1;
    ans = 0;
    end = 2e9;
    while (start <= end) {
      mid = (start + end) >> 1;
      dec = mid + 1;
      inc = mid * (mid - 1) / 2 + 1;
      if (b - dec >= (t + inc) / 2) {
        ans = mid;
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    if (ans) {
      dec = ans + 1;
      inc = ans * (ans - 1) / 2 + 1;
      minc = ans * (ans + 1) / 2;
      start = inc;
      end = minc;
      while (start <= end) {
        mid = (start + end) >> 1;
        if (b - dec >= (t + mid) / 2) {
          inc = mid;
          start = mid + 1;
        } else
          end = mid - 1;
      }
    } else
      inc = 0;
    cout << t + inc << endl;
  }
  return 0;
}
