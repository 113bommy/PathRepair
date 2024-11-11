#include <bits/stdc++.h>
using namespace std;
int Nextint() {
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  int x = 0;
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
const int maxn = 2010;
int N, C[maxn][maxn], S[maxn][maxn];
int lq, cir, sq;
double que[maxn * maxn][2], srt[maxn * maxn];
bool vis[maxn][maxn];
void add(int x, int y) {
  if (x < 1 || x > N || y < 1 || y > N) return;
  if (vis[x][y] || S[x][y] == 0) return;
  vis[x][y] = true;
  lq++;
  que[lq][0] = x;
  que[lq][1] = y;
}
void dfs(int x, int y) {
  add(x, y);
  int t = 1;
  while (t <= lq) {
    x = int(que[t][0]);
    y = int(que[t][1]);
    for (int i = -1; i <= 1; i++)
      for (int j = -1; j <= 1; j++)
        if (i * j == 0 && i + j != 0) add(x + i, y + j);
    t++;
  }
}
void Calc() {
  if (lq < 100) return;
  double x, y;
  for (int i = 1; i <= lq; i++) srt[i] = que[i][0];
  nth_element(srt + 1, srt + (lq / 2), srt + lq + 1);
  x = srt[lq / 2];
  for (int i = 1; i <= lq; i++) srt[i] = que[i][1];
  nth_element(srt + 1, srt + (lq / 2), srt + lq + 1);
  y = srt[lq / 2];
  double d = 0;
  for (int i = 1; i <= lq; i++)
    srt[i] =
        (x - que[i][0]) * (x - que[i][0]) + (y - que[i][1]) * (y - que[i][1]);
  int tmp = (lq - (lq / sqrt(lq) / 3));
  nth_element(srt + 1, srt + tmp, srt + lq + 1);
  d = srt[tmp];
  if (1.0 * lq / d < 2.33)
    sq++;
  else
    cir++;
}
int main() {
  N = Nextint();
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) scanf("%d", &C[i][j]);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) {
      int ts = 0;
      for (int i1 = i - 2; i1 <= i + 2; i1++)
        for (int j1 = j - 2; j1 <= j + 2; j1++)
          if (i1 > 0 && i1 <= N && j1 <= N && j1 > 0) ts += C[i][j];
      if (ts > 10) S[i][j] = 1;
    }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      if (!vis[i][j] && S[i][j] == 1) {
        lq = 0;
        dfs(i, j);
        Calc();
      }
  printf("%d %d\n", cir, sq);
  return 0;
}
