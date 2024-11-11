#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int mod = 1000000007;
int N;
vector<int> g[100001];
vector<int> time_in(100001);
vector<int> time_out(100001);
int cnt;
void dfs(int v) {
  cnt++;
  time_in[v] = cnt;
  for (int i : g[v]) {
    if (time_in[i] == 0) dfs(i);
  }
  cnt++;
  time_out[v] = cnt;
}
void slv() {
  cin >> N;
  if (N % 2) {
    cout << -1;
    return;
  }
  int x, y;
  for (int i = 1; i <= N - 1; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= N; i++) {
    if (g[i].size() == 1) {
      dfs(i);
      break;
    }
  }
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    int cur = time_out[i] - time_in[i] + 1;
    if (cur == 0) continue;
    if (cur % 4 == 0) {
      ans++;
    }
  }
  cout << (ans == 0 ? -1 : ans - 1);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  while (T--) slv();
  return 0;
}
