#include <bits/stdc++.h>
using namespace std;
const int N = 9;
const int Mod = 9997;
const int step[][2] = {{0, 1},  {0, -1}, {1, 0},   {-1, 0}, {1, 1},
                       {1, -1}, {-1, 1}, {-1, -1}, {0, 0}};
struct Node {
  int dis, x, y;
  char mat[N][N];
  bool operator<(const Node& p) const { return dis > p.dis; }
  bool operator==(const Node& p) const {
    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
        if (mat[i][j] != p.mat[i][j]) return false;
    return true;
  }
};
vector<Node> v[10000];
int hashstr(const Node& n) {
  int ans = 0;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) ans += n.mat[i][j];
  return ans % Mod;
}
void insert(int id, Node n) { v[id].push_back(n); }
bool exist(int id, const Node& n) {
  for (int i = 0; i < v[id].size(); i++) {
    if (v[id][i] == n) return true;
  }
  return false;
}
bool gao(Node& now) {
  for (int i = 7; i >= 0; i--) {
    for (int j = 0; j < 8; j++)
      if (now.mat[i][j] == 'S') {
        if (i + 1 <= 7) {
          if (now.mat[i + 1][j] == 'M') return false;
          now.mat[i + 1][j] = 'S';
          now.mat[i][j] = '.';
        } else {
          now.mat[i][j] = '.';
        }
      }
  }
  return true;
}
int main() {
  for (int i = 0; i < 10000; i++) v[i].clear();
  Node now;
  for (int i = 0; i < 8; i++) {
    scanf("%s", now.mat[i]);
  }
  now.x = 0;
  now.y = 7;
  now.dis = 14;
  priority_queue<Node> pq;
  pq.push(now);
  bool ok = false;
  insert(hashstr(now), now);
  while (!pq.empty()) {
    Node now = pq.top();
    pq.pop();
    if (now.x == 0 && now.y == 0) {
      ok = true;
      break;
    }
    for (int i = 0; i < 9; i++) {
      int tx = now.x + step[i][0];
      int ty = now.y + step[i][1];
      if (ty >= 0 && ty <= 7 && tx >= 0 && tx <= 7 && now.mat[ty][tx] != 'S') {
        Node next = now;
        next.x = tx;
        next.y = ty;
        next.dis = ty + 7 - tx;
        next.mat[now.y][now.x] = '.';
        next.mat[ty][tx] = 'M';
        if (gao(next)) {
          int id = hashstr(next);
          if (exist(id, next)) continue;
          insert(id, next);
          pq.push(next);
        }
      }
    }
  }
  ok ? puts("WIN") : puts("LOSE");
  return 0;
}
