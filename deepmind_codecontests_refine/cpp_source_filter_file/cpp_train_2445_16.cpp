#include <bits/stdc++.h>
using namespace std;
long long A, B, n, l, m, t;
bool check(long long r) {
  long long k = r - l + 1LL;
  long long rate = min(k, m);
  if (A + B * (r - 1) > t) return false;
  long long total = A * (l - r + 1LL) + B * (l + r - 2LL) * (r - l + 1LL) / 2LL;
  if (total > rate * t) return false;
  return true;
}
int main() {
  int T;
  cin >> A >> B >> n;
  for (T = 0; T < n; T++) {
    cin >> l >> t >> m;
    if (!check(l)) {
      cout << -1 << endl;
      continue;
    }
    long long i = 1;
    while (check(l + i)) i *= 2;
    long long res = 0LL;
    long long lo = l, hi = l + i;
    while (lo < hi) {
      long long mid = (lo + hi) / 2LL;
      if (!check(mid))
        hi = mid - 1LL;
      else
        lo = mid;
      if (lo + 1LL == hi) {
        if (check(hi))
          lo = hi;
        else
          hi = lo;
        break;
      }
    }
    cout << lo << endl;
  }
}
