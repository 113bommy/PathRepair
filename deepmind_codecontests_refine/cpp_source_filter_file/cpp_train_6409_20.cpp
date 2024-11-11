#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int dx[] = {0, 0, 1, -1};
long long int dy[] = {1, -1, 0, 0};
long long int m = 0, n, res = 0, k;
string s2, ch = "", s, t, s1 = "";
vector<pair<string, long long int> > vm;
vector<pair<pair<long long int, long long int>, long long int> > vvv;
vector<pair<long long int, long long int> > vv;
vector<pair<string, long long int> > vv2;
vector<long long int> v;
set<long long int> st;
long long int a[1000005], b[200005], c[200005], d[200005], dp[200005];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long int i = 0, x = 0, z = 0, y = 0, j = 0, q, mx = 0, idx = 0, ok = 0,
                l = 0, r = 0, negatif = 0, positif = 0, l1, r1, p;
  set<long long int>::iterator itp, it;
  set<long long int>::iterator it1;
  cin >> n >> m >> k;
  long long int s;
  cin >> x >> s;
  res = 1e18;
  for (i = 1; i <= m; i++) cin >> a[i];
  for (i = 1; i <= m; i++) {
    cin >> b[i];
    if (b[i] <= s) {
      res = min(res, a[i] * n);
    }
    vv.push_back({b[i], a[i]});
  }
  sort(vv.begin(), vv.end());
  for (i = 0; i < vv.size(); i++) v.push_back(vv[i].first);
  dp[0] = vv[0].second;
  for (i = 1; i < m; i++) {
    dp[i] = min(vv[i].second, dp[i - 1]);
  }
  long long int ans;
  for (i = 1; i <= k; i++) cin >> c[i];
  for (i = 1; i <= k; i++) {
    cin >> d[i];
    if (d[i] <= s) {
      res = min(res, (n - c[i]) * x);
    }
  }
  for (i = k - 1; i >= 1; i--) {
    if (d[i] == d[i + 1]) c[i] = c[i + 1];
  }
  for (i = 1; i <= m; i++) {
    if (b[i] >= s) break;
    z = (s - b[i]);
    idx = lower_bound(d + 1, d + 1 + k, z) - d;
    if (idx > k || d[idx] > z) idx--;
    if (idx < 1) continue;
    long long int cur = n;
    cur -= c[idx];
    ans = 0;
    if (cur >= 0) {
      ans = cur * a[i];
    }
    res = min(res, ans);
  }
  for (i = 1; i <= k; i++) {
    if (d[i] >= s) break;
    z = (s - d[i]);
    idx = lower_bound(v.begin(), v.end(), z) - v.begin();
    if (idx >= v.size() || v[idx] > z) idx--;
    if (idx < 0) continue;
    long long int cur = n;
    cur -= c[i];
    ans = 0;
    if (cur >= 0) {
      ans = cur * dp[idx];
    }
    res = min(res, ans);
  }
  res = min(res, x * n);
  if (res < 0) res = 0;
  cout << res;
  return 0;
}
