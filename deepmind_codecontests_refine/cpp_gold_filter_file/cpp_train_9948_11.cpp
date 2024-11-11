#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
const int MAXN = 5e4 + 111;
int x[MAXN << 1], y[MAXN << 1];
vector<int> G[MAXN];
int team[MAXN];
bool col[MAXN * 20];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    --x[i], --y[i];
  }
  int cnt = 0, len;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &len);
    G[i].resize(len);
    for (int j = 0; j < len; ++j) {
      scanf("%d", &G[i][j]);
      cnt = max(cnt, G[i][j]);
      --G[i][j];
    }
  }
  srand(10007);
  while (1) {
    for (int i = 0; i < n; ++i) {
      team[i] = G[i][rand() % G[i].size()];
    }
    for (int i = 0; i < cnt; ++i) {
      col[i] = rand() & 1;
    }
    int tol = 0;
    for (int i = 0; i < m; ++i) {
      tol += col[team[x[i]]] != col[team[y[i]]];
    }
    if (tol * 2 >= m) {
      for (int i = 0; i < n; ++i) {
        printf("%d ", team[i] + 1);
      }
      putchar('\n');
      for (int i = 0; i < cnt; ++i) {
        printf("%d ", col[i] + 1);
      }
      putchar('\n');
      break;
    }
  }
  return 0;
}
