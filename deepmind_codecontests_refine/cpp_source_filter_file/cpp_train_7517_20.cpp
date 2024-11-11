#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, -1, -1, 0, 0, +1, +1, +1};
int dy[] = {-1, 0, +1, -1, +1, -1, 0, +1};
string element[8][8];
bool visited[8][8][8];
bool valid(int i, int j, int n, int m) {
  if (i >= 0 && j >= 0 && i < n && j < m) return true;
  return false;
}
class Graph {
  int V;

 public:
  Graph();
  int BFS();
};
Graph::Graph() {}
int Graph::BFS() {
  int x, y;
  pair<int, int> s, temp;
  s.first = 7;
  s.second = 0;
  visited[0][7][0] = true;
  list<pair<int, int> > queue;
  queue.push_back(s);
  int l = 0;
  list<int> level;
  level.push_back(0);
  while (!queue.empty()) {
    s = queue.front();
    queue.pop_front();
    l = level.front();
    level.pop_front();
    if (l == 7) return 1;
    for (int j = 0; j < 8; j++) {
      x = s.first + dx[j];
      y = s.second + dy[j];
      if (valid(x, y, 8, 8)) {
        if (!visited[l + 1][x][y] && element[l][x][y] != 'S' &&
            element[l + 1][x][y] != 'S') {
          visited[(l + 1) % 8][x][y] = true;
          temp.first = x;
          temp.second = y;
          if (x == 0 && y == 7) return 1;
          queue.push_back(temp);
          level.push_back(l + 1);
        }
      }
    }
  }
  return -1;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  Graph graph;
  string s[8];
  for (int i = 0; i < 8; i++) cin >> s[i];
  string top = "........", temp;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (j - i >= 0)
        element[i][j] = s[j - i];
      else
        element[i][j] = top;
    }
  }
  int answer = graph.BFS();
  if (answer == -1)
    printf("LOSE\n");
  else
    printf("WIN\n");
  return 0;
}
