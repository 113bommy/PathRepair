#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e18 + 10, M = 2e5 + 137;
long long a[M], f[M], g[M];
vector<long long> ve[M];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    set<long long> st;
    map<long long, long long> mp;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      st.insert(a[i]);
    }
    long long c = 0;
    for (int u : st) mp[u] = ++c;
    for (int i = 0; i <= n + 1; i++) ve[i].clear();
    for (int i = 1; i <= n; i++) ve[mp[a[i]]].push_back(i);
    long long ans = n;
    ve[c + 1].push_back(-1);
    ve[0].push_back(n + 1);
    f[c + 1] = 0;
    g[c + 1] = c + 1;
    for (int i = c; i > 0; i--) {
      f[i] = ve[i].size();
      g[i] = i;
      if (ve[i].back() < ve[i + 1][0]) f[i] += f[i + 1], g[i] = g[i + 1];
      long long ri = lower_bound(ve[g[i] + 1].begin(), ve[g[i] + 1].end(),
                                 ve[g[i]].back() + 1) -
                     ve[g[i] + 1].begin();
      ri = ve[g[i] + 1].size() - ri;
      long long le = lower_bound(ve[i - 1].begin(), ve[i - 1].end(), ve[i][0]) -
                     ve[i - 1].begin();
      ans = min(ans, n - f[i] - le - ri);
    }
    for (int i = 2; i <= c; i++) {
      long long x = 0;
      for (int u : ve[i]) {
        long long ri = lower_bound(ve[i - 1].begin(), ve[i - 1].end(), u) -
                       ve[i - 1].begin();
        long long cur = ve[i].size() - x;
        ans = min(ans, n - cur - ri);
        x++;
      }
    }
    cout << ans << "\n";
  }
}
