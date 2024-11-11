#include <bits/stdc++.h>
using namespace std;
struct go {
  long long a, b;
};
const long long N = 1e5, inf = 2e9;
vector<long long> g[N];
pair<long long, long long> ch[N];
long long mn, mx;
void dfs(long long v, long long p) {
  long long cnt = 0;
  if (g[v].size() == 1) ch[v].second = 1;
  long long nw = 0, GG = 0;
  for (long long to : g[v]) {
    if (to != p) {
      dfs(to, v);
      if (g[to].size() == 1) ++cnt;
      GG++;
      if (ch[v].first && ch[to].first) nw = 1;
      if (ch[v].second && ch[to].second) nw = 1;
      if (ch[to].first) {
        ch[v].second = 1;
      }
      if (ch[to].second) {
        ch[v].first = 1;
      }
    }
  }
  if (nw) mn += GG - 1;
  mx -= max((cnt - 1), (long long)0);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (long long i = 0; i < N; ++i) ch[i] = {0, 0};
  long long n;
  cin >> n;
  for (long long i = 1; i < n; ++i) {
    long long u, v;
    cin >> u >> v;
    g[--u].push_back(--v);
    g[v].push_back(u);
  }
  long long st = 0;
  mn = 1, mx = n - 1;
  for (long long i = 0; i < n; ++i) {
    if (g[i].size() >= 2) {
      st = i;
    }
  }
  dfs(st, -1);
  cout << mn << " " << mx;
}
