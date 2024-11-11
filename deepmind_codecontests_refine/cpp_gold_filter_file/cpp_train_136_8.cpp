#include <bits/stdc++.h>
using namespace std;
long long t = 1, a, b, c, total_data;
bool can(long long predicted_time) {
  long long waited_data = predicted_time * b;
  long long completed_data = b * c;
  return waited_data + completed_data >= total_data;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  while (t--) {
    cin >> a >> b >> c;
    total_data = a * c;
    long long lo = 1, hi = 1e10, mid = 0, ans = -1;
    while (lo <= hi) {
      mid = lo + (hi - lo) / 2;
      if (can(mid)) {
        ans = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    cout << ans << '\n';
  }
}
