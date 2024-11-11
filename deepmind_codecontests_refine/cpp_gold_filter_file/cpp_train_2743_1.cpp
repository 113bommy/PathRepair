#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
set<long long> dep[100010];
long long n, v[210];
long long dist(long long a, long long b) {
  if (b >= a) return b - a;
  return 3 - a + b;
}
long long check(long long index) {
  vector<bool> vis(210, false);
  map<long long, long long> cnt;
  long long ans = 0;
  for (long long i = 0; i < n; i++) cnt[i] += dep[i].size();
  while (true) {
    vector<long long> free;
    for (long long i = 0; i < n; i++) {
      if (!vis[i] and cnt[i] == 0) {
        free.push_back(i);
      }
    }
    long long id = -1, mn = 10;
    for (long long i : free) {
      if (dist(index, v[i]) < mn) {
        id = i, mn = dist(index, v[i]);
      }
    }
    if (id != -1) {
      vis[id] = true;
      ans += dist(index, v[id]) + 1;
      for (long long i = 0; i < n; i++) {
        if (dep[i].find(id) != dep[i].end()) cnt[i]--;
      }
      index = (index + dist(index, v[id])) % 3;
    } else
      break;
  }
  for (long long i = 0; i < n; i++)
    if (!vis[i]) return LLONG_MAX;
  return ans;
}
void solve() {
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    v[i]--;
  }
  for (long long i = 0; i < n; i++) {
    long long k;
    cin >> k;
    for (long long j = 0; j < k; j++) {
      long long tp;
      cin >> tp;
      tp--;
      dep[i].insert(tp);
    }
  }
  long long ans = LLONG_MAX;
  for (long long i = 0; i < 3; i++) {
    ans = min(ans, check(i));
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t = 1;
  while (t--) solve();
  return 0;
}
