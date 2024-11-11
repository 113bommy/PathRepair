#include <bits/stdc++.h>
using namespace std;
long long mx = 0LL;
vector<pair<int, long long> > adj[100005];
void dfs(int p, int u, long long cnt) {
  if (cnt > mx) mx = cnt;
  for (int i = 0; i < adj[u].size(); i++) {
    if (adj[u][i].first != p) dfs(u, adj[u][i].first, cnt + adj[u][i].second);
  }
}
int main() {
  int n;
  int sum = 0LL;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    long long d;
    cin >> x >> y >> d;
    adj[x].push_back(make_pair(y, d));
    adj[y].push_back(make_pair(x, d));
    sum += d;
  }
  sum = sum * 2LL;
  dfs(0, 1, 0);
  sum -= mx;
  cout << sum << endl;
  return 0;
}
