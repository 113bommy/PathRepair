#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  vector<long long> ans;
  set<long long> b;
  map<long long, pair<long long, long long>> otr;
  for (long long i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    a[i] = x;
    if (b.find(x) == b.end()) otr[x].first = i;
    otr[x].second = i;
    b.insert(x);
  }
  vector<long long> pref(n);
  pref[0] = max(0ll, a[0]);
  for (long long i = 1; i < n; ++i) {
    pref[i] = pref[i - 1];
    if (a[i] >= 0) pref[i] += a[i];
  }
  long long mx = -11111111, L = -1, R = -1;
  for (auto u : b) {
    long long l = otr[u].first, r = otr[u].second;
    if (l == r) continue;
    if (u * 2 + pref[r - 1] - pref[l] > mx)
      mx = u * 2 + pref[r - 1] - pref[l], L = l, R = r;
  }
  for (long long i = 0; i < L; ++i) {
    ans.push_back(i + 1);
  }
  for (long long i = L + 1; i <= R - 1; ++i) {
    if (a[i] < 0) ans.push_back(i + 1);
  }
  for (long long i = R + 1; i < n; ++i) {
    ans.push_back(i + 1);
  }
  cout << mx << ' ' << ans.size() << '\n';
  for (auto i : ans) cout << i << ' ';
}
