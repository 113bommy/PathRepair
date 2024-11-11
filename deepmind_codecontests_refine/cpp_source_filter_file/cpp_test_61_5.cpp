#include <bits/stdc++.h>
constexpr int maxn = 2e5 + 5;
constexpr int inf = 1e9;
constexpr int mod = 1e9 + 7;
using namespace std;
using lint = long long;
using pii = pair<int, int>;
int t, n, a[maxn], b[maxn];
lint ans;
map<int, int> ma, mb;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      ma[a[i]]++;
      mb[b[i]]++;
    }
    ans = 1ll * n * (n - 1) * (n - 2) / 6;
    for (int i = 0; i < n; i++) ans -= (ma[a[i]] - 1) * (mb[b[i]] - 1);
    cout << ans << '\n';
    ma.clear();
    mb.clear();
  }
}
