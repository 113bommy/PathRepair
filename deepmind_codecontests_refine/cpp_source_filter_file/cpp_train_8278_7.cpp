#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int N = 1e5 + 10;
const long long INF = 1e12;
long long n, k;
long long b[N], a[N];
bool solve(long long mid) {
  long long all = k;
  long long need;
  for (int i = 1; i <= n; i++) {
    need = b[i] - mid * a[i];
    if (need >= 0) continue;
    all += need;
    if (all < 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  long long l = 0;
  long long r = INF;
  long long ans = 0;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (solve(mid)) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << ans;
  return 0;
}
