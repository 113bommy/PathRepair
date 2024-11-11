#include <bits/stdc++.h>
using namespace std;
const int32_t INFint = 1e9;
const long long INFll = 1e18;
const long long INF = 9e18;
const long double PI = acos(-1);
long long powersOfTwo[31] = {
    1,         2,         4,         8,        16,       32,       64,
    128,       256,       512,       1024,     2048,     4096,     8192,
    16384,     32768,     65536,     131072,   262144,   524288,   1048576,
    2097152,   4194304,   8388608,   16777216, 33554432, 67108864, 134217728,
    268435456, 536870912, 1073741824};
long long power(long long x, long long y) {
  long long r = 1;
  while (y > 0) {
    if (y & 1) r = r * x;
    y = y >> 1;
    x = x * x;
  }
  return r;
}
long long powerMod(long long x, long long y, long long p) {
  long long res = 1;
  x %= p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long n, m;
vector<pair<long long, long long>> edges[1050];
vector<long long> visited(1050);
vector<long long> indeg(1050);
vector<long long> outdeg(1050);
vector<pair<long long, pair<long long, long long>>> ans;
long long minDiam;
long long en;
void dfs(long long src, long long mn) {
  visited[src] = true;
  for (auto it : edges[src]) {
    if (not visited[it.first]) {
      mn = min(mn, it.second);
      if (indeg[it.first] == 1 and outdeg[it.second] == 0) {
        minDiam = mn;
        en = it.first;
      }
      dfs(it.first, mn);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tt = 1;
  while (tt--) {
    cin >> n >> m;
    for (long long i = 0; i < m; i++) {
      long long x, y, z;
      cin >> x >> y >> z;
      edges[x].push_back({y, z});
      outdeg[x]++;
      indeg[y]++;
    }
    for (long long i = 1; i <= n; i++) {
      if (not visited[i]) {
        if (indeg[i] == 0 and outdeg[i] == 1) {
          long long mn = INT_MAX;
          en = 0;
          minDiam = 0;
          dfs(i, mn);
          ans.push_back({i, {en, minDiam}});
        }
      }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (long long i = 0; i < ans.size(); i++) {
      cout << ans[i].first << " " << ans[i].second.first << " "
           << ans[i].second.second << '\n';
    }
  }
  cerr << "Time : " << 1000 * (long double)clock() / (long double)CLOCKS_PER_SEC
       << "ms\n";
  ;
}
