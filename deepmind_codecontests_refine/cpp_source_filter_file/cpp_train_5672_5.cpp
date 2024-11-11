#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<pair<long long int, long long int> > a[100010];
long long int ds[100010], d[100010];
vector<pair<long long int, long long int> > st;
long long int ans[100010];
long long int dfs(long long int x, long long int p) {
  long long int ret = 0;
  for (int i = 0; i < a[x].size(); i++)
    if (a[x][i].first != p)
      ret = max(ret, dfs(a[x][i].first, x) + a[x][i].second);
  ds[x] = ret;
  return ret;
}
void dfs2(long long int x, long long int p, long long int s) {
  long long int best = -1, best2 = -1;
  long long int v = -1, v2 = -1;
  for (int i = 0; i < a[x].size(); i++) {
    if (a[x][i].first == p) continue;
    long long int dd = ds[a[x][i].first] + a[x][i].second;
    if (dd >= best) {
      best2 = best, best = dd;
      v2 = v, v = a[x][i].first;
    } else if (dd > best2) {
      best2 = dd;
      v2 = a[x][i].first;
    }
  }
  if (s >= best) {
    best2 = best, best = s;
    v2 = v, v = -1;
  } else if (s > best2) {
    best2 = s;
    v2 = -1;
  }
  d[x] = best;
  for (int i = 0; i < a[x].size(); i++) {
    if (a[x][i].first == p) continue;
    if (a[x][i].first == v)
      dfs2(a[x][i].first, x, max(0LL, best2) + a[x][i].second);
    else
      dfs2(a[x][i].first, x, max(0LL, best) + a[x][i].second);
  }
}
long long int solve(long long int x, long long int p, long long int l) {
  st.push_back(make_pair(d[x], x));
  long long int idx =
      lower_bound(st.begin(), st.end(), make_pair(d[x] - l, -1LL)) - st.begin();
  if (idx) ans[st[idx - 1].second]--;
  ans[x] = 1;
  for (int i = 0; i < a[x].size(); i++)
    if (a[x][i].first != p) ans[x] += solve(a[x][i].first, x, l);
  st.pop_back();
  return ans[x];
}
int main() {
  long long int xx, yy, ww;
  cin >> n;
  memset((ds), (0), sizeof(ds));
  memset((d), (0), sizeof(d));
  for (int i = 0; i < n - 1; i++) {
    cin >> xx >> yy >> ww;
    xx--;
    yy--;
    a[xx].push_back(make_pair(yy, ww));
    a[yy].push_back(make_pair(xx, ww));
  }
  dfs(0, -1);
  dfs2(0, -1, -1);
  cin >> q;
  long long int root = 0;
  long long int mn = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (d[i] < mn) {
      mn = d[i];
      root = i;
    }
  }
  while (q--) {
    long long int l;
    cin >> l;
    solve(root, -1, l);
    long long int sol = -1;
    for (int i = 0; i < n; i++) sol = max(sol, ans[i]);
    cout << sol << "\n";
  }
  return 0;
}
