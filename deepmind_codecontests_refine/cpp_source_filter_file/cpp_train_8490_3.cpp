#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;
long long dis[MAX];
int a[MAX], ans[MAX];
int pos[MAX];
vector<pair<int, int> > adj[MAX];
void dfs(int x, int idx, int d) {
  pos[idx] = x;
  dis[idx] = d;
  int len = lower_bound(dis, dis + idx + 1, d - a[x]) - dis - 1;
  ans[pos[len]]--;
  ans[x]++;
  for (int i = 0; i < ((int)(adj[x]).size()); i += 1) {
    dfs(adj[x][i].first, idx + 1, d + adj[x][i].second);
    ans[x] += ans[adj[x][i].first];
  }
}
int main(int argc, char* argv[]) {
  if (argc == 2 or argc == 3) freopen(argv[1], "r", stdin);
  if (argc == 3) freopen(argv[2], "w", stdout);
  ios::sync_with_stdio(false);
  int n, p, w;
  cin >> n;
  for (int i = 1; i < n + 1; i += 1) {
    cin >> a[i];
  }
  for (int i = 2; i < n + 1; i += 1) {
    cin >> p >> w;
    adj[p].push_back(make_pair(i, w));
  }
  dis[0] = -1;
  dfs(1, 1, 0);
  for (int i = 1; i < n + 1; i += 1)
    if (i == 1)
      cout << ans[i] - 1;
    else
      cout << ' ' << ans[i] - 1;
  cout << endl;
  return 0;
}
