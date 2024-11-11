#include <bits/stdc++.h>
using namespace std;
const int maxn(2005);
const int maxm(16005);
int n, lenl, lenr, trs[maxm][10], tot, fail[maxm], g[maxm][maxn], f[maxm][maxn],
    ans;
bitset<maxn> vis[maxm];
char liml[maxn], limr[maxn];
queue<int> Q;
inline void Upd(int &x, int y) { x = x > y ? x : y; }
inline void Init() {
  int i, c, cur1, cur2;
  scanf(" %s %s%d", liml + 1, limr + 1, &n);
  lenl = strlen(liml + 1), lenr = strlen(limr + 1);
  if (lenl == lenr) {
    cur1 = cur2 = 0;
    for (i = 1; i <= lenl; ++i) {
      if (cur1 == cur2) {
        for (c = liml[i] - '0' + 1; c < limr[i] - '0'; ++c) {
          if (!trs[cur1][c]) trs[cur1][c] = ++tot;
          ++g[trs[cur1][c]][lenl - i];
        }
      } else {
        for (c = liml[i] - '0' + 1; c < 10; ++c) {
          if (!trs[cur1][c]) trs[cur1][c] = ++tot;
          ++g[trs[cur1][c]][lenl - i];
        }
        for (c = 0; c < limr[i] - '0'; ++c) {
          if (!trs[cur2][c]) trs[cur2][c] = ++tot;
          ++g[trs[cur2][c]][lenl - i];
        }
      }
      if (!trs[cur1][liml[i] - '0']) trs[cur1][liml[i] - '0'] = ++tot;
      if (!trs[cur2][limr[i] - '0']) trs[cur2][limr[i] - '0'] = ++tot;
      cur1 = trs[cur1][liml[i] - '0'], cur2 = trs[cur2][limr[i] - '0'];
    }
    ++g[cur1][0];
    if (cur1 ^ cur2) ++g[cur2][0];
  } else {
    cur1 = cur2 = 0;
    for (i = 1; i <= lenl; ++i) {
      for (c = liml[i] - '0' + 1; c < 10; ++c) {
        if (!trs[cur1][c]) trs[cur1][c] = ++tot;
        ++g[trs[cur1][c]][lenl - i];
      }
      if (!trs[cur1][liml[i] - '0']) trs[cur1][liml[i] - '0'] = ++tot;
      cur1 = trs[cur1][liml[i] - '0'];
    }
    for (i = 1; i <= lenr; ++i) {
      for (c = i == 1; c < limr[i] - '0'; ++c) {
        if (!trs[cur2][c]) trs[cur2][c] = ++tot;
        ++g[trs[cur2][c]][lenr - i];
      }
      if (!trs[cur2][limr[i] - '0']) trs[cur2][limr[i] - '0'] = ++tot;
      cur2 = trs[cur2][limr[i] - '0'];
    }
    ++g[cur1][0], ++g[cur2][0];
    for (i = lenl + 1; i < lenr; ++i)
      for (c = 1; c < 10; ++c) {
        if (!trs[0][c]) trs[0][c] = ++tot;
        ++g[trs[0][c]][i - 1];
      }
  }
}
inline void GetFail() {
  int u, i, c;
  for (c = 0; c < 10; ++c)
    if (trs[0][c]) Q.push(trs[0][c]);
  while (!Q.empty()) {
    u = Q.front(), Q.pop();
    for (c = 0; c < 10; ++c)
      if (trs[u][c])
        fail[trs[u][c]] = trs[fail[u]][c], Q.push(trs[u][c]);
      else
        trs[u][c] = trs[fail[u]][c];
    for (i = 0; i <= n; ++i) g[u][i] += g[fail[u]][i];
  }
  for (i = 0; i <= tot; ++i)
    for (c = 1; c <= n; ++c) g[i][c] += g[i][c - 1];
}
inline void Solve(int x, int y) {
  if (y == n) return;
  int c;
  for (c = 0; c < 10; ++c)
    if (f[x][y] + g[trs[x][c]][n - y - 1] == f[trs[x][c]][y + 1] &&
        vis[trs[x][c]][y + 1]) {
      putchar(c + '0'), Solve(trs[x][c], y + 1);
      return;
    }
}
int main() {
  int i, j, c;
  memset(f, -63, sizeof(f));
  Init(), GetFail(), f[0][0] = 0;
  for (i = 1; i <= n; ++i)
    for (j = 0; j <= tot; ++j)
      if (f[j][i - 1] >= 0)
        for (c = 0; c < 10; ++c)
          Upd(f[trs[j][c]][i], f[j][i - 1] + g[trs[j][c]][n - i]);
  for (j = 0; j <= tot; ++j) Upd(ans, f[j][n]);
  for (j = 0; j <= tot; ++j)
    if (f[j][n] == ans) vis[j][n] = 1;
  for (i = n; i; --i)
    for (j = 0; j <= tot; ++j)
      for (c = 0; c < 10; ++c)
        if (vis[trs[j][c]][i] &&
            f[trs[j][c]][i] == f[j][i - 1] + g[trs[j][c]][n - i])
          vis[j][i - 1] = 1;
  printf("%d\n", ans), Solve(0, 0), puts("");
  return 0;
}
