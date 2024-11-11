#include <bits/stdc++.h>
using namespace std;
const int MAX = (int)1e6 + 5;
const int INF = (int)-1e9 + 7;
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
long long n, ans = 0;
long long calc(long long x) { return 3 * x * (x + 1) / 2; }
long long solve() {
  int lo = 1, hi = MAX, mid, ans = 0;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (calc(mid) - mid <= n) {
      ans = mid;
      lo = mid + 1;
    } else
      hi = mid - 1;
  }
  return ans;
}
int main() {
  cin >> n;
  ans = solve();
  if (n % 3 == 0)
    cout << ans / 3 << "\n";
  else if (n % 3 == 1)
    cout << ans / 3 + (ans % 3 == 2) << "\n";
  else
    cout << ans / 3 + (ans % 3 != 0) << "\n";
  return 0;
}
