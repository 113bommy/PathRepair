#include <bits/stdc++.h>
using namespace std;
inline long long Getint() {
  char ch = getchar();
  long long x = 0, fh = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    (x *= 10) += ch ^ 48;
    ch = getchar();
  }
  return x * fh;
}
const int N = 1000005;
int n, p, M, m, tot;
vector<int> G[N];
inline void Addside(int x, int y) { G[x].push_back(y); }
int dfn[N], llk[N], tim, blk;
bool ist[N];
int st[N], col[N];
void Tarjan(int u) {
  dfn[u] = llk[u] = ++tim;
  st[++st[0]] = u;
  ist[u] = 1;
  for (int i = 0; i <= int(G[u].size()) - 1; i++) {
    int v = G[u][i];
    if (!dfn[v])
      Tarjan(v), llk[u] = min(llk[u], llk[v]);
    else if (ist[v])
      llk[u] = min(llk[u], dfn[v]);
  }
  if (llk[u] == dfn[u]) {
    blk++;
    int x;
    do {
      x = st[st[0]--];
      ist[x] = 0;
      col[x] = blk;
    } while (x != u);
  }
}
int main() {
  int x, y, z;
  n = Getint();
  p = Getint();
  M = Getint();
  m = Getint();
  for (int i = 1; i <= n; i++) {
    x = Getint();
    y = Getint();
    Addside(x << 1, y << 1 | 1);
    Addside(y << 1, x << 1 | 1);
  }
  for (int i = 1; i <= p; i++) {
    x = Getint();
    y = Getint();
    Addside(i << 1 | 1, (p + x) << 1 | 1);
    Addside((p + x) << 1, i << 1);
    Addside(i << 1 | 1, (p + y + 1) << 1);
    Addside((p + y + 1) << 1 | 1, i << 1);
  }
  for (int i = 1; i <= m; i++) {
    x = Getint();
    y = Getint();
    Addside(x << 1 | 1, y << 1);
    Addside(y << 1 | 1, x << 1);
  }
  for (int i = 1; i <= M; i++) {
    Addside((p + i) << 1, (p + i + 1) << 1);
    Addside((p + i + 1) << 1 | 1, (p + i) << 1 | 1);
  }
  tot = p + M + 1;
  for (int i = 2; i <= (tot << 1 | 1); i++) {
    if (!dfn[i]) Tarjan(i);
  }
  for (int i = 1; i <= tot; i++) {
    if (col[i << 1] == col[i << 1 | 1]) return puts("-1"), 0;
  }
  vector<int> Ans;
  Ans.clear();
  int f = 1;
  for (int i = 1; i <= tot; i++) {
    if (col[i << 1] > col[i << 1 | 1]) continue;
    if (i <= p)
      Ans.push_back(i);
    else
      f = max(f, i - p);
  }
  cout << Ans.size() << ' ' << f << '\n';
  for (int i = 0; i <= int(Ans.size()) - 1; i++) {
    cout << Ans[i] << ' ';
  }
  cout << '\n';
  return 0;
}
