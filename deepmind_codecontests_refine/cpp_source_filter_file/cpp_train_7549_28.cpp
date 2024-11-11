#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5;
const long long M = 20;
const long long SQ = 320;
const long long INF = 1e16;
const long long MOD = 1e9 + 7;
int n, m;
int l[N], r[N];
int f[N];
vector<int> v[N], ts;
map<pair<int, int>, int> ma;
void dfs(int x) {
  f[x] = 1;
  for (int i = 0; i < v[x].size(); i++)
    if (!f[v[x][i]]) dfs(v[x][i]);
  ts.push_back(x);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i];
    l[i]--;
    r[i]--;
    v[l[i]].push_back(r[i]);
  }
  for (int i = 0; i < n; i++)
    if (!f[i]) dfs(i);
  reverse(ts.begin(), ts.end());
  for (int i = 0; i < n - 1; i++) ma[make_pair(ts[i], ts[i + 1])] = 1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (ma.count(make_pair(l[i], r[i])) > 0) ans++;
    if (ans == n - 1) {
      cout << i + 1 << '\n';
      return 0;
    }
  }
  cout << "-1\n";
  return 0;
}
