#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 305;
int n, m, las, len;
int zer[M], one[M];
queue<char> a[M][M];
int b[M][M], lb[M][M];
char s[N];
int ans[N * 4][4], A;
void move(int x1, int Y1, int x2, int y2) {
  if (x1 == x2 && Y1 == y2) return;
  A++;
  ans[A][0] = x1;
  ans[A][1] = Y1;
  ans[A][2] = x2;
  ans[A][3] = y2;
}
void move2(int x1, int Y1, int x2, int y2) {
  if (x1 == x2 && Y1 == y2) {
    move(x1, Y1, x1, Y1 + 1);
    move(x1, Y1 + 1, x1, Y1);
  }
  move(x1, Y1, x1, y2);
  move(x1, y2, x2, y2);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%s", s);
      len = strlen(s);
      for (int k = len; k--;) a[i][j].push(s[k]);
    }
  while (!a[1][1].empty())
    if (a[1][1].front() == '0') {
      move(1, 1, 1, 2);
      a[1][2].push(a[1][1].front());
      a[1][1].pop();
    } else {
      move(1, 1, n, 1);
      one[1]++;
      a[1][1].pop();
    }
  while (!a[n][1].empty())
    if (a[n][1].front() == '1') {
      move(n, 1, n, 2);
      a[n][2].push(a[n][1].front());
      a[n][1].pop();
    } else {
      move(n, 1, 1, 1);
      zer[1]++;
      a[n][1].pop();
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      for (; !a[i][j].empty(); a[i][j].pop())
        if (a[i][j].front() == '0') {
          if (i == 1)
            move(i, j, 1, 1), zer[1]++;
          else
            move(i, j, 1, j), zer[j]++;
        } else {
          if (i == n)
            move(i, j, n, 1), one[1]++;
          else
            move(i, j, n, j), one[j]++;
        }
    }
  for (int i = 2; i <= m; i++)
    while (zer[i]) move(1, i, 1, 1), zer[i]--, zer[1]++;
  for (int i = 2; i <= m; i++)
    while (one[i]) move(n, i, n, 1), one[i]--, one[1]++;
  int las = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%s", s + las);
      b[i][j] = las;
      lb[i][j] = strlen(s + las);
      las += lb[i][j] + 1;
    }
  for (int k = lb[1][1]; k--;)
    if (s[b[1][1] + k] == '0')
      move2(1, 1, 1, 1);
    else
      move2(n, 1, 1, 1);
  for (int k = lb[n][1]; k--;)
    if (s[b[n][1] + k] == '0')
      move2(1, 1, n, 1);
    else
      move2(n, 1, n, 1);
  memset(zer, 0, sizeof(zer));
  memset(one, 0, sizeof(one));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (i == 1 && j == 1 || i == n && j == 1) continue;
      for (int k = lb[i][j]; k--;)
        if (s[b[i][j] + k] == '0') {
          if (i == 1 || j == 1)
            zer[1]++;
          else
            move(1, 1, 1, j), zer[j]++;
        } else {
          if (i == n || j == 1)
            one[1]++;
          else
            move(n, 1, n, j), one[j]++;
        }
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (i == 1 && j == 1 || i == n && j == 1) continue;
      for (int k = lb[i][j]; k--;)
        if (s[b[i][j] + k] == '0') {
          if (i == 1 || j == 1)
            move(1, 1, i, j);
          else
            move(1, j, i, j);
        } else {
          if (i == n || j == 1)
            move(n, 1, i, j);
          else
            move(n, j, i, j);
        }
    }
  printf("%d\n", A);
  for (int i = 1; i <= A; i++, puts(""))
    for (int j = 0; j < 4; j++) printf("%d ", ans[i][j]);
}
