#include <bits/stdc++.h>
using namespace std;
long long n, sm, x, k, st, en, mid;
int main() {
  cin >> n >> k;
  if (n == 1)
    cout << 0;
  else if (n <= k)
    cout << 1;
  else {
    n--;
    k--;
    sm = k * (k + 1) / 2;
    if (sm < n) {
      cout << -1;
      return 0;
    }
    st = 1;
    en = k;
    while (st < en) {
      mid = (st + en) / 2;
      x = mid * (mid - 1) / 2;
      x = sm - x;
      if (x == n) {
        cout << k - mid + 1;
        return 0;
      } else if (x > n)
        st = mid + 1;
      else
        en = mid;
    }
    cout << k - st + 2;
  }
  return 0;
}
