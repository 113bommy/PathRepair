#include <bits/stdc++.h>
using namespace std;
int N;
vector<vector<pair<int, int>>> G;
vector<int> V;
vector<int> ans;
void dfs(int v, int dist) {
  V.at(v) = 1;
  ans.at(v) = dist % 2;
  if (accumulate(V.begin(), V.end(), 0L) == N) return;
  for (auto g : G.at(v)) {
    if (V.at(g.first)) continue;
    dfs(g.first, dist + g.second);
  }
}
int main() {
  cin >> N;
  G.resize(N);
  V.resize(N);
  ans.resize(N);
  for (int a, b, c; cin >> a >> b >> c;) {
    G.at(--a).push_back({--b, c % 2});
    G.at(b).push_back({a, c % 2});
  }
  dfs(0, 0);
  for (auto a : ans) cout << a << "\n";
}
