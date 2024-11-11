#include <bits/stdc++.h>
using namespace std;
const int MX = 200005;
long long N, M;
vector<vector<int> > G(MX);
bool exist = true;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
vector<pair<long long, long long> > ans(40);
int fix(int d) {
  if (d == 0) return 2;
  if (d == 1) return 3;
  if (d == 2) return 0;
  if (d == 3) return 1;
  if (d > 3) return d;
}
void dfs(long long node, long long par, long long d, int last) {
  if (G[node].size() > 4) exist = false;
  int j = -1;
  if (par != -1) {
    ans[node].first = ans[par].first + d * dx[last];
    ans[node].second = ans[par].second + d * dy[last];
  }
  int f = fix(last);
  for (int i = 0; i < (int)G[node].size(); i++) {
    int ch = G[node][i];
    if (ch == par) continue;
    j++;
    if (j == f) j++;
    dfs(ch, node, d / 2, j);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  ans[1] = make_pair(0, 0);
  dfs(1, -1, 1e18, 5);
  if (!exist)
    cout << "NO\n";
  else {
    cout << "YES\n";
    for (int i = 1; i <= N; i++)
      cout << ans[i].first << " " << ans[i].second << "\n";
  }
  return 0;
}
