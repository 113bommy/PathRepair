#include <bits/stdc++.h>
using namespace std;
int width, height;
long long cnt;
char w[60][60];
int visit[60][60];
int isCycle;
int head, tail;
int sx, sy;
void initVisit() {
  for (int i = 0; i < 60 - 1; i++) {
    for (int j = 0; j < 60 - 1; j++) {
      visit[i][j] = 0;
    }
  }
}
void bfs() {
  int y, x;
  deque<pair<int, int>> q;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (w[i][j] == '#') {
        q.push_back(make_pair(i, j));
        visit[i][j] = 1;
        break;
      }
    }
    if (!q.empty()) break;
  }
  while (!q.empty()) {
    pair<int, int> p = q.front();
    y = p.first;
    x = p.second;
    q.pop_front();
    if (y + 1 < height && w[y + 1][x] == '#' && visit[y + 1][x] == 0) {
      q.push_back(make_pair(y + 1, x));
      visit[y + 1][x] = 1;
    }
    if (y - 1 >= 0 && w[y - 1][x] == '#' && visit[y - 1][x] == 0) {
      q.push_back(make_pair(y - 1, x));
      visit[y - 1][x] = 1;
    }
    if (x + 1 < width && w[y][x + 1] == '#' && visit[y][x + 1] == 0) {
      q.push_back(make_pair(y, x + 1));
      visit[y][x + 1] = 1;
    }
    if (x - 1 >= 0 && w[y][x - 1] == '#' && visit[y][x - 1] == 0) {
      q.push_back(make_pair(y, x - 1));
      visit[y][x - 1] = 1;
    }
  }
}
int main(int argc, char **argv) {
  cin >> height >> width;
  int n = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cin >> w[i][j];
      if (w[i][j] == '#') n++;
    }
  }
  if (n == 1) {
    cout << "-1";
    return 0;
  }
  int temp = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (w[i][j] == '#') {
        initVisit();
        w[i][j] = '.';
        bfs();
        temp = 0;
        for (int k = 0; k < height; k++) {
          for (int l = 0; l < width; l++) {
            if (w[k][l] == '#' && visit[k][l] == 0) {
              temp = 1;
              break;
            }
          }
          if (temp == 1) break;
        }
        if (temp == 1) {
          cout << "1";
          return 0;
        }
        w[i][j] = '#';
      }
    }
  }
  cout << "2";
  return 0;
}
