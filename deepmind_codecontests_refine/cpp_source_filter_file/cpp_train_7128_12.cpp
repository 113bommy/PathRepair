#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2010;
const int inf = 0x7fffffff;
int N, M;
int ar[MAXN][MAXN];
int sol[MAXN][MAXN];
int used[MAXN][MAXN];
int YON[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
queue<pair<int, int> > bir;
char tt[MAXN][MAXN];
void dec(int a, int b) {
  for (int i = 0; i < 4; i++)
    if (a + YON[i][0] && b + YON[i][1] && !used[a + YON[i][0]][b + YON[i][1]]) {
      ar[a + YON[i][0]][b + YON[i][1]]--;
      if (ar[a + YON[i][0]][b + YON[i][1]] == 1)
        bir.push(pair<int, int>(a + YON[i][0], b + YON[i][1]));
    }
}
int T;
int main() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) sol[i][j] = -1;
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      scanf(" %c", &tt[i][j]);
      if (tt[i][j] == '.') T++;
    }
  if (T % 2) {
    puts("Not unique");
    return 0;
  }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      if (tt[i][j] == '.')
        for (int k = 0; k < 4; k++)
          if (i + YON[k][0] && i + YON[k][0] <= N && j + YON[k][1] &&
              j + YON[k][1] <= M) {
            int a = i + YON[k][0];
            int b = j + YON[k][1];
            if (tt[a][b] == '.') ar[i][j]++;
          }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      if (ar[i][j] == 1) bir.push(pair<int, int>(i, j));
  while (!bir.empty()) {
    int i = bir.front().first;
    int j = bir.front().second;
    bir.pop();
    if (used[i][j]) continue;
    for (int k = 0; k < 4; k++)
      if (tt[i + YON[k][0]][j + YON[k][1]] == '.' &&
          !used[i + YON[k][0]][j + YON[k][1]]) {
        sol[i][j] = k;
        sol[i + YON[k][0]][j + YON[k][1]] = 3 - k;
        used[i][j] = used[i + YON[k][0]][j + YON[k][1]] = 1;
        dec(i + YON[k][0], j + YON[k][1]);
        T -= 2;
      }
  }
  if (T) {
    puts("Not unique");
    return 0;
  }
  for (int i = 1; i <= N; i++, puts(""))
    for (int j = 1; j <= M; j++) switch (sol[i][j]) {
        case 0:
          printf(">");
          break;
        case 1:
          printf("v");
          break;
        case 2:
          printf("^");
          break;
        case 3:
          printf("<");
          break;
        default:
          printf("*");
      }
  return 0;
}
