#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 228;
const long long oo = 1e9;
const long long K = 300;
const long long mod = 998244353;
mt19937_64 rnd(time(0));
int n, k, a[N], p[N];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) p[i] = 0;
  map<int, int> last;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[a[i]] = max(p[a[i]], i - last[a[i]]);
    last[a[i]] = i;
  }
  for (int i = 1; i <= n; ++i) p[i] = max(p[i], n - last[i] + 1);
  vector<pair<int, int> > v;
  for (int i = 1; i <= n; ++i)
    if (p[i]) v.push_back({p[i], i});
  sort(v.begin(), v.end());
  int l = 0;
  int mn = oo;
  for (int i = 1; i <= n; ++i) {
    while (l < v.size() && v[l].first <= i) mn = min(mn, v[l].second), l++;
    if (mn == oo)
      cout << -1;
    else
      cout << mn;
    cout << ' ';
  }
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
