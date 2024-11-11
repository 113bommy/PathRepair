#include <bits/stdc++.h>
using namespace std;
int N, M;
char table[512][512];
vector<char> ans1;
vector<int> ans2, ans3;
void output(char c, int x, int y) {
  ans1.push_back(c);
  ans2.push_back(x);
  ans3.push_back(y);
}
void go(int x, int y) {
  table[x][y] = '#';
  output('B', x, y);
  for (int d = 0; d < 4; d++) {
    int dx = x + "1102"[d] - '1';
    int dy = y + "0211"[d] - '1';
    if (table[dx][dy] == '.') {
      go(dx, dy);
      output('R', dx, dy);
    }
  }
  output('D', x, y);
}
int main() {
  memset(table, '#', sizeof(table));
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) scanf(" %c", table[i] + j);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++)
      if (table[i][j] == '.') {
        go(i, j);
        output('B', i, j);
      }
  printf("%d\n", (int)ans1.size());
  for (int i = 0; i < ans1.size(); i++)
    printf("%c %d %d\n", ans1[i], ans2[i], ans3[i]);
  return 0;
}
