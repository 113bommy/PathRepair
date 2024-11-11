#include <bits/stdc++.h>
using namespace std;
int N, M;
int cal(int i, int j) { return (i - 1) * M + j; }
int f[1000010];
int findf(int x) { return x == f[x] ? f[x] : f[x] = findf(f[x]); }
int in[1000010];
vector<int> e[1000010];
vector<int> bin[1000010];
int ans[1000010];
vector<pair<int, int>> sub;
queue<pair<int, int>> q;
void topo() {
  for (int i = 1; i <= N; i++) {
    if (findf(i) == i && !in[i]) q.push({i, 1});
  }
  while (!q.empty()) {
    int x = q.front().first;
    ans[x] = q.front().second;
    q.pop();
    for (int i = 0; i < e[x].size(); i++) {
      int to = e[x][i];
      --in[to];
      if (!in[to]) q.push({to, ans[x] + 1});
    }
  }
  for (int i = 1; i <= N * M; i++)
    if (!ans[i]) ans[i] = ans[findf(i)];
}
int main() {
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      int val;
      scanf("%d", &val);
      bin[i].push_back(val);
      f[cal(i, j)] = cal(i, j);
    }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      sub.push_back({bin[i][j - 1], cal(i, j)});
    }
    sort(sub.begin(), sub.end());
    for (int j = 1; j < M; j++) {
      if (sub[j].first == sub[j - 1].first) {
        int u = findf(sub[j].second), v = findf(sub[j - 1].second);
        f[u] = v;
      } else {
        int u = findf(sub[j].second), v = findf(sub[j - 1].second);
        e[v].push_back(u);
      }
    }
    sub.clear();
  }
  for (int j = 1; j <= M; j++) {
    for (int i = 1; i <= N; i++) {
      sub.push_back({bin[i][j - 1], cal(i, j)});
    }
    sort(sub.begin(), sub.end());
    for (int i = 1; i < N; i++) {
      if (sub[i].first == sub[i - 1].first) {
        int u = findf(sub[i].second), v = findf(sub[i - 1].second);
        f[u] = v;
      } else {
        int u = findf(sub[i].second), v = findf(sub[i - 1].second);
        e[v].push_back(u);
      }
    }
    sub.clear();
  }
  for (int i = 1; i <= N * M; i++) {
    if (i != findf(i)) {
      int u = findf(i);
      for (int j = 0; j < e[i].size(); j++) e[u].push_back(e[i][j]);
      e[i].clear();
    }
  }
  for (int i = 1; i <= N * M; i++) {
    for (int j = 0; j < e[i].size(); j++) {
      e[i][j] = findf(e[i][j]);
      ++in[e[i][j]];
    }
  }
  topo();
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (j > 1) printf(" ");
      printf("%d", ans[(i - 1) * M + j]);
    }
    puts("");
  }
  return 0;
}
