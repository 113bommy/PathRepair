#include <bits/stdc++.h>
using namespace std;
long n, m, a, b, c;
vector<pair<long, long> > g[220000];
long cap[220000];
map<pair<long, long>, long> mapp;
set<pair<long, long> > done;
long ans[220000];
void solve(long v) {
  for (int i = 0; i < g[v].size(); i++) {
    long q = g[v][i].first;
    long val = g[v][i].second;
    if (done.find(make_pair(v, q)) != done.end()) continue;
    done.insert(make_pair(v, q));
    done.insert(make_pair(q, v));
    ans[mapp[make_pair(v, q)]] = 1;
    cap[q] -= val;
    if (cap[q] == 0 && q < n) solve(q);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b >> c;
    mapp[make_pair(b, a)] = i;
    g[a].push_back(make_pair(b, c));
    g[b].push_back(make_pair(a, c));
    cap[a] += c;
    cap[b] += c;
  }
  for (int i = 1; i <= n; i++) cap[i] /= 2;
  cap[n] = 0;
  cap[1] = 0;
  solve(1);
  for (int i = 1; i <= m; i++) cout << ans[i] << endl;
  cin.get();
  cin.get();
  return 0;
}
