#include <bits/stdc++.h>
using namespace std;
void getint(int &v) {
  char ch, fu = 0;
  for (ch = '*'; (ch < '0' || ch > '9') && ch != '-'; ch = getchar())
    ;
  if (ch == '-') fu = 1, ch = getchar();
  for (v = 0; ch >= '0' && ch <= '9'; ch = getchar()) v = v * 10 + ch - '0';
  if (fu) v = -v;
}
vector<int> v[200010];
bool r[500010];
int n, m, x, t, S, Q[500010], C[500010], c[500010], nxt[500010], hed[500010],
    too[500010], nedge, d[500010][2];
pair<int, int> q[500010];
void ae(int x, int y) {
  nxt[++nedge] = hed[x];
  hed[x] = nedge;
  too[nedge] = y;
}
void bfs() {
  int he = 0, ta = 1;
  memset(d, -1, sizeof(d));
  q[1] = make_pair(S, 0);
  d[S][0] = 0;
  while (he != ta) {
    pair<int, int> x = q[++he];
    for (int i = hed[x.first]; i; i = nxt[i]) {
      int y = too[i];
      if (d[y][x.second ^ 1] != -1) continue;
      d[y][x.second ^ 1] = x.first;
      q[++ta] = make_pair(y, x.second ^ 1);
    }
  }
}
void pr(int x, int y) {
  if (x != S || y != 0) pr(d[x][y], y ^ 1);
  printf("%d ", x);
}
void topsort() {
  int he = 0, ta = 0;
  for (int i = 1; i <= n; i++)
    if (c[i] == 0) Q[++ta] = i;
  while (he != ta) {
    int x = Q[++he];
    for (int i = 0; i < v[x].size(); ++i) {
      int y = v[x][i];
      --C[y];
      if (C[y] == 0) Q[++ta] = y;
    }
  }
  for (int i = 1; i <= n; i++) r[i] = 1;
  for (int i = 1; i <= ta; i++) r[Q[i]] = 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t);
    c[i] = t;
    C[i] = t;
    while (t--) {
      scanf("%d", &x);
      ++r[x];
      v[x].push_back(i);
      ae(i, x);
    }
  }
  cin >> S;
  bfs();
  for (int i = 1; i <= n; i++)
    if (c[i] == 0 && d[i][1] != -1) {
      puts("Win");
      pr(i, 1);
      return 0;
    }
  topsort();
  for (int i = 1; i <= n; i++)
    if ((d[i][0] != -1 || d[i][1] != -1) && r[i]) return puts("Draw"), 0;
  puts("Lose");
  return 0;
}
