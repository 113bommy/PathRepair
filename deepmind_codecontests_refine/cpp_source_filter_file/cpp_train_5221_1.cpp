#include <bits/stdc++.h>
using namespace std;
inline long long bip(long long x, long long n, long long mod) {
  long long res = 1;
  while (n) {
    if (n & 1) {
      res = (res * x) % mod;
    }
    x = (x * x) % mod;
    n >>= 1;
  }
  return res;
}
const int maxn = 1e9;
const long long inf = 1e18;
const int mod = 1e9 + 7;
const int N = 3e5 + 10;
int n, a[1511];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  map<int, vector<pair<int, int>>> sumsegs;
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = i; j <= n; j++) {
      sum += a[j];
      sumsegs[sum].push_back({i, j});
    }
  }
  int ans = 0;
  vector<pair<int, int>> best;
  for (auto it : sumsegs) {
    vector<pair<int, int>> v = it.second;
    int cur = 0, r = -1;
    vector<pair<int, int>> now;
    for (auto seg : v) {
      if (seg.first > r) {
        cur++;
        now.push_back(seg);
        r = seg.second;
      }
    }
    if (cur > ans) {
      ans = cur;
      best = now;
    }
  }
  cout << ans << endl;
  for (auto it : best) cout << it.first << ' ' << it.second << endl;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tt = 1;
  while (tt--) {
    solve();
    cout << '\n';
  }
}
