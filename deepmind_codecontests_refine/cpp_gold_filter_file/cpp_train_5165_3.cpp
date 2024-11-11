#include <bits/stdc++.h>
using namespace std;
const long long MAXN = (long long)((1e5) + 10);
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
long long min(long long a, long long b) {
  if (a < b)
    return a;
  else
    return b;
}
bool isPrime(long long N) {
  for (long long i = 2; i * i <= N; ++i) {
    if (N % i == 0) return false;
  }
  return true;
}
long long cbrt(long long x) {
  long long lo = 1, hi = min(2000000ll, x);
  while (hi - lo > 1) {
    long long mid = (lo + hi) / 2;
    if (mid * mid * mid < x) {
      lo = mid;
    } else
      hi = mid;
  }
  if (hi * hi * hi <= x)
    return hi;
  else
    return lo;
}
const long long dx[4] = {-1, 1, 0, 0};
const long long dy[4] = {0, 0, -1, 1};
const long long nax = (long long)(100000 + 10);
vector<string> v;
vector<pair<long long, long long>> adj[300005], ans1;
long long INF = 10000000000000000;
set<long long> st;
string ss;
long long a, b, c, d, n, m, k = 0, f = 0, mm = 0, h = 0, t, res = 0, tmp = 0,
                            flag = 1, s, x, src, root = 1;
long long vis[400004], dp[5005][5005], ans[400005], dis[400005], val[300005];
map<pair<long long, long long>, long long> mp, ab;
bool dfs(long long u) {
  if (vis[u]++) return 1;
  long long degree = 0;
  for (auto &i : adj[u]) {
    if (!dfs(i.first)) {
      degree += 1;
      st.insert(i.second);
    }
  }
  return (val[u] == -1 || val[u] == degree % 2);
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    cin >> val[i];
    if (val[i] == -1) {
      root = i;
    }
  }
  for (long long i = 1; i <= m; i++) {
    cin >> a >> b;
    adj[a].push_back({b, i});
    adj[b].push_back({a, i});
  }
  if (!dfs(root)) {
    cout << -1 << "\n";
  } else {
    cout << st.size() << "\n";
    for (long long x : st) {
      cout << x << "\n";
    }
  }
}
