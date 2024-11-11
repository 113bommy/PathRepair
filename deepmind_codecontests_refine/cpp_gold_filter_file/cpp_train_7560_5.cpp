#include <bits/stdc++.h>
const bool DEBUG = false;
using namespace std;
const long long maxn = 1e5 + 2;
const long long INF = 4e18;
const long long M = 1e9 + 7;
const int lg = 21;
const int z = 256 * 256;
int n, m, a[maxn], t[maxn], dp[maxn];
string s;
vector<int> g[2], v[2];
bool f(vector<int>(&v), int l, int r) {
  if (lower_bound(v.begin(), v.end(), l) == v.end()) return 1;
  int l1 = lower_bound(v.begin(), v.end(), l) - v.begin();
  if (lower_bound(v.begin(), v.end(), r + 1) == v.end()) return 0;
  int l2 = lower_bound(v.begin(), v.end(), r + 1) - v.begin();
  if (l1 == l2) return 1;
  return 0;
}
bool check(int l, int r) {
  if (l % 2 == 0)
    if (f(v[1], l, r) and f(g[0], l, r)) return 1;
  if (l % 2 == 1)
    if (f(v[0], l, r) and f(g[1], l, r)) return 1;
  return 0;
}
int par(int l, int r) {
  if (l == 0) return a[r];
  return a[r] - a[l - 1];
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> s >> m;
  a[0] = bool(s[0] == '?');
  for (int i = 1; i < n; i++) a[i] = a[i - 1] + bool(s[i] == '?');
  for (int i = 0; i < n; i++)
    if (s[i] == 'a')
      v[(i % 2)].push_back(i);
    else if (s[i] == 'b')
      g[(i % 2)].push_back(i);
  t[n - m] = check(n - m, n - 1);
  for (int i = n - m - 1; i >= 0; i--) {
    if (check(i, i + m - 1))
      t[i] = 1 + t[i + m];
    else
      t[i] = t[i + 1];
  }
  int maxx = t[0];
  if (t[n - m] == 1) dp[n - m] = par(n - m, n - 1);
  for (int i = n - m - 1; i >= 0; i--) {
    if (check(i, i + m - 1)) {
      dp[i] = par(i, i + m - 1) + dp[i + m];
      if (t[i + 1] == t[i]) dp[i] = min(dp[i], dp[i + 1]);
    } else
      dp[i] = dp[i + 1];
  }
  cout << dp[0] << endl;
  return 0;
}
