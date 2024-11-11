#include <bits/stdc++.h>
using namespace std;
int d[300005];
list<pair<int, int> > adjList[300005];
int par[300005];
int r[300005];
int gp(int x) {
  if (x == par[x]) return x;
  return par[x] = gp(par[x]);
}
bool join(int a, int b) {
  a = gp(a);
  b = gp(b);
  if (a == b) return 0;
  if (r[a] < r[b]) swap(a, b);
  if (r[a] == r[b]) r[a]++;
  par[b] = a;
  return 1;
}
vector<int> ans;
void dfs(int i, int p, int x) {
  for (auto v : adjList[i])
    if (v.first != p) dfs(v.first, i, v.second);
  if (d[i] & 1) ans.push_back(x), d[p] ^= 1;
  ;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int(n), (m);
  cin >> n >> m;
  int cnt[3] = {0};
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
    cnt[d[i] + 1]++;
  }
  if ((cnt[2] & 1) && (cnt[0] == 0)) {
    int k, c;
    for (int i = 0; i < m; i++) cin >> k >> c;
    cout << "-1\n";
    return 0;
  }
  int rem = 0;
  if (d[2] & 1) rem++;
  for (int i = 1; i <= n; i++)
    if (rem && d[i] == -1) d[i] = 1, rem--;
  for (int i = 1; i <= n; i++)
    if (d[i] == -1) d[i] = 0;
  for (int i = 1; i <= n; i++) par[i] = i, r[i] = 1;
  for (int i = 0; i < m; i++) {
    int(a), (b);
    cin >> a >> b;
    if (join(a, b)) {
      adjList[a].push_back({b, i + 1});
      adjList[b].push_back({a, i + 1});
    }
  }
  dfs(1, 0, -1);
  if (ans.size() && ans.back() == -1) ans.pop_back();
  cout << ans.size() << '\n';
  if (ans.size())
    if (ans.size())
      for (int i = 0; i <= ans.size() - 1; i++)
        cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  return 0;
}
