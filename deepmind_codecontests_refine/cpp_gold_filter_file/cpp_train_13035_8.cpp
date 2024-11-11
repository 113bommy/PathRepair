#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;
const int INF = 0x3f3f3f3f, N = 2e5 + 5;
const ll LINF = 1e18 + 5;
int t;
int n, s, k, a[N];
map<int, bool> vis;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> s >> k;
    vis.clear();
    for (int i = 1; i <= k; i++) {
      cin >> a[i];
      vis[a[i]] = 1;
    }
    int ans = INF;
    for (int i = s; i >= 1; i--) {
      if (!vis[i]) {
        ans = s - i;
        break;
      }
    }
    for (int i = s; i <= n; i++) {
      if (!vis[i]) {
        ans = min(ans, i - s);
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
