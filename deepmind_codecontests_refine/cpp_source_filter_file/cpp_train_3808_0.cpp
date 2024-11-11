#include <bits/stdc++.h>
using namespace std;
const long long N = 2.5e5 + 5, MOD = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long n, m, a[N], maxx = -MOD, dp[N];
vector<long long> adj[55];
long long maxpref[55], maxsuff[55], tot[55];
long long kadane(long long idx) {
  long long maxsum = adj[idx][0], curmax = adj[idx][0], cnt = 0;
  for (auto u : adj[idx]) {
    cnt++;
    if (cnt == 1) continue;
    curmax = max(curmax + u, u);
    maxsum = max(maxsum, curmax);
  }
  return maxsum;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    long long l;
    cin >> l;
    while (l--) {
      long long x;
      cin >> x;
      adj[i].push_back(x);
      tot[i] += x;
    }
  }
  unordered_set<long long> s;
  set<long long> ans;
  for (long long i = 1; i <= m; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  for (auto u : s) {
    for (auto v : adj[u]) {
      maxx = max(maxx, v);
    }
  }
  if (maxx <= 0) {
    cout << 0 << endl;
    return 0;
  }
  for (auto u : s) {
    ans.insert(kadane(u));
  }
  for (long long i = 1; i <= n; i++) {
    long long sum = 0;
    for (auto u : adj[i]) {
      sum += u;
      maxpref[i] = max(maxpref[i], sum);
    }
    sum = 0;
    for (auto it = adj[i].rbegin(); it != adj[i].rend(); it++) {
      sum += *it;
      maxsuff[i] = max(maxsuff[i], sum);
    }
  }
  long long sum = 0;
  for (long long i = 1; i <= m; i++) {
    if (sum) ans.insert(sum + maxpref[a[i]]);
    sum = max(0LL, max(maxsuff[a[i]], sum + tot[a[i]]));
  }
  cout << *(ans.rbegin());
  return 0;
}
