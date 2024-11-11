#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long double PI = 4 * atan(1);
long long w, n, m, a[100001], cum[200001], l, r, cur[100001], Min, cnt, rem;
bool check(long long x) {
  cnt = 0;
  rem = m;
  for (int i = 1; i < n + 1; i++) cum[i] = 0, cur[i] = a[i];
  for (int i = 1; i < n + 1; i++) {
    cum[i] += cum[i - 1];
    cur[i] += cum[i];
    if (cur[i] < x && rem > 0) {
      long long df = min(rem, x - cur[i]);
      rem -= df;
      cur[i] += df;
      cum[i] += df;
      cum[i + w] -= df;
    }
  }
  Min = 1e18;
  for (int i = 1; i < n + 1; i++) Min = min(Min, cur[i]);
  if (Min >= x) return true;
  return false;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> w;
  for (int i = 1; i < n + 1; i++) cin >> a[i];
  l = 1, r = 2e9;
  while (l < r) {
    long long mid = (l + r + 1) / 2LL;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l;
  return 0;
}
