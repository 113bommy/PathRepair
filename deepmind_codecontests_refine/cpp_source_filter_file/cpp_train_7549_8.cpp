#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long MOD = 998244353;
inline long long add(long long x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
inline long long sub(long long x, long long y) {
  x -= y;
  if (x < 0) x += mod;
  return x;
}
inline long long mul(long long x, long long y) { return (x * 1ll * y) % mod; }
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
vector<pair<long long, long long>> v;
vector<long long> adj[100100];
long long n, m;
long long in[200100];
bool che(long long x) {
  long long innn[100100] = {0};
  vector<long long> ad[100100];
  long long a, b;
  for (long long i = 1; i <= x; i++) {
    a = v[i].first, b = v[i].second;
    innn[b]++;
    ad[a].push_back(b);
  }
  bool cnt = false;
  priority_queue<long long> pq;
  for (long long i = 1; i <= n; i++) {
    if (innn[i] == 0) pq.push(i);
  }
  while (!pq.empty()) {
    if (pq.size() >= 2) {
      cnt = true;
      break;
    }
    long long k = pq.top();
    pq.pop();
    for (auto it : ad[k]) {
      innn[it]--;
      if (innn[it] == 0) pq.push(it);
    }
  }
  if (cnt) return false;
  return true;
}
signed main() {
  cin >> n >> m;
  long long a, b;
  v.push_back({0, 0});
  for (long long i = 0; i < m; i++) {
    cin >> a >> b;
    in[b]++;
    adj[a].push_back(b);
    v.push_back({a, b});
  }
  long long cnt = 0;
  for (long long i = 1; i <= n; i++)
    if (in[i] == 0) cnt++;
  if (cnt != 1)
    cout << -1;
  else {
    long long ans = m;
    long long l = 1, r = m;
    while (l < r) {
      long long mid = (l + r) / 2;
      if (che(mid)) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    cout << ans;
  }
}
