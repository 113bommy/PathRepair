#include <bits/stdc++.h>
using namespace std;
int m, n, k, xs, ys, xt, yt, l[55][55], len;
char s[55][55], c[4], d[55][55][2505], out[2505];
bool b[300], v[55][55];
bool check(char C) {
  for (int i = 0; i < k; i++)
    if (C == c[i]) return true;
  return false;
}
int q[2505], rq, wq;
bool f1(int i, int j) { return strcmp(d[i / n][i % n], d[j / n][j % n]) < 0; }
void pro(int X, int Y, int L, char *D) {
  if ((0 <= X) && (X < m) && (0 <= Y) && (Y < n) && (check(s[X][Y])) &&
      (v[X][Y])) {
    v[X][Y] = false;
    l[X][Y] = L;
    strcpy(d[X][Y], D);
    d[X][Y][l[X][Y]] = s[X][Y];
    l[X][Y]++;
    d[X][Y][l[X][Y]] = '\0';
    q[wq++] = X * n + Y;
  }
}
void bfs() {
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) l[i][j] = 250000;
  memset(v, true, sizeof(v));
  rq = wq = 0;
  l[xs][ys] = 0;
  strcpy(d[xs][ys], "");
  v[xs][ys] = false;
  q[wq++] = xs * n + ys;
  s[xt][yt] = c[0];
  while (rq != wq) {
    if ((rq != 0) &&
        (l[q[rq] / n][q[rq] % n] != l[q[rq - 1] / n][q[rq - 1] % n]))
      sort(q + rq, q + wq, f1);
    int X = q[rq] / n;
    int Y = q[rq] % n;
    int L = l[X][Y];
    char D[2505];
    strcpy(D, d[X][Y]);
    if ((X == xt) && (Y == yt)) {
      if ((L < len) || ((L == len) && (strcmp(D, out) < 0))) {
        len = L;
        strcpy(out, D);
      }
      break;
    }
    if (L > len) break;
    pro(X - 1, Y, L, D);
    pro(X + 1, Y, L, D);
    pro(X, Y - 1, L, D);
    pro(X, Y + 1, L, D);
    rq++;
  }
}
void dfs(int z, int x) {
  if (z == k) {
    bfs();
  } else {
    for (int i = x; i <= 'z'; i++) {
      if (b[i]) {
        c[z] = i;
        dfs(z + 1, i + 1);
      }
    }
  }
}
int main() {
  scanf("%d%d%d", &m, &n, &k);
  memset(b, false, sizeof(b));
  for (int i = 0; i < m; i++) {
    scanf("%s", s[i]);
    for (int j = 0; j < n; j++) {
      if (s[i][j] == 'S') {
        xs = i;
        ys = j;
      } else if (s[i][j] == 'T') {
        xt = i;
        yt = j;
      } else {
        b[s[i][j]] = true;
      }
    }
  }
  b['w'] = b['x'] = b['y'] = b['z'] = true;
  len = 25000;
  dfs(0, 'a');
  if (len == 25000) {
    printf("-1\n");
  } else {
    out[--len] = '\0';
    printf("%s\n", out);
  }
  return 0;
}
