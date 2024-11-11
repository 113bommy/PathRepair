#include <bits/stdc++.h>
using namespace std;
void debug_arr(vector<long long> &a) {
  long long len = a.size();
  for (long long i = 0; i < len; ++i) {
    cout << a[i] << " ";
  }
  cout << "\n";
}
const long long mod = 1e9 + 7;
const long long mod1 = 998244353;
void solve() {
  long long n, k, l, first = 1;
  cin >> n >> k >> l;
  vector<long long> d(n + 1), p(2 * k);
  for (long long i = 1; i < n + 1; ++i) cin >> d[i];
  for (long long i = 0; i < k + 1; ++i) p[i] = i;
  long long j = k - 1;
  for (long long i = k + 1; i < 2 * k; ++i) p[i] = j--;
  long long t, t1, pos = 2 * k - 1;
  for (long long i = 0; i < n + 1; ++i) {
    if (i && d[i] + p[pos % (2 * k)] > l) {
      first = 0;
      break;
    }
    if (i == n) break;
    t = -d[i + 1] + l;
    t1 = max(k, 2 * k - t);
    if (i == 0 || k + d[i] <= l || (pos >= k && t1 - pos > 0))
      pos = t1 % (2 * k);
    else
      pos = (pos + 1) % (2 * k);
  }
  if (first)
    cout << "Yes"
         << "\n";
  else
    cout << "No"
         << "\n";
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
