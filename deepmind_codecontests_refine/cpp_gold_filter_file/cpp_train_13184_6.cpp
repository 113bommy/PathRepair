#include <bits/stdc++.h>
using namespace std;
long long int n, m, cost[200100];
set<pair<long long int, long long int> > D;
vector<long long int> G[200100];
map<pair<long long int, long long int>, long long int> M;
long long int Ans[200100];
bool used[200100];
void dfs(long long int cur) {
  used[cur] = 1;
  for (long long int to : G[cur]) {
    if (!used[to]) {
      long long int val = M[make_pair(cur, to)];
      if (Ans[to] > val * 2 + Ans[cur]) {
        D.erase(make_pair(Ans[to], to));
        Ans[to] = val * 2 + Ans[cur];
        D.insert(make_pair(Ans[to], to));
      }
    }
  }
  while (D.size() != 0) {
    D.erase(D.begin());
    auto next = D.begin();
    if (!used[next->second]) {
      dfs(next->second);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  while (m != 0) {
    long long int x, y, z;
    cin >> x >> y >> z;
    G[x].push_back(y);
    G[y].push_back(x);
    M[make_pair(x, y)] = z;
    M[make_pair(y, x)] = z;
    m--;
  }
  for (long long int i = 1; i <= n; i++) {
    cin >> cost[i];
    Ans[i] = cost[i];
    D.insert(make_pair(cost[i], i));
  }
  auto st = D.begin();
  dfs(st->second);
  for (long long int i = 1; i <= n; i++) {
    cout << Ans[i] << ' ';
  }
  return 0;
}
