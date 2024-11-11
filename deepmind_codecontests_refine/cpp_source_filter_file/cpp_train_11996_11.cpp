#include <bits/stdc++.h>
using namespace std;
inline void chkmax(int &a, int b) {
  if (a < b) a = b;
}
inline void chkmin(int &a, int b) {
  if (a > b) a = b;
}
inline int read() {
  int a = 0, fh = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') fh = -1;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    a = a * 10 + c - 48;
    c = getchar();
  }
  return a * fh;
}
int T, n, m, rt;
int ban[1005], siz[1005], w[1005];
vector<int> edge[1005];
void getrt(int x, int fa) {
  siz[x] = 1;
  w[x] = 0;
  for (int i = 0; i < edge[x].size(); ++i)
    if (edge[x][i] != fa && !ban[edge[x][i]]) {
      getrt(edge[x][i], x);
      if (siz[w[x]] < siz[edge[x][i]]) w[x] = edge[x][i];
      siz[x] += siz[edge[x][i]];
    }
  if (!rt || max(siz[w[rt]], n - siz[rt]) > max(siz[w[x]], n - siz[x])) rt = x;
}
void dfs(int x, int fa) {
  n++;
  for (int i = 0; i < edge[x].size(); ++i)
    if (!ban[edge[x][i]] && edge[x][i] != fa) dfs(edge[x][i], x);
}
int main() {
  n = read();
  int m = read();
  int ans = 0;
  for (int i = 1; i <= n; ++i) ans += (i - 1) / 2;
  if (ans < m) {
    puts("-1");
    return 0;
  }
  int now = 0, lst = 0;
  for (int i = 1; i <= n; ++i) {
    if (now + (i - 1) / 2 <= m) {
      now += (i - 1) / 2;
      printf("%d ", i);
    } else {
      int ned = m - now;
      int p = i - ned * 2;
      now = m;
      printf("%d ", i - 1 + p);
      for (int j = i + 1; j <= n; ++j) printf("%d ", j * 10000);
      return 0;
    }
  }
  return 0;
}
