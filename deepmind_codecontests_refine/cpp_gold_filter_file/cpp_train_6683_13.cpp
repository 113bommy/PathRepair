#include <bits/stdc++.h>
using namespace std;
const int ms = int(1e5) + 10;
long long n, a[ms];
long long k, sum[ms];
long long get(int l, int r) {
  if (l > r) return 0;
  return sum[r] - (l == 0 ? 0 : sum[l - 1]);
}
bool can(int diff) {
  long long ans = 1e18;
  for (int i = 0; i < n; i++) {
    int pos = int(lower_bound(a, a + n, a[i] + diff) - a);
    long long val = (i + 1) * a[i] - get(0, i);
    val += get(pos, n - 1) - (n - pos) * (a[i] + diff);
    ans = min(ans, val);
  }
  for (int i = 0; i < n; i++) {
    int pos = int(upper_bound(a, a + n, a[i] - diff) - a);
    long long val = get(i, n - 1) - a[i] * (n - i);
    val += pos * (a[i] - diff) - get(0, pos - 1);
    ans = min(ans, val);
  }
  return ans <= k;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; i++) sum[i] = a[i] + (i == 0 ? 0 : sum[i - 1]);
  int l = 0, r = a[n - 1] - a[0], ans = r;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (can(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << ans << endl;
  return 0;
}
