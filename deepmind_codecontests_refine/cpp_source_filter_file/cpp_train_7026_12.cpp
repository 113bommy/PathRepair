#include <bits/stdc++.h>
using namespace std;
int Dis[4000][2];
int Map[4000][4000];
int Count[4000];
int main() {
  int i, j, k, m, n;
  while (~scanf("%d%d", &n, &m)) {
    memset(Map, 0, sizeof(Map));
    memset(Count, 0, sizeof(Count));
    int Min = 0x7ffffff;
    for (i = 0; i < m; i++) {
      scanf("%d%d", &Dis[i][0], &Dis[i][1]);
      Count[Dis[i][0]]++;
      Count[Dis[i][1]]++;
      Map[Dis[i][0]][Dis[i][1]] = 1;
      Map[Dis[i][1]][Dis[i][0]] = 1;
    }
    for (i = 0; i < m; i++) {
      for (j = 0; j < m; j++) {
        int sum = 0;
        if (Dis[i][0] == Dis[j][0]) {
          if (Map[Dis[i][1]][Dis[j][1]]) {
            sum += Count[Dis[i][0]] + Count[Dis[i][1]] + Count[Dis[j][1]] - 6;
            if (Min > sum) Min = sum;
          }
        } else if (Dis[i][0] == Dis[j][1]) {
          if (Map[Dis[i][1]][Dis[j][0]]) {
            sum += Count[Dis[i][0]] + Count[Dis[i][1]] + Count[Dis[j][0]] - 6;
            if (Min > sum) Min = sum;
          }
        } else if (Dis[i][1] == Dis[j][0]) {
          if (Map[Dis[i][0]][Dis[j][1]]) {
            sum += Count[Dis[i][1]] + Count[Dis[i][0]] + Count[Dis[j][1]] - 6;
            if (Min > sum) Min = sum;
          }
        } else if (Dis[i][1] == Dis[j][1]) {
          if (Map[Dis[i][0]][Dis[j][0]]) {
            sum += Count[Dis[i][1]] + Count[Dis[i][0]] + Count[Dis[j][0]] - 6;
            if (Min > sum) Min = sum;
          }
        }
      }
    }
    if (Min < 0x7ffffff)
      printf("%d\n", Min);
    else
      printf("-1\n");
  }
  return 0;
}
