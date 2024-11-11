#include <bits/stdc++.h>
using namespace std;
long long a[1010000], p[1010000];
void insert(long long x) {
  for (int j = 62; j >= 0; j--)
    if ((x >> j) & 1) {
      if (p[j])
        x ^= p[j];
      else {
        p[j] = x;
        break;
      }
    }
}
long long getans(long long ans) {
  for (int i = 62; i >= 0; i--) {
    if (((ans >> i) & 1) == 0)
      continue;
    else if (p[i])
      ans ^= p[i];
  }
  return ans;
}
vector<pair<int, long long> > g[1010000];
int n, m, s, t;
long long d;
bool visit[1010000];
int depth[1010000];
long long v[1010000];
void dfs(int pos, int f, long long val) {
  depth[pos] = depth[f] + 1;
  visit[pos] = 1;
  v[pos] = val;
  for (auto p : g[pos])
    if (p.first != f) {
      if (!visit[p.first])
        dfs(p.first, pos, val ^ p.second);
      else
        insert(val ^ p.second ^ v[p.first]);
    }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    scanf("%d%d%lld", &s, &t, &d);
    g[s].push_back({t, d});
    g[t].push_back({s, d});
  }
  dfs(1, 1, 0);
  long long ans = getans(v[n]);
  cout << ans;
  return ~~(0 ^ 0 ^ 0);
}
