#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);
  const int LIM = 600;
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> x(M), y(M);
  vector<vector<int> > g(N);
  for (int i = 0; i < M; i++) {
    cin >> x[i] >> y[i];
    g[--x[i]].push_back(i);
    g[--y[i]].push_back(i);
  }
  vector<int> deg(N);
  for (int i = 0; i < N; i++) deg[i] = g[i].size();
  vector<bool> del(N, false);
  vector<bool> live(M, true);
  int alive = N;
  vector<int> ans(M);
  auto bfs = [&](int v) {
    if (deg[v] >= K || del[v]) return;
    queue<int> rem;
    rem.push(v);
    del[v] = true;
    alive--;
    while (!rem.empty()) {
      int nxt = rem.front();
      rem.pop();
      for (int e : g[v]) {
        if (!live[e]) continue;
        live[e] = false;
        int nbr = x[e] + y[e] - v;
        deg[nbr]--;
        if (!del[nbr] && deg[nbr] < K) {
          del[nbr] = true;
          alive--;
          rem.push(nbr);
        }
      }
    }
  };
  for (int i = 0; i < N; i++) {
    bfs(i);
  }
  for (int i = M - 1; i >= 0; i--) {
    ans[i] = alive;
    if (live[i]) {
      live[i] = false;
      deg[x[i]]--;
      deg[y[i]]--;
      bfs(x[i]);
      bfs(y[i]);
    }
  }
  for (int i = 0; i < M; i++) cout << ans[i] << "\n";
  return 0;
}
