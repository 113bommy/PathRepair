#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mxN = 200001;
int n, k, s, t;
pair<ll, ll> arr[mxN];
vector<ll> gas;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k >> s >> t;
  ll a, b;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    arr[i] = {a, b};
  }
  for (int i = 0; i < k; ++i) {
    cin >> a;
    gas.push_back(a);
  }
  sort(gas.begin(), gas.end());
  int l = 0;
  int r = 1e9 + 10;
  while (l < r) {
    int mid = l + (r - l) / 2;
    int tt = 0;
    int pos = 0;
    bool ok = true;
    for (int i = 0; i < k; ++i) {
      if (gas[i] - pos > mid) {
        ok = false;
        break;
      }
      tt += 2 * (gas[i] - pos) - min(gas[i] - pos, mid - gas[i] + pos);
      pos = gas[i];
    }
    if (s - pos > mid) ok = false;
    tt += 2 * (s - pos) - min(s - pos, mid - s + pos);
    if (ok && tt <= t) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  ll ans = INF;
  for (int i = 0; i < n; ++i) {
    if (arr[i].second < l) continue;
    ans = min(ans, arr[i].first);
  }
  if (ans == INF) {
    cout << "-1\n";
  } else {
    cout << ans << "\n";
  }
  return 0;
}
