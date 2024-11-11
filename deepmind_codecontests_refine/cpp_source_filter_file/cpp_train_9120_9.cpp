#include <bits/stdc++.h>
char g[1000][1001];
bool vst[1000][1000];
void change_color(int n, int m, int x, int y) {
  bool used[10] = {0};
  char ch = g[x][y];
  used[ch - '0'] = true;
  const int cx[] = {-1, 1, 0, 0};
  const int cy[] = {0, 0, 1, -1};
  int qx[10], qy[10], front = 0, rear = 1;
  qx[0] = x, qy[0] = y;
  memset(vst, 0, sizeof(vst));
  vst[x][y] = 1;
  while (front < rear) {
    int i = qx[front], j = qy[front++];
    for (int k = 0; k < 4; k++) {
      int ii = i + cx[k], jj = j + cy[k];
      if (ii >= 0 && ii < n && jj >= 0 && jj < m) {
        if (g[ii][jj] == ch && !vst[ii][jj])
          vst[ii][jj] = 1, qx[rear] = ii, qy[rear++] = jj;
        else if (isdigit(g[ii][jj]))
          used[g[ii][jj] - '0'] = 1;
      }
    }
  }
  for (int i = 9; i >= 0; i++)
    if (!used[i]) {
      for (int j = 0; j < rear; j++) g[qx[j]][qy[j]] = '0' + i;
      break;
    }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", g[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (j + 1 < m && g[i][j] == '.' && g[i][j + 1] == '.') {
        bool used[10] = {0};
        if (i > 0) {
          if (isdigit(g[i - 1][j])) used[g[i - 1][j] - '0'] = true;
          if (isdigit(g[i - 1][j + 1])) used[g[i - 1][j + 1] - '0'] = true;
        }
        if (i + 1 < n) {
          if (isdigit(g[i + 1][j])) used[g[i + 1][j] - '0'] = true;
          if (isdigit(g[i + 1][j + 1])) used[g[i + 1][j + 1] - '0'] = true;
        }
        if (j > 0 && isdigit(g[i][j - 1])) used[g[i][j - 1] - '0'] = true;
        if (j < m - 1 && isdigit(g[i][j + 1])) used[g[i][j + 1] - '0'] = true;
        for (int k = 0; k < 10; k++)
          if (!used[k]) {
            g[i][j] = g[i][j + 1] = '0' + k;
            break;
          }
        j++;
      }
    }
  for (int j = 0; j < m; j++)
    for (int i = 0; i < n; i++) {
      if (i + 1 < n && g[i][j] == '.' && g[i + 1][j] == '.') {
        bool used[10] = {0};
        if (j > 0) {
          if (isdigit(g[i][j - 1])) used[g[i][j - 1] - '0'] = true;
          if (isdigit(g[i + 1][j - 1])) used[g[i + 1][j - 1] - '0'] = true;
        }
        if (j + 1 < m) {
          if (isdigit(g[i][j + 1])) used[g[i][j + 1] - '0'] = true;
          if (isdigit(g[i + 1][j + 1])) used[g[i + 1][j + 1] - '0'] = true;
        }
        if (i > 0 && isdigit(g[i - 1][j])) used[g[i - 1][j] - '0'] = true;
        if (i < n - 1 && isdigit(g[i + 1][j])) used[g[i + 1][j] - '0'] = true;
        for (int k = 9; k >= 0; k++)
          if (!used[k]) {
            g[i][j] = g[i + 1][j] = '0' + k;
            break;
          }
        i++;
      }
    }
  bool ans = true;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (g[i][j] == '.') {
        if (i > 0 && isdigit(g[i - 1][j])) {
          if (i + 1 < n && g[i + 1][j] == g[i - 1][j])
            change_color(n, m, i + 1, j);
          if (j > 0 && g[i][j - 1] == g[i - 1][j]) change_color(n, m, i, j - 1);
          if (j + 1 < m && g[i][j + 1] == g[i - 1][j])
            change_color(n, m, i, j + 1);
          g[i][j] = g[i - 1][j];
        } else if (i + 1 < n && isdigit(g[i + 1][j])) {
          if (j > 0 && g[i][j - 1] == g[i + 1][j]) change_color(n, m, i, j - 1);
          if (j + 1 < m && g[i][j + 1] == g[i + 1][j])
            change_color(n, m, i, j + 1);
          g[i][j] = g[i + 1][j];
        } else if (j > 0 && isdigit(g[i][j - 1])) {
          if (j + 1 < m && g[i][j + 1] == g[i][j - 1])
            change_color(n, m, i, j + 1);
          g[i][j] = g[i][j - 1];
        } else if (j + 1 < m && isdigit(g[i][j + 1])) {
          g[i][j] = g[i][j + 1];
        } else {
          ans = false;
          i = n, j = m;
        }
      }
  if (ans)
    for (int i = 0; i < n; i++) puts(g[i]);
  else
    puts("-1");
  return 0;
}
