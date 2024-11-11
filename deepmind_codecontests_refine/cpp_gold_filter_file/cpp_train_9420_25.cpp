#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, inf = 1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int cnt[205];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int> > a(n);
  vector<int> suf(n + 1);
  int tot = 0;
  for (int i = 0; i < n; i++) cin >> a[i].first;
  for (int i = 0; i < n; i++) cin >> a[i].second;
  sort(a.begin(), a.end());
  int j = 0;
  int ans = inf;
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] + a[i].second;
  }
  for (int i = 0; i < n;) {
    while (j < n && a[i].first == a[j].first) {
      cnt[a[j].second]++;
      j++;
    }
    for (int l = i; l < j; l++) {
      int cost = suf[l + 1],
          x = max(0, l + 1 - ((l - i + 1) * 2 - 1 - (l - i + 1)) - (l - i + 1));
      cnt[a[l].second]--;
      for (int k = 1; k <= 200; k++) {
        cost += k * min(cnt[k], x);
        x -= min(cnt[k], x);
      }
      if (x == 0) ans = min(ans, cost);
    }
    for (int l = i; l < j; l++) cnt[a[l].second]++;
    i = j;
  }
  cout << ans << '\n';
  return 0;
}
