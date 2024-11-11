#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll LINF = 1001002003004005006ll;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(n), sum(k + 1, 0);
  for (int i = 0; i < (n); i++) cin >> a[i];
  sort(a.begin(), a.end());
  a.resize(k);
  for (int i = 0; i < (k); i++) sum[i + 1] = sum[i] + a[i];
  vector<int> b(k + 1, 0);
  for (int i = 0; i < (m); i++) {
    int x, y;
    cin >> x >> y;
    if (x > k) continue;
    b[x] = y;
  }
  vector<ll> dp(k + 1, LINF);
  dp[0] = 0;
  for (int i = 0; i < (k); i++) {
    for (int j = i + 1; j <= k; j++) {
      chmin(dp[j], dp[i] + sum[j] - sum[i + b[j - i]]);
    }
  }
  cout << dp[k] << endl;
  return 0;
}
