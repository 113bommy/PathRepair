#include <bits/stdc++.h>
using namespace std;
const int N = 3010;
const int M = 5010;
const int INF = 1e9;
struct EDGE {
  int u, v, d, nex;
  EDGE() {}
  EDGE(int _u, int _v, int _d, int _nex) {
    u = _u;
    v = _v;
    d = _d;
    nex = _nex;
  }
} e[M];
int len, fir[N];
int n, m;
int D1[N][N], MAX1[N][4], P1[N][4];
int D2[N][N], MAX2[N][4], P2[N][4];
queue<int> q;
void addedge(int u, int v, int d) {
  e[++len] = EDGE(u, v, d, fir[u]);
  fir[u] = len;
}
void bfs(int st) {
  while (!q.empty()) q.pop();
  q.push(st);
  D1[st][st] = 0;
  while (!q.empty()) {
    int u = q.front();
    for (int k = fir[u]; k != -1; k = e[k].nex) {
      int v = e[k].v;
      if (D1[st][v] == INF) {
        D1[st][v] = D1[st][u] + e[k].d;
        q.push(v);
      }
    }
    q.pop();
  }
}
void read_graph() {
  len = 0;
  memset(fir, -1, sizeof fir);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    addedge(u, v, 1);
  }
}
void solve() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) D1[i][j] = D2[i][j] = INF;
  for (int i = 1; i <= n; i++) bfs(i);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) D2[j][i] = D1[i][j];
  for (int i = 1; i <= n; i++) {
    MAX1[i][1] = MAX1[i][2] = MAX1[i][3] = 0;
    P1[i][1] = P1[i][2] = P1[i][3] = 0;
    for (int j = 1; j <= n; j++) {
      if (D1[i][j] == INF) continue;
      if (D1[i][j] > MAX1[i][1]) {
        MAX1[i][3] = MAX1[i][2];
        P1[i][3] = P1[i][2];
        MAX1[i][2] = MAX1[i][1];
        P1[i][2] = P1[i][1];
        MAX1[i][1] = D1[i][j];
        P1[i][1] = j;
      } else if (D1[i][j] > MAX1[i][2]) {
        MAX1[i][3] = MAX1[i][2];
        P1[i][3] = P1[i][2];
        MAX1[i][2] = D1[i][j];
        P1[i][2] = j;
      } else if (D1[i][j] > MAX1[i][3]) {
        MAX1[i][3] = D1[i][j];
        P1[i][3] = j;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    MAX2[i][1] = MAX2[i][2] = MAX2[i][3] = 0;
    P2[i][1] = P2[i][2] = P2[i][3] = 0;
    for (int j = 1; j <= n; j++) {
      if (D2[i][j] == INF) continue;
      if (D2[i][j] > MAX2[i][1]) {
        MAX2[i][3] = MAX2[i][2];
        P2[i][3] = P2[i][2];
        MAX2[i][2] = MAX2[i][1];
        P2[i][2] = P2[i][1];
        MAX2[i][1] = D2[i][j];
        P2[i][1] = j;
      } else if (D2[i][j] > MAX2[i][2]) {
        MAX2[i][3] = MAX2[i][2];
        P2[i][3] = P2[i][2];
        MAX2[i][2] = D2[i][j];
        P2[i][2] = j;
      } else if (D2[i][j] > MAX2[i][3]) {
        MAX2[i][3] = D2[i][j];
        P2[i][3] = j;
      }
    }
  }
  int TA, TB, TC, TD;
  int ans = 0;
  for (int b = 1; b <= n; b++)
    for (int c = 1; c <= n; c++)
      for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++) {
          int a = P2[b][i];
          int d = P1[c][j];
          if (D1[b][c] == INF) continue;
          if (a == 0 || b == 0) continue;
          if (a == b || a == c || a == d || b == c || b == d || c == d)
            continue;
          int t = D1[a][b] + D1[b][c] + D1[c][d];
          if (t > ans) ans = t, TA = a, TB = b, TC = c, TD = d;
        }
  printf("%d %d %d %d\n", TA, TB, TC, TD);
}
int main() {
  read_graph();
  solve();
  return 0;
}
