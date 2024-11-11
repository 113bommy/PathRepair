#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, ans = 0, s = 0, res = 0;
  cin >> n >> k;
  if (k >= n)
    cout << n << endl;
  else {
    long long l = 0, h = n, m;
    while (l < h) {
      res = 0;
      m = l + (h - l) / 2;
      s = m;
      while (s > 0) {
        res += s;
        s = s / k;
      }
      if (res >= n) {
        ans = m;
        h = m;
      } else
        l = m + 1;
    }
    cout << ans << endl;
  }
  return 0;
}
