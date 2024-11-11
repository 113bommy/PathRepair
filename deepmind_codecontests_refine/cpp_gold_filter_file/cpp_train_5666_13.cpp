#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n, m, p;
pair<int, int> v[100002];
pair<int, int> vx[100002];
int pz[100002];
bool cmp(int a, int b) { return vx[a].first < vx[b].first; }
int wh[100002];
bool chk(int d) {
  int rem = 0;
  int oo = 0;
  int q = n;
  set<pair<int, int> > cost;
  int tc = 0;
  for (int i = m; i >= 1; --i) {
    while (q >= 1 && vx[pz[q]].first >= v[i].first)
      cost.insert({vx[pz[q]].second, pz[q]}), --q;
    if (rem)
      --rem, wh[v[i].second] = oo;
    else {
      if (cost.empty()) return 0;
      pair<int, int> it = *cost.begin();
      tc += it.first;
      oo = it.second;
      rem = d - 1;
      wh[v[i].second] = oo;
      cost.erase(it);
    }
    if (tc > p) return 0;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> p;
  for (int i = 1; i <= m; ++i) cin >> v[i].first, v[i].second = i;
  sort(v + 1, v + m + 1);
  for (int i = 1; i <= n; ++i) cin >> vx[i].first;
  for (int i = 1; i <= n; ++i) cin >> vx[i].second, pz[i] = i;
  sort(pz + 1, pz + n + 1, cmp);
  if (v[m].first > vx[pz[n]].first) {
    cout << "NO";
    return 0;
  }
  int st = 1;
  int dr = m;
  int ans = m + 1;
  while (st <= dr) {
    int mid = (st + dr) / 2;
    if (chk(mid))
      ans = mid, dr = mid - 1;
    else
      st = mid + 1;
  }
  if (ans == m + 1) {
    cout << "NO";
    return 0;
  }
  chk(ans);
  cout << "YES\n";
  for (int i = 1; i <= m; ++i) cout << wh[i] << " ";
  return 0;
}
