#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k, x;
  cin >> k;
  vector<long long> arr[k];
  unordered_map<long long, long long> mp;
  vector<long long> ssum(k, 0);
  long long sum = 0;
  for (long long i = 0; i < k; i++) {
    cin >> n;
    for (long long j = 0; j < n; j++) {
      cin >> x;
      ssum[i] += x;
      arr[i].push_back(x);
      mp[x] = i;
    }
    sum += ssum[i];
  }
  if (sum % k != 0) {
    cout << "No";
    return;
  }
  sum /= k;
  long long sz = (1LL << k);
  vector<pair<long long, long long> > done[sz];
  vector<bool> vis(k, 0);
  for (long long i = 0; i < k; i++) {
    for (auto x : arr[i]) {
      for (long long y = 0; y < k; y++) vis[y] = 0;
      long long last = i;
      long long elm = x;
      long long mask = (1LL << i);
      vector<pair<long long, long long> > way;
      while (way.size() < k) {
        if (mp.find(sum - (ssum[last] - elm)) == mp.end()) break;
        long long v = mp[sum - (ssum[last] - elm)];
        if (vis[v] == 1) break;
        vis[v] = 1;
        mask |= (1LL << v);
        way.push_back({sum - (ssum[last] - elm), last});
        elm = sum - (ssum[last] - elm);
        last = v;
      }
      if (x == elm && last == i) done[mask] = way;
    }
  }
  for (long long i = 1; i < sz; i++) {
    for (long long s = i;; s = (s - 1) & i) {
      long long a = s;
      long long b = (s ^ i);
      if (!done[a].empty() && !done[b].empty()) {
        done[i] = done[a];
        for (auto z : done[b]) done[i].push_back(z);
        break;
      }
      if (s == 0) break;
    }
  }
  if (!done[sz - 1].empty()) {
    cout << "Yes\n";
    vector<pair<long long, long long> > final(k);
    for (auto x : done[sz - 1]) final[mp[x.first]] = x;
    for (long long i = 0; i < k; i++)
      cout << final[i].first << " " << final[i].second + 1 << "\n";
  } else
    cout << "No\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
}
