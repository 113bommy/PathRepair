#include <bits/stdc++.h>
using namespace std;
const int MAXN = 510;
vector<int> way[MAXN];
struct node {
  int x, y, s;
  node(int _x = 0, int _y = 0, int _s = 0) {
    x = _x;
    y = _y;
    s = _s;
  }
};
node q[MAXN * MAXN * 10];
bool used[MAXN][MAXN][2];
int dad[MAXN * MAXN];
vector<int> res[2];
int main() {
  int n, m, at = 0, al = 0;
  scanf("%d %d", &n, &m);
  for (int i = 1, a, b; i <= m; i++) {
    scanf(" %d %d", &a, &b);
    way[a].push_back(b);
    way[b].push_back(a);
  }
  q[++at] = node(1, n, 0);
  while (at != al) {
    node tmp = q[++al];
    if (tmp.s == 0 && tmp.x == tmp.y) continue;
    if (tmp.s == 0 && tmp.x == n && tmp.y == 1) {
      for (int i = al; i; i = dad[i]) {
        if (q[i].s == 0) res[0].push_back(q[i].x);
        if (q[i].s == 1) res[1].push_back(q[i].y);
      }
      cout << ((int)res[0].size()) - 1 << endl;
      for (int i = ((int)res[0].size()) - 1; i >= 0; i--)
        printf("%d ", res[0][i]);
      puts("");
      for (int i = ((int)res[1].size()) - 1; i >= 0; i--)
        printf("%d ", res[1][i]);
      printf("1");
      puts("");
      return 0;
    }
    if (tmp.s == 0) {
      for (int i = 0; i < ((int)way[tmp.x].size()); i++)
        if (!used[way[tmp.x][i]][tmp.y][1]) {
          used[way[tmp.x][i]][tmp.y][1] = true;
          q[++at] = node(way[tmp.x][i], tmp.y, 1);
          dad[at] = al;
        }
    } else {
      for (int i = 0; i < ((int)way[tmp.y].size()); i++)
        if (!used[tmp.x][way[tmp.y][i]][0] && tmp.x != way[tmp.y][i]) {
          used[tmp.x][way[tmp.y][i]][0] = true;
          q[++at] = node(tmp.x, way[tmp.y][i], 0);
          dad[at] = al;
        }
    }
  }
  puts("-1");
  return 0;
}
