#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
vector<int> gph[505050];
long long arr[505050];
int gp[505050];
pair<int, int> UM[505050];
long long sm[505050];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) vector<int>().swap(gph[i]);
    for (int i = 0; i < n; ++i) gp[i] = 0;
    for (int i = 0; i <= m; ++i) UM[i] = {-1, -1};
    for (int i = 0; i <= m; ++i) sm[i] = 0;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      --x;
      --y;
      gph[x].push_back(y);
    }
    int cnt = 1;
    for (int i = 0; i < n; ++i) {
      for (auto j : gph[i]) {
        if (UM[gp[j]].first == i) {
          gp[j] = UM[gp[j]].second;
        } else {
          UM[gp[j]] = {i, cnt++};
          gp[j] = UM[gp[j]].second;
        }
      }
    }
    for (int i = 0; i < n; ++i) sm[gp[i]] += arr[i];
    int ans = 0;
    for (int i = 0; i < cnt; ++i) ans = gcd(sm[i], ans);
    cout << ans << '\n';
  }
  return 0;
}
