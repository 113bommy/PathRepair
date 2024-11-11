#include <bits/stdc++.h>
using namespace std;
const long long maxm = 1e6 + 5;
long long d[maxm];
long long a[maxm];
long long n;
long long ask(long long l, long long r, long long x) {
  long long ans = 0;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (a[mid] <= x) {
      ans = mid, l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return ans;
}
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (long long i = 1; i <= n; i++) {
    d[i] = d[i - 1] + 20;
    d[i] = min(d[i], d[ask(1, i - 1, a[i] - 90 + 1)] + 50);
    d[i] = min(d[i], d[ask(1, i - 1, a[i] - 1440 + 1)] + 120);
  }
  for (long long i = 1; i <= n; i++) {
    cout << d[i] - d[i - 1] << endl;
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
