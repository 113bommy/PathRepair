#include <bits/stdc++.h>
using namespace std;
const int MAXN = 6e5 + 5;
const int MOD = 1e9 + 7;
int N, sz[MAXN];
vector<pair<int, int> > G[MAXN];
long long A, B;
int dfs0(int cur, int par) {
  sz[cur] = 1;
  for (auto nxt : G[cur])
    if (nxt.first != par) sz[cur] += dfs0(nxt.first, cur);
  return sz[cur];
}
void dfs(int cur, int par) {
  for (auto nxt : G[cur])
    if (nxt.first != par) {
      if (sz[nxt.first] % 2) A += nxt.second;
      B += nxt.second * min(sz[nxt.first], N - sz[nxt.first]);
      dfs(nxt.first, cur);
    }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> N;
    N <<= 1;
    A = B = 0;
    for (int i = 1; i <= N; i++) G[i].clear();
    for (int i = 1; i < N; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      G[a].push_back(pair<int, int>(b, c));
      G[b].push_back(pair<int, int>(a, c));
    }
    dfs0(1, 0);
    dfs(1, 0);
    cout << A << " " << B << "\n";
  }
}
