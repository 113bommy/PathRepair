#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
long long check(long long x) {
  long long res = 0;
  long long l = 0, r = x;
  while (l <= r) {
    long long mid = l + r >> 1;
    long long d = (1 + mid) * mid / 2;
    if (d >= x) {
      res = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);
    long long ans = check(abs(a - b));
    while ((b + ans * (ans + 1) / 2 - a) % 2) ans++;
    cout << ans << '\n';
  }
  return 0;
}
