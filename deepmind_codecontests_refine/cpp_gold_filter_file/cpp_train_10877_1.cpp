#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
const int MAXN = 100010;
const int INF = 1e9;
int to[MAXN << 1], nxt[MAXN << 1], head[MAXN], col[MAXN], l[MAXN], r[MAXN];
int N, M, Tmin, Tmax, cnte;
bool flg = true;
inline void addedge(int x, int y) {
  to[++cnte] = y;
  nxt[cnte] = head[x];
  head[x] = cnte;
}
inline bool Cover(int x, int Id) { return l[Id] <= x && x <= r[Id]; }
inline void dfs(int x, int Col) {
  if (col[x] != -1 && col[x] != Col) {
    flg = false;
    return;
  }
  col[x] = Col;
  for (int i = head[x]; i; i = nxt[i]) {
    int y = to[i];
    if (col[y] == -1)
      dfs(y, Col ^ 1);
    else {
      if (col[y] != (Col ^ 1)) {
        flg = false;
        return;
      }
    }
  }
}
int main() {
  memset(col, -1, sizeof(col));
  Tmin = read();
  Tmax = read();
  N = read();
  M = read();
  int L = -INF, R = INF;
  for (int i = 1; i <= N; ++i) {
    l[i] = read(), r[i] = read();
    L = max(L, l[i]);
    R = min(R, r[i]);
  }
  if (L + R < Tmin)
    L = Tmin - R;
  else if (L + R > Tmax)
    R = Tmax - L;
  if (L < 0 || R < 0) {
    puts("IMPOSSIBLE");
    return 0;
  }
  for (int i = 1; i <= M; ++i) {
    int x = read(), y = read();
    addedge(x, y);
    addedge(y, x);
  }
  for (int i = 1; i <= N; ++i) {
    if (Cover(L, i)) {
      if (!Cover(R, i)) dfs(i, 0);
    } else if (Cover(R, i))
      dfs(i, 1);
    else {
      puts("IMPOSSIBLE");
      return 0;
    }
  }
  for (int i = 1; i <= N; ++i)
    if (col[i] == -1) dfs(i, 0);
  if (!flg)
    puts("IMPOSSIBLE");
  else {
    puts("POSSIBLE");
    printf("%d %d\n", L, R);
    for (int i = 1; i <= N; ++i)
      if (col[i] == 0)
        printf("1");
      else
        printf("2");
    printf("\n");
  }
  return 0;
}
