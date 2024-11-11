#include <bits/stdc++.h>
using namespace std;
const int maxr = 250;
const pair<int, int> bib = make_pair(-1, -1);
struct node {
  pair<int, int> tar[2][maxr];
  bool vis_draw, vis_win, finish_draw, vis_lose;
  int dis;
  int dp;
  pair<int, int> &operator[](pair<bool, int> i) {
    return tar[i.first][i.second];
  }
  node() {
    vis_draw = false;
    vis_win = false;
    vis_lose = false;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < maxr; j++) tar[i][j] = bib;
    dp = 0;
    dis = -1;
  }
} graph[maxr][maxr];
pair<int, int> af[2][maxr];
int h, t, r, n, m;
void build() {
  for (int i = 0; i < r + 1; i++)
    for (int j = 0; i + j < r + 1; j++) {
      for (int k = 1; k < min(n, i) + 1; k++)
        if (i + j - k + af[0][k].first + af[0][k].second < r + 1)
          graph[i][j][make_pair(false, k)] =
              make_pair(i - k + af[0][k].first, j + af[0][k].second);
      for (int k = 1; k < min(m, j) + 1; k++)
        if (i + j - k + af[0][k].first + af[0][k].second < r + 1)
          graph[i][j][make_pair(true, k)] =
              make_pair(i + af[1][k].first, j - k + af[1][k].second);
    }
}
queue<pair<int, int> > queen;
void win_push(pair<int, int> v) {
  for (int i = 1; i < n + 1; i++) {
    pair<int, int> maghsad = graph[v.first][v.second][make_pair(false, i)];
    if (maghsad != bib && !graph[maghsad.first][maghsad.second].vis_win) {
      graph[maghsad.first][maghsad.second].vis_win = true;
      graph[maghsad.first][maghsad.second].dis =
          graph[v.first][v.second].dis + 1;
      queen.push(maghsad);
    }
  }
  for (int i = 1; i < m + 1; i++) {
    pair<int, int> maghsad = graph[v.first][v.second][make_pair(true, i)];
    if (maghsad != bib && !graph[maghsad.first][maghsad.second].vis_win) {
      graph[maghsad.first][maghsad.second].vis_win = true;
      graph[maghsad.first][maghsad.second].dis =
          graph[v.first][v.second].dis + 1;
      queen.push(maghsad);
    }
  }
}
int win() {
  graph[h][t].vis_win = true;
  graph[h][t].dis = 0;
  queen.push(make_pair(h, t));
  while (!queen.empty()) {
    win_push(queen.front());
    queen.pop();
  }
  return graph[0][0].dis;
}
bool draw(pair<int, int> v) {
  if (graph[v.first][v.second].vis_draw)
    return !graph[v.first][v.second].finish_draw;
  graph[v.first][v.second].vis_draw = true;
  for (int i = 1; i < n + 1; i++) {
    pair<int, int> maghsad = graph[v.first][v.second][make_pair(false, i)];
    if (maghsad != bib) {
      bool ps = draw(maghsad);
      if (ps) return true;
    }
  }
  for (int i = 1; i < m + 1; i++) {
    pair<int, int> maghsad = graph[v.first][v.second][make_pair(true, i)];
    if (maghsad != bib) {
      bool ps = draw(maghsad);
      if (ps) return true;
    }
  }
  graph[v.first][v.second].finish_draw = true;
  return false;
}
int loser(pair<int, int> v) {
  if (graph[v.first][v.second].vis_lose) return graph[v.first][v.second].dp;
  graph[v.first][v.second].vis_lose = true;
  for (int i = 1; i < n + 1; i++) {
    pair<int, int> maghsad = graph[v.first][v.second][make_pair(false, i)];
    if (maghsad != bib)
      graph[v.first][v.second].dp =
          max(graph[v.first][v.second].dp, loser(maghsad));
  }
  for (int i = 1; i < m + 1; i++) {
    pair<int, int> maghsad = graph[v.first][v.second][make_pair(true, i)];
    if (maghsad != bib)
      graph[v.first][v.second].dp =
          max(graph[v.first][v.second].dp, loser(maghsad));
  }
  graph[v.first][v.second].dp++;
  return graph[v.first][v.second].dp;
}
int main() {
  scanf("%d %d %d", &h, &t, &r);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d %d", &af[0][i + 1].first, &af[0][i + 1].second);
  scanf("%d", &m);
  for (int i = 0; i < m; i++)
    scanf("%d %d", &af[1][i + 1].first, &af[1][i + 1].second);
  build();
  int uwin = win();
  if (uwin != -1) {
    printf("Ivan\n%d", uwin);
    return 0;
  }
  if (draw(make_pair(h, t))) {
    puts("Draw");
    return 0;
  }
  printf("Zmey\n%d", loser(make_pair(h, t)));
}
