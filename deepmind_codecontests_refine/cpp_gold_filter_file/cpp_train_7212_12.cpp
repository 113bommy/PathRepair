#include <bits/stdc++.h>
using namespace std;
const int N = 3030;
const int MOD = 1e9 + 7;
const long long INF = 4e18;
vector<long long> a[N], f[N], now;
int n, k, t[N];
long long sum[N], ans;
vector<long long> dp(vector<long long> &v, int l, int r) {
  vector<long long> res = v;
  for (int i = l; i <= r; i++) {
    for (int j = k; j >= a[i].size(); j--) {
      res[j] = max(res[j], res[j - a[i].size()] + sum[i]);
    }
  }
  return res;
}
void solve(int l, int r) {
  long long res = 0;
  if (l == r) {
    ans = max(ans, now[k]);
    for (int i = 1; i <= a[l].size(); i++) {
      res += a[l][i - 1];
      ans = max(ans, res + now[k - i]);
    }
    return;
  }
  int mid = l + r >> 1;
  vector<long long> tmp = now;
  now = dp(tmp, mid + 1, r);
  solve(l, mid);
  now = dp(tmp, l, mid);
  solve(mid + 1, r);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  now.resize(k + 1, -INF);
  now[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
    for (int j = 1, tt; j <= t[i]; j++) {
      cin >> tt;
      a[i].push_back(tt);
      sum[i] += tt;
    }
    while (a[i].size() > k) {
      sum[i] -= a[i].back();
      a[i].pop_back();
    }
  }
  solve(1, n);
  cout << ans;
}
