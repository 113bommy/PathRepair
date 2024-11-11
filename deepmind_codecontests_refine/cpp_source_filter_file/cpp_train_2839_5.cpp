#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 10;
long long a[maxn], pre[maxn];
long long solve(long long gg) {
  long long l = -1e9 + 10, r = 1e9 + 10;
  long long tt = 0;
  while (l <= r) {
    long long mid = (l + r) / 2;
    long long ans = pre[1] - mid + gg;
    if (mid == ans) {
      tt = ans;
      break;
    }
    if (mid > ans)
      r = mid - 1, tt = mid;
    else
      l = mid + 1, tt = ans;
  }
  return tt;
}
int main() {
  int n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long sum = 0;
  pre[1] = a[1];
  for (long long i = 2; i <= n; i++) {
    pre[i] = a[i] - a[i - 1];
    if (pre[i] > 0) sum += pre[i];
  }
  cout << solve(sum) << endl;
  int q;
  cin >> q;
  while (q--) {
    long long l, r, e;
    cin >> l >> r >> e;
    if (l != 1 && pre[l] > 0) sum -= pre[l];
    if (r + 1 != n + 1 && pre[r + 1] > 0) sum -= pre[r + 1];
    pre[l] += e;
    pre[r + 1] -= e;
    if (l != 1 && pre[l] > 0) sum += pre[l];
    if (r + 1 != n + 1 && pre[r + 1] > 0) sum += pre[r + 1];
    cout << solve(sum) << endl;
  }
  return 0;
}
