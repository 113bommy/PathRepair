#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
vector<int> g[N];
int a[N];
int cnt[N];
int n, k;
int val;
int f[N];
int without[N];
void mmax(int &a, int b) { a = max(a, b); }
void mmin(int &a, int b) { a = min(a, b); }
void dfs1(int v, int par = -1) {
  cnt[v] = 1;
  for (int to : g[v]) {
    if (to == par) continue;
    dfs1(to, v);
    cnt[v] += cnt[to];
  }
  if (a[v] < val) return;
  int mx = -1;
  for (int to : g[v]) {
    if (to == par) continue;
    if (f[to] == -1)
      without[v] += cnt[to];
    else
      mmax(mx, f[to]);
  }
  if (mx == -1)
    f[v] = -1;
  else
    f[v] = 1 + without[v] + mx;
}
int ans;
void dfs2(int v, int f_up, int par = -1) {
  if (a[v] < val) {
    for (int to : g[v]) {
      if (to == par) continue;
      dfs2(to, 0, v);
    }
    return;
  }
  if (f_up == -1 && f[v] == -1) {
    ans = n;
    return;
  }
  int w = without[v];
  if (f_up == -1) w += n - cnt[v];
  map<int, int> mp;
  mp[f_up]++;
  for (int to : g[v]) {
    if (to == par) continue;
    mp[f[to]]++;
  }
  mp[-1] += 2;
  for (int to : g[v]) {
    if (to == par) continue;
    if (f[to] == -1)
      w -= cnt[to];
    else {
      mp[f[to]]--;
      if (!mp[f[to]]) mp.erase(f[to]);
    }
    int mx = (*mp.rbegin()).first;
    if (mx == -1)
      dfs2(to, -1, v);
    else
      dfs2(to, 1 + mx + w, v);
    if (f[to] == -1)
      w += cnt[to];
    else
      mp[f[to]]++;
  }
  mmax(ans, 1 + (*mp.rbegin()).first + w);
}
void clear_dp() {
  ans = 0;
  fill(cnt, cnt + N, 0);
  fill(f, f + N, 0);
  fill(without, without + N, 0);
}
bool able(int l) {
  clear_dp();
  val = l;
  dfs1(1);
  dfs2(1, 0);
  return ans >= k;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int l = 0, r = 2e6;
  while (l < r) {
    int mid = l + r >> 1;
    if (able(mid))
      l = mid;
    else
      r = mid - 1;
    if (l == r - 1) {
      if (able(r))
        l = r;
      else
        r = l;
    }
  }
  cout << r;
}
