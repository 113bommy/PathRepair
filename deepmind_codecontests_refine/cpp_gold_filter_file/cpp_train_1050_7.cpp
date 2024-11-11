#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 123;
vector<pair<int, int> > nen;
pair<int, int> a[N];
struct node {
  int mx1, mx2, sz, ed;
} lt[2 * N];
int par[2 * N], n, res[2 * N], cnt, vt, ok[6];
int get(int u) {
  if (u == par[u]) return u;
  return par[u] = get(par[u]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
    nen.push_back(pair<int, int>(a[i].first, i));
    nen.push_back(pair<int, int>(a[i].second, i));
  }
  nen.push_back(pair<int, int>(-1, -1));
  sort(nen.begin(), nen.end());
  cnt = 0;
  for (int i = 1; i < nen.size(); ++i) {
    if (nen[i].first != nen[i - 1].first) ++cnt, res[cnt] = nen[i].first;
    if (a[nen[i].second].first == nen[i].first) a[nen[i].second].first = cnt;
    if (a[nen[i].second].second == nen[i].first) a[nen[i].second].second = cnt;
  }
  for (int i = 1; i <= cnt; ++i) par[i] = i, lt[i].mx1 = i, lt[i].sz = 1;
  int u, v;
  for (int i = 1; i <= n; ++i) {
    u = get(a[i].first);
    v = get(a[i].second);
    if (u == v) {
      lt[u].ed += 1;
      if (lt[u].sz < lt[u].ed) {
        cout << -1;
        return 0;
      }
      continue;
    }
    par[v] = u;
    lt[u].sz += lt[v].sz;
    lt[u].ed += lt[v].ed + 1;
    if (lt[u].sz < lt[u].ed) {
      cout << -1;
      return 0;
    }
    ok[1] = lt[u].mx1;
    ok[2] = lt[u].mx2;
    ok[3] = lt[v].mx1;
    ok[4] = lt[v].mx2;
    sort(ok + 1, ok + 5);
    lt[u].mx1 = ok[4];
    lt[u].mx2 = ok[3];
  }
  for (int i = 1; i <= cnt; ++i) {
    if (i == get(i)) {
      if (lt[i].ed == lt[i].sz - 1)
        vt = max(vt, lt[i].mx2);
      else
        vt = max(vt, lt[i].mx1);
    }
  }
  cout << res[vt];
  return 0;
}
