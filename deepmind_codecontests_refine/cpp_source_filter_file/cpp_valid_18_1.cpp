#include <bits/stdc++.h>
using namespace std;
void read(vector<long long> &a) {
  for (long long i = 0; i < a.size(); i++) cin >> a[i];
}
void read(vector<string> &a) {
  for (long long i = 0; i < a.size(); i++) cin >> a[i];
}
bool intersect(pair<long long, long long> c, pair<long long, long long> d) {
  if (c.first > d.first) swap(c, d);
  return c.second > d.first and c.second < d.second;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<pair<long long, long long>> a;
  vector<bool> used(2 * n + 1, false);
  for (long long i = 0; i < k; i++) {
    long long x, y;
    cin >> x >> y;
    if (x < y)
      a.push_back({x, y});
    else
      a.push_back({y, x});
    used[x] = used[y] = true;
  }
  vector<long long> left;
  for (long long i = 1; i <= 2 * n; i++) {
    if (!used[i]) left.push_back(i);
  }
  for (long long i = 1; i <= n - k; i++) {
    a.push_back({left[i], left[n - k + i]});
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      if (intersect(a[i], a[j])) ans++;
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
