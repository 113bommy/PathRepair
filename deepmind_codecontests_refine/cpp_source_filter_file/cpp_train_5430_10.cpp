#include <bits/stdc++.h>
using namespace std;
void pr_init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long n, m;
vector<long long> a;
bool ok(long long mid) {
  long long n = a.size();
  vector<long long> t = a;
  if (m - t[0] <= mid) t[0] = 0;
  for (long long i = 1; i < n - 1; i++) {
    long long mv;
    if (t[i] < t[i - 1]) {
      if (mid < t[i - 1] - t[i]) return 0;
      t[i] = t[i - 1];
    } else {
      if (m + t[i - 1] - t[i] <= mid) t[i] = t[i - 1];
    }
  }
  return 1;
}
void solve() {
  cin >> n >> m;
  a.resize(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long i = 0, j = m - 1;
  while (i < j) {
    long long mid = (i + j) / 2;
    if (ok(mid))
      j = mid;
    else
      i = mid + 1;
  }
  cout << i << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
