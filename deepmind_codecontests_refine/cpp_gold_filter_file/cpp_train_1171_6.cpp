#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxn = 200005;
void solve() {
  int n, h, m, k;
  cin >> n >> h >> m >> k;
  vector<int> v;
  m /= 2;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    y++;
    v.push_back({y % m});
    int yy = v.back() + k - 1;
    if (yy < m) {
      mp[v.back()]++;
      mp[yy]--;
    } else {
      mp[v.back()]++;
      mp[0]++;
      mp[yy - m]--;
    }
  }
  int mi = 1e9;
  int ans = 0;
  int cur = 0;
  if (!mp[0]) {
    mi = 0;
    ans = 0;
  } else {
    for (auto &i : mp) {
      cur += i.second;
      if (cur < mi) {
        mi = cur;
        ans = i.first;
      }
    }
  }
  cout << mi << ' ' << ans << '\n';
  for (int i = 0; i < n; i++) {
    int x = v[i];
    if (v[i] <= ans && v[i] + k - 1 > ans) {
      cout << i + 1 << ' ';
    } else if (v[i] + k - 1 > m && v[i] + k - 1 - m > ans) {
      cout << i + 1 << ' ';
    }
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int c = 0;
  int t;
  if (!c) {
    t = 1;
  } else {
    cin >> t;
  }
  while (t--) {
    solve();
  }
}
