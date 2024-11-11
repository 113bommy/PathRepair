#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
int N, L;
ll S;
vector<int> path[100010];
ll upcost[100010][20];
int upto[100010][20];
int ans = 0;
int dfs(int v) {
  int up = 0;
  for (int sv : path[v]) up = max(up, dfs(sv));
  if (up > 0) {
    ans += path[v].size() - 1;
    return up - 1;
  } else {
    ans += path[v].size();
    int ret = 0;
    ll cost = 0;
    while (v > 0) {
      int k;
      for (k = 19; k >= 0; --k) {
        if (upcost[v][k] + cost <= S) break;
      }
      if (k < 0) break;
      ret += (1 << k);
      cost += upcost[v][k];
      v = upto[v][k];
    }
    return min(L, ret) - 1;
  }
}
int main() {
  cin >> N >> L >> S;
  for (int i = 0; i < N; ++i) {
    cin >> upcost[i][0];
    if (upcost[i][0] > S) {
      cout << -1 << endl;
      return 0;
    }
  }
  upto[0][0] = -1;
  for (int i = 1; i < N; ++i) {
    cin >> upto[i][0];
    path[--upto[i][0]].push_back(i);
  }
  for (int k = 1; k < 20; ++k) {
    for (int i = 0; i < N; ++i) {
      if (upto[i][k - 1] >= 0) {
        upto[i][k] = upto[upto[i][k - 1]][k - 1];
        upcost[i][k] = upcost[i][k - 1] + upcost[upto[i][k - 1]][k - 1];
      } else {
        upto[i][k] = -1;
        upcost[i][k] = INF;
      }
    }
  }
  dfs(0);
  cout << ans + 1 << endl;
  return 0;
}
