#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<long long> x;
int n, m;
bool solve(long long maxn) {
  for (int i = 0; i < n; ++i) x[i] = a[i];
  x[n - 1] = min(m - 1LL, x[n - 1] + maxn);
  for (int i = n - 2; i >= 0; --i) {
    if (x[i] <= x[i + 1])
      x[i] += min(x[i + 1] - x[i], maxn);
    else {
      if (maxn - m + x[i] < 0) return false;
      x[i] = min(x[i + 1], maxn - m + x[i]);
    }
  }
  return true;
}
signed main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  a.resize(n);
  x.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  long long lo = 0, hi = 1LL << 40;
  while (lo < hi) {
    auto mid = (lo + hi) / 2;
    if (solve(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << hi << '\n';
  return 0;
}
