#include <bits/stdc++.h>
using namespace std;
const int64_t inf = 1e18 + 88;
vector<int> c;
vector<vector<int>> g;
vector<vector<vector<int>>> best;
vector<vector<int64_t>> dp;
void DFS(int v, int p = 0) {
  if (g[v].size() == 1 && v != 0) {
    dp[v][0] = c[v];
    return;
  }
  int64_t sum = 0;
  for (int to : g[v]) {
    if (to == p) {
      continue;
    }
    DFS(to, v);
    sum += dp[to][0];
  }
  dp[v][0] = sum;
  best[v][0].push_back(v);
  dp[v][1] = inf;
  for (int to : g[v]) {
    if (to == p) {
      continue;
    }
    int64_t cost = sum - dp[to][0] + dp[to][1];
    if (cost + c[v] < dp[v][0]) {
      dp[v][0] = cost + c[v];
      best[v][0].clear();
    }
    if (cost + c[v] <= dp[v][0]) {
      best[v][0].push_back(to);
    }
    if (cost < dp[v][1]) {
      dp[v][1] = cost;
      best[v][1].clear();
    }
    if (cost <= dp[v][1]) {
      best[v][1].push_back(to);
    }
  }
}
vector<int> ans;
void Answer(int v, bool can0 = true, bool can1 = false, int p = 0) {
  if (can0 && (best[v][0].size() != 1 || best[v][0][0] != v)) {
    ans.push_back(v);
  }
  int it0 = (!best[v][0].empty() && best[v][0][0] == v ? 1 : 0);
  int it1 = 0;
  for (int to : g[v]) {
    if (to == p) {
      continue;
    }
    bool curcan0 = (can0 && (best[v][0].size() != 1 || best[v][0][0] != to)) ||
                   (can1 && (best[v][1].size() != 1 || best[v][1][0] != to));
    bool curcan1 = (can0 && it0 < best[v][0].size() && best[v][0][it0] == to) ||
                   (can1 && it1 < best[v][1].size() && best[v][1][it1] == to);
    Answer(to, curcan0, curcan1, v);
    it0 += (it0 < best[v][0].size() && best[v][0][it0] == to ? 1 : 0);
    it1 += (it1 < best[v][0].size() && best[v][1][it1] == to ? 1 : 0);
  }
}
void Solve(istream& in, ostream& out) {
  int n;
  in >> n;
  c.resize(n);
  for (int& item : c) {
    in >> item;
  }
  g.assign(n, vector<int>());
  for (int i = 1; i < n; ++i) {
    int a, b;
    in >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dp.assign(n, vector<int64_t>(2));
  best.assign(n, vector<vector<int>>(2));
  DFS(0);
  Answer(0);
  sort(ans.begin(), ans.end());
  out << dp[0][0] << ' ' << ans.size() << '\n';
  for (int item : ans) {
    out << item + 1 << ' ';
  }
  out << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ifstream in("input.txt");
  ofstream out("output.txt");
  Solve(cin, cout);
  return 0;
}
