#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N + 1);
  vector<int> PC(N + 1, 0);
  for (int i = 0; i < N + M - 1; i++) {
    int a, b;
    cin >> a >> b;
    G[a].emplace_back(b);
    PC[b]++;
  }
  vector<int> P(N + 1);
  queue<int> que;
  for (int i = 1; i < N + 1; i++) {
    if (PC[i] == 0) {
      que.push(i);
      P[i] = 0;
      break;
    }
  }
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int v : G[u]) {
      if (PC[v] > 1) {
        PC[v]--;
      } else {
        P[v] = u;
        que.push(v);
      }
    }
  }
  for (int i = 1; i < N + 1; i++) {
    cout << P[i] << '\n';
  }
  return 0;
}
