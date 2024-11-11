#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
vector<vector<long long>> mul(vector<vector<long long>> a,
                              vector<vector<long long>> b) {
  vector<vector<long long>> ans(a.size(), vector<long long>(b[0].size(), INF));
  for (int i = 0; i < a.size(); i++)
    for (int j = 0; j < b[0].size(); j++)
      for (int k = 0; k < b.size(); k++)
        ans[i][j] = min(ans[i][j], a[i][k] + b[k][j]);
  return ans;
}
vector<vector<long long>> unit(int n) {
  vector<vector<long long>> ans(n, vector<long long>(n, INF));
  for (int i = 0; i < n; i++) ans[i][i] = 0;
  return ans;
}
vector<vector<long long>> power(vector<vector<long long>> base, int p) {
  if (p == 0) return unit(base.size());
  vector<vector<long long>> ans = power(base, p / 2);
  ans = mul(ans, ans);
  if (p % 2) ans = mul(ans, base);
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int x, k, n, q;
  cin >> x >> k >> n >> q;
  map<int, int> mp;
  vector<int> states;
  for (int i = 0; i < (1 << k); i++) {
    if (__builtin_popcount(i) != x) continue;
    states.push_back(i);
    mp[i] = states.size() - 1;
  }
  int z = states.size();
  vector<int> costs(k);
  for (int i = 0; i < k; i++) cin >> costs[i];
  vector<vector<long long>> tr(z, vector<long long>(z, INF));
  for (int i = 0; i < z; i++) {
    int mask = states[i];
    if (mask & 1) {
      for (int b = 1; b <= k; b++) {
        if (mask & (1 << b)) continue;
        int nwmask = (mask | (1 << b)) >> 1;
        int j = mp[nwmask];
        tr[i][j] = costs[b - 1];
      }
    } else {
      int j = mp[mask >> 1];
      tr[i][j] = 0;
    }
  }
  long long ans = 0;
  int en = n - x + 1;
  vector<pair<int, int>> events;
  for (int i = 0; i < q; i++) {
    int t, c;
    cin >> t >> c;
    if (t > en)
      ans += c;
    else
      events.push_back({t, c});
  }
  events.push_back({en, 0});
  sort(events.begin(), events.end());
  int cur = 1;
  int startstate = (1 << x) - 1;
  assert(mp.count(startstate) && mp[startstate] == 0);
  vector<vector<long long>> mn(1, vector<long long>(z, INF));
  mn[0][0] = 0;
  for (auto pr : events) {
    int nxt = pr.first;
    int d = nxt - cur;
    mn = mul(mn, power(tr, d));
    for (int i = 0; i < z; i++)
      if (states[i] & 1) {
        mn[0][i] += pr.second;
        mn[0][i] = min(mn[0][i], INF);
      }
    cur = nxt;
  }
  ans += mn[0][0];
  cout << ans << endl;
}
