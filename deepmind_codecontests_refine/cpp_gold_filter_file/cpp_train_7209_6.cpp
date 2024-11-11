#include <bits/stdc++.h>
using namespace std;
bool bo(pair<long long int, long long int> a,
        pair<long long int, long long int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  return a.second > b.second;
}
struct comp {
  bool operator()(pair<long long int, long long int> a,
                  pair<long long int, long long int> b) const {
    if (a.first != b.first) {
      return a.first > b.first;
    }
    return a.second > b.second;
  }
};
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m, i, j, x, y, pref[100005], may = 0, ma = 0;
    vector<pair<long long int, long long int> > nos;
    vector<long long int> idk;
    cin >> n >> m;
    for (i = 0; i < m; i++) {
      cin >> x >> y;
      nos.push_back(make_pair(x, y));
      if (y > may) {
        may = y;
        ma = x;
      }
      if (y == may && x > ma) {
        ma = x;
      }
    }
    long long int ans = 0;
    sort(nos.begin(), nos.end(), bo);
    pref[0] = 0;
    pref[1] = nos[0].first;
    for (i = 1; i < m; i++) {
      pref[i + 1] = pref[i] + nos[i].first;
    }
    if (n <= m) {
      ans = pref[n];
    }
    if (n == 1) {
      cout << nos[0].first << "\n";
      continue;
    }
    for (i = 0; i < m; i++) {
      x = nos[i].first;
      y = nos[i].second;
      long long int temp = 0;
      long long int l = 0, r = m - 1, mi;
      while (l <= r) {
        mi = (l + r) / 2;
        if (nos[mi].first > y) {
          l = mi + 1;
        } else {
          r = mi - 1;
        }
      }
      if (l >= n) {
        continue;
      }
      if (x <= y) {
        if (l > n) {
          continue;
        }
        l = min(l, m);
        temp = pref[l] + x + max(0LL, n - l - 1) * y;
      } else {
        if (l > n || l > m) {
          continue;
        }
        l = min(l, m);
        temp = pref[l] + max(0LL, n - l) * y;
      }
      if (n > m) {
        ans = max(ans, pref[m - 1] + (n - m) * y);
      }
      ans = max(ans, temp);
    }
    cout << ans << "\n";
  }
  return 0;
}
