#include <bits/stdc++.h>
using namespace std;
typedef struct graph {
  int act;
  int Min;
  int Max;
} graph;
int N;
graph Graph[55][55];
int Ans;
int Val[10];
void dfs(int x, int y, int z, int s) {
  if (x == N) {
    Ans = max(Ans, s);
    return;
  }
  if (y > N) {
    if (!z) {
      dfs(x + 1, x + 2, Val[x + 1], s);
    }
    return;
  }
  for (int n = Graph[x][y].Min; n <= min(z, Graph[x][y].Max); ++n) {
    Val[y] += n;
    dfs(x, y + 1, z - n, s + (n ? Graph[x][y].act : 0) + n * n);
    Val[y] -= n;
  }
}
int main() {
  cin >> N;
  int M = (N * (N - 1)) / 2;
  int p, q, r, s, t;
  for (int n = 0; n < M; ++n) {
    scanf("%d%d%d%d%d", &p, &q, &r, &s, &t);
    Graph[p][q].act = t;
    Graph[p][q].Min = r;
    Graph[p][q].Max = s;
  }
  for (int i = 1; i < 30; ++i) {
    Ans = -1;
    dfs(1, 2, i, 0);
    if (Ans >= 0) {
      cout << i << " " << Ans << endl;
      return 0;
    }
  }
  cout << -1 << " " << -1 << endl;
  return 0;
}
