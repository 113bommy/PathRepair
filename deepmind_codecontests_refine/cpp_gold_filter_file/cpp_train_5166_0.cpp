#include <bits/stdc++.h>
using namespace std;
long long calc(long long asum, long long bsum) { return abs(asum + bsum); }
long long getmin(long long asum, vector<long long> &jvals) {
  long long l = 1;
  long long r = (long long)jvals.size() - 1;
  long long ans = INT_MAX;
  while (l <= r) {
    long long mid = l + (r - l) / 2;
    long long left = calc(asum, jvals[mid - 1]);
    long long current = calc(asum, jvals[mid]);
    long long right = calc(asum, jvals[mid + 1]);
    if (left >= current && current <= right) {
      ans = current;
      break;
    } else if (left >= current && current >= right)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return ans;
}
signed main(void) {
  cin.tie(0)->sync_with_stdio(0);
  long long n, m, q;
  cin >> n >> m >> q;
  long long asum = 0;
  long long p = 1;
  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    asum += a * p - a * (p ^ 1);
    p ^= 1;
  }
  vector<long long> b(m);
  vector<long long> jvals;
  set<long long> jset;
  for (auto &x : b) cin >> x;
  long long window = 0;
  for (long long i = 0; i < n; i++)
    window += b[i] * (i % 2 == 1) - b[i] * (i % 2 == 0);
  jset.insert(window);
  p = 0;
  for (long long i = n; i < m; i++) {
    window += b[i] * (i % 2 == 1) - b[i] * (i % 2 == 0);
    long long r = i - n;
    window -= b[r] * (r % 2 == 1) - b[r] * (r % 2 == 0);
    jset.insert(window * p - window * (p ^ 1));
    p ^= 1;
  }
  jset.insert(-1e18);
  jset.insert(+1e18);
  for (auto x : jset) jvals.push_back(x);
  cout << getmin(asum, jvals) << "\n";
  for (long long i = 0; i < q; i++) {
    long long l, r, x;
    cin >> l >> r >> x;
    if ((r - l) % 2 == 0) asum += x * (l % 2 == 1) - x * (l % 2 == 0);
    cout << getmin(asum, jvals) << "\n";
  }
}
