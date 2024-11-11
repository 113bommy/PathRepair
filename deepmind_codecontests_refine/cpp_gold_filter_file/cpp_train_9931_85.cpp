#include <bits/stdc++.h>
using namespace std;
const int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int S, N, M, L, R, U, D, a[1605][1605], b[1605][1605], c[1605][1605], ans[1605];
void init() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) scanf("%d", &a[i][j]);
}
void dfs1(int x, int y) {
  L = min(L, y), R = max(R, y);
  U = min(U, x), D = max(D, x);
  a[x][y] = 0, b[x][y] = S;
  for (int i = 0; i < 4; i++) {
    int xx = x + d[i][0], yy = y + d[i][1];
    if ((1 <= xx && xx <= N && 1 <= yy && yy <= M) && a[xx][yy]) dfs1(xx, yy);
  }
}
int dfs2(int x, int y) {
  int s = 0;
  c[x][y] = 0;
  for (int i = 0; i < 4; i++) {
    int xx = x + d[i][0], yy = y + d[i][1];
    if ((1 <= xx && xx <= N && 1 <= yy && yy <= M) && c[xx][yy] == S)
      s += dfs2(xx, yy);
  }
  return s + 1;
}
int work(int sx, int sy) {
  L = U = 1e9, R = D = 0, dfs1(sx, sy);
  for (int i = U; i <= D; i++)
    for (int j = L, k; j <= R; j++)
      if (b[i][j] == S) {
        for (k = j; k <= R && b[i][k] == S; k++)
          ;
        if (k - j <= 6)
          for (; j < k; j++) c[i][j] = S;
        j = k - 1;
      }
  for (int j = L; j <= R; j++)
    for (int i = U, k; i <= D; i++)
      if (b[i][j] == S) {
        for (k = i; k <= D && b[k][j] == S; k++)
          ;
        if (k - i <= 6)
          for (; i < k; i++) c[i][j] = S;
        i = k - 1;
      }
  for (int i = U; i <= D + R - L; i++)
    for (int j = 0, k; j <= R - L; j++)
      if ((1 <= i - j && i - j <= N && 1 <= L + j && L + j <= M) &&
          b[i - j][L + j] == S) {
        for (k = j; (1 <= i - k && i - k <= N && 1 <= L + k && L + k <= M) &&
                    b[i - k][L + k] == S;
             k++)
          ;
        if (k - j <= 6)
          for (; j < k; j++) c[i - j][L + j] = S;
        j = k - 1;
      }
  for (int i = U - (R - L); i <= D; i++)
    for (int j = 0, k; j <= R - L; j++)
      if ((1 <= i + j && i + j <= N && 1 <= L + j && L + j <= M) &&
          b[i + j][L + j] == S) {
        for (k = j; (1 <= i + k && i + k <= N && 1 <= L + k && L + k <= M) &&
                    b[i + k][L + k] == S;
             k++)
          ;
        if (k - j <= 6)
          for (; j < k; j++) c[i + j][L + j] = S;
        j = k - 1;
      }
  int res = 0;
  for (int i = U; i <= D; i++)
    for (int j = L; j <= R; j++)
      if (c[i][j] == S) {
        int ss = dfs2(i, j);
        if (ss >= 20) res++;
      }
  return res;
}
void doit() {
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      if (a[i][j]) S++, ans[S] = work(i, j);
  sort(ans + 1, ans + S + 1), printf("%d\n", S);
  for (int i = 1; i <= S; i++) printf("%d%c", ans[i], i == S ? '\n' : ' ');
}
int main() {
  init();
  doit();
  return 0;
}
