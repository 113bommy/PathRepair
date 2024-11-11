#include <bits/stdc++.h>
using namespace std;
vector<long long> a(5005);
long long res;
long long help(long long l, long long r) {
  if (r < l) return 0;
  long long cur = INT_MAX;
  for (long long i = l; i <= r; i++) cur = min(cur, a[i]);
  for (long long i = l; i <= r; i++) a[i] -= cur;
  long long i = l, second = l;
  for (; i <= r; i++) {
    if (!a[i]) {
      cur += help(second, i - 1);
      second = i + 1;
    }
  }
  if (second != r) cur += help(second, r);
  return min(cur, r - l + 1);
}
void solve() {
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long cur = 0, i = 0;
  res = 0;
  for (; i < n; i++) {
    if (!a[i]) {
      res += help(cur, i - 1);
      cur = i + 1;
    }
  }
  if (cur != n) res += help(cur, n);
  cout << min(res, n);
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
}
