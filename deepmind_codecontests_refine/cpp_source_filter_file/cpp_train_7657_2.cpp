#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 10;
int N, M, ans, root, color[maxN], dsu[maxN], D[2][maxN], par[maxN];
pair<int, int> G[maxN];
vector<int> F[maxN];
int found(int x) { return dsu[x] < 0 ? x : found(dsu[x]); }
void combine(int x, int y) {
  int i = found(x), j = found(y);
  if (i == j) return;
  if (dsu[i] > dsu[j]) swap(i, j);
  dsu[i] += dsu[j];
  dsu[j] = i;
}
void BFS(int k, int x) {
  queue<int> que;
  memset(par, 0, sizeof(par));
  que.push(x);
  par[x] = -1;
  while (!que.empty()) {
    int x = que.front();
    que.pop();
    for (int i = 0; i < F[x].size(); i++) {
      int y = F[x][i];
      if (par[y] != 0) continue;
      par[y] = x;
      D[k][y] = D[k][x] + 1;
      que.push(y);
    }
  }
}
int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> color[i];
  memset(dsu, -1, sizeof(dsu));
  for (int i = 1, x, y; i < N; i++) {
    cin >> x >> y;
    if (color[x] == color[y])
      combine(x, y);
    else
      G[++M] = pair<int, int>(x, y);
  }
  for (int i = 1; i <= M; i++) {
    int x = found(G[i].first), y = found(G[i].second);
    F[x].push_back(y);
    F[y].push_back(x);
  }
  root = 1;
  BFS(0, root);
  for (int i = 1; i <= N; i++)
    if (D[0][i] > D[0][root]) root = i;
  BFS(1, root);
  for (int i = 1; i <= N; i++)
    if (D[1][i] > D[1][root]) root = i;
  cout << (D[1][root] + 1) / 2;
}
