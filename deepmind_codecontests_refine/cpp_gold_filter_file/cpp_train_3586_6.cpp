#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
bool ok(long long t) {
  long long res = 0;
  for (int i = 1; i <= min(n, m); i++) {
    if (t / i <= max(n, m))
      res += (t / i);
    else
      res += max(n, m);
    if (!res % i) res--;
    if (!t / i) break;
  }
  return res + 1 <= k;
}
int main(int argc, char** argv) {
  cin >> n >> m >> k;
  long long l = 0, r = n * (m + 2), mid, ans = 0;
  while (r >= l) {
    mid = (r + l) / 2;
    if (ok(mid)) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << ans + 1;
  return 0;
}
