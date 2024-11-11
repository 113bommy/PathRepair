#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int MAXN = 1001;
struct Event {
  char O;
  int x, y;
  Event() {}
  Event(char O, int x, int y) : O(O), x(x), y(y){};
};
int N, M;
int A[MAXN][MAXN], B[MAXN][MAXN];
char S[MAXN][MAXN];
vector<Event> E;
inline void DFS(int x0, int y0) {
  E.push_back(Event('B', x0, y0));
  for (int k = 0; k < 4; ++k) {
    int x1 = x0 + dx[k], y1 = y0 + dy[k];
    if (x1 >= 1 && x1 <= N && y1 >= 1 && y1 <= M && A[x1][y1] && !B[x0][y0])
      B[x1][y1] = 2, DFS(x1, y1);
  }
  if (B[x0][y0] == 2) {
    E.push_back(Event('D', x0, y0));
    E.push_back(Event('R', x0, y0));
  }
}
int main() {
  scanf("%d %d\n", &N, &M);
  for (int i = 1; i <= N; ++i) scanf("%s", S[i] + 1);
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j) A[i][j] = (S[i][j] == '.');
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j)
      if (A[i][j] && !B[i][j]) B[i][j] = 1, DFS(i, j);
  printf("%d\n", (int)E.size());
  for (int i = 0; i < (int)E.size(); ++i)
    printf("%c %d %d\n", E[i].O, E[i].x, E[i].y);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
