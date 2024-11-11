#include <bits/stdc++.h>
using namespace std;
int N, M;
char ch[60][60] = {"\0"};
struct bian_ {
  int to;
  int next;
  int dis;
} bian[60000] = {{0, 0, 0}};
int bp = 0;
int go[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int Ans = 2e9;
int Dist[5000][5000] = {{0}};
int nd[5000] = {0};
int Hash[5000] = {0};
int First[5000] = {0};
int W[5000] = {0};
void Add(int p, int q, int d) {
  bp++;
  bian[bp].to = q;
  bian[bp].next = First[p];
  bian[bp].dis = d;
  First[p] = bp;
  return;
}
void done(int st) {
  memset(Hash, 0, sizeof(Hash));
  memset(nd, 0, sizeof(nd));
  Dist[0][++nd[0]] = st;
  Hash[st] = 1;
  int ret = -1;
  for (int i = 0; nd[i] > 0; i++) {
    for (int p = 1; p <= nd[i]; p++) {
      int u = Dist[i][p];
      for (int x = First[u]; x != 0; x = bian[x].next) {
        int v = bian[x].to;
        if (bian[x].dis == 1 || Hash[v] == 1) continue;
        Dist[i][++nd[i]] = v;
        Hash[v] = 1;
        if (W[v] == 0) ret = max(ret, i);
      }
    }
    for (int p = 1; p <= nd[i]; p++) {
      int u = Dist[i][p];
      for (int x = First[u]; x != 0; x = bian[x].next) {
        int v = bian[x].to;
        if (bian[x].dis == 0 || Hash[v] == 1) continue;
        Dist[i + 1][++nd[i + 1]] = v;
        Hash[v] = 1;
        if (W[v] == 0) ret = i + 1;
      }
    }
  }
  Ans = min(Ans, ret);
  return;
}
int main() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) scanf("%s", ch[i] + 1);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      W[(((i)-1) * M + (j))] = ch[i][j] == 'W';
      int u = (((i)-1) * M + (j));
      for (int p = 0; p <= 3; p++) {
        int x = i + go[p][0], y = j + go[p][1];
        if (x < 1 || x > N || y < 1 || y > M) continue;
        int v = (((x)-1) * M + (y));
        Add(u, v, ch[i][j] != ch[x][y]);
        Add(v, u, ch[i][j] != ch[x][y]);
      }
    }
  for (int i = 1; i <= N * M; i++) done(i);
  cout << Ans + 1 << endl;
  return 0;
}
