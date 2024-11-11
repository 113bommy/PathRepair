#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
using namespace std;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int inf = (2e9 + 7);
const int mod = 1e9 + 7;
const int MAXN = 1e5 + 5;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(15);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    k = min(k, m - 1);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int st = n - m;
    vector<int> v;
    for (int i = 0; i < n - st; ++i) {
      v.push_back(max(a[i], a[i + st]));
    }
    int len = m - k;
    int ans = 0;
    int l = 0, r = len;
    int sz = v.size();
    map<int, int> ma;
    for (int i = 0; i < len; ++i) ma[v[i]]++;
    ans = ma.begin()->first;
    while (r < sz) {
      if (ma[v[l]] == 1)
        ma.erase(v[l++]);
      else
        ma[v[l++]]--;
      ma[v[r++]]++;
      ans = max(ans, ma.begin()->first);
    }
    cout << ans << endl;
  }
  return 0;
}
