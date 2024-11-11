#include <bits/stdc++.h>
using namespace std;
struct Update {
  int type, c, h;
};
const int NN = 4005;
int dp[NN][NN];
struct Knapsack {
  int cur = 0;
  Knapsack() {
    cur = 0;
    memset(dp[0], 0, sizeof dp[0]);
  }
  void addUpdate(Update u) {
    for (int i = 0; i < u.c; i++) dp[cur + 1][i] = dp[cur][i];
    for (int i = u.c; i < NN; i++)
      dp[cur + 1][i] = max(dp[cur][i], dp[cur][i - u.c] + u.h);
    cur++;
  }
  void undoLastUpdate() { cur--; }
  int bestProfitWith(int budget) { return dp[cur][budget]; }
};
struct QueueUndoTrick {
  vector<Update> updates;
  Knapsack knapsack;
  int cnt0 = 0;
  QueueUndoTrick() {}
  void pushUpdate(const Update &up) {
    knapsack.addUpdate(up);
    updates.push_back(up);
    if (up.type == 0) cnt0++;
  }
  void popUpdate() {
    if (updates.back().type == 0) cnt0--;
    updates.pop_back();
    knapsack.undoLastUpdate();
  }
  void update(int c, int h) { pushUpdate({1, c, h}); }
  int query(int x) { return knapsack.bestProfitWith(x); }
  void undoFront() {
    if (cnt0 == 0) {
      vector<Update> temp;
      for (Update &up : updates) temp.push_back(up), popUpdate();
      reverse(temp.begin(), temp.end());
      for (Update &up : temp) up.type = 0, pushUpdate(up);
    }
    if (updates.back().type == 1) {
      vector<Update> temp[2];
      do {
        temp[updates.back().type].push_back(updates.back());
        popUpdate();
      } while (cnt0 > 0 && temp[0].size() != temp[1].size());
      reverse(temp[0].begin(), temp[0].end());
      reverse(temp[1].begin(), temp[1].end());
      for (Update up : temp[1]) pushUpdate(up);
      for (Update up : temp[0]) pushUpdate(up);
    }
    assert(updates.back().type == 0);
    popUpdate();
  }
};
const int N = 2e4 + 5;
int h[N], c[N], ans[N];
vector<int> st[N], en[N];
vector<pair<int, int>> qq[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, p;
  cin >> n >> p;
  for (int i = 1; i <= n; i++) {
    cin >> c[i] >> h[i];
    int t;
    cin >> t;
    st[t].push_back(i);
    en[t + p].push_back(i);
  }
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int a, b;
    cin >> a >> b;
    qq[a].push_back({b, i});
  }
  QueueUndoTrick solver;
  for (int i = 0; i < N; i++) {
    for (int idx : en[i]) solver.undoFront();
    for (int idx : st[i]) solver.update(c[idx], h[idx]);
    for (auto pr : qq[i]) ans[pr.second] = solver.query(pr.first);
  }
  for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
}
