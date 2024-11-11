#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 5;
long long n, k, p, depth[maxn], cnt[maxn];
vector<long long> vc, sum, g[maxn];
inline void dfs(long long v, long long p = -1, long long d = 0) {
  depth[v] = d;
  cnt[d]++;
  for (long long i = 0; i < g[v].size(); i++)
    if (g[v][i] != p) dfs(g[v][i], v, d + 1);
}
inline bool ok(long long x) {
  for (long long i = x - 1; i < n; i++) {
    long long tot = x * vc[i] - (sum[i] - ((i - x) >= 0 ? sum[i - x] : 0));
    if (tot <= p) return 1;
  }
  return 0;
}
inline long long BS(long long fi, long long se) {
  if (fi == se) return fi;
  long long mid = (fi + se) / 2;
  if (ok(mid + 1)) return BS(mid + 1, se);
  return BS(fi, mid);
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin >> n >> k >> p;
  if (k == 0) {
    cout << 0 << endl;
    exit(0);
  }
  for (long long u, v, i = 0; i + 1 < n; i++) {
    cin >> u >> v;
    u--, v--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  dfs(0);
  for (long long i = 1; i < maxn; i++)
    for (long long j = 0; j < cnt[i]; j++) {
      vc.push_back(i);
      if (vc.size() > 1)
        sum.push_back(sum.back() + vc.back());
      else
        sum.push_back(vc.back());
    }
  cout << BS(0, min(n - 1, k)) << endl;
}
