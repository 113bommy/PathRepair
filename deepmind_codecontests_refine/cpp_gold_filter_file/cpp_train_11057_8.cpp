#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f, mod = 1000000007;
const double pi = 3.1415926535897932, eps = 1e-6;
int n, T;
long long ans1, ans2, res;
vector<pair<int, int> > v[200005];
long long dfs(int x, int fa, int cst) {
  int cur = 1;
  for (int(i) = (0); (i) < (v[x].size()); (i)++) {
    int a = v[x][i].first, y = v[x][i].second;
    if (fa == a) continue;
    cur += dfs(a, x, y);
  }
  while (cur * 2 > res) res -= 2, cur -= 2;
  ans1 += (long long)cur * cst;
  return cur;
}
long long dfs2(int x, int fa, int cst) {
  int cur = 1;
  for (int(i) = (0); (i) < (v[x].size()); (i)++) {
    int a = v[x][i].first, y = v[x][i].second;
    if (fa == a) continue;
    int re = dfs2(a, x, y);
    if (re) ans2 += y;
    cur += re;
  }
  cur %= 2;
  return cur;
}
void solve() {
  for (int(i) = (1); (i) <= (2 * n); (i)++) v[i].clear();
  cin >> n;
  for (int(i) = (1); (i) <= (2 * n - 1); (i)++) {
    int t1, t2, t3;
    cin >> t1 >> t2 >> t3;
    v[t1].push_back(make_pair(t2, t3));
    v[t2].push_back(make_pair(t1, t3));
  }
  res = 2 * n;
  dfs(1, -1, 0);
  dfs2(1, -1, 0);
  cout << ans2 << ' ' << ans1 << '\n';
  ans1 = 0;
  ans2 = 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> T;
  while (T--) solve();
  return 0;
}
