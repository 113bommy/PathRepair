#include <bits/stdc++.h>
using namespace std;
const int N = 8;
int sx, sy, ex, ey;
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<pair<int, int> > status;
struct Node {
  int x, y, t;
  Node() {}
  Node(int _x, int _y, int _t) {
    x = _x;
    y = _y;
    t = _t;
  }
};
bool chk(Node x) {
  for (int i = 0; i < status.size(); i++) {
    if (status[i].second == x.y && status[i].first + x.t == x.x) return 0;
  }
  return 1;
}
queue<Node> q;
bool bfs(int sx, int sy, int ex, int ey) {
  while (!q.empty()) q.pop();
  q.push(Node(sx, sy, 0));
  while (!q.empty()) {
    Node t = q.front();
    q.pop();
    if (!chk(t)) continue;
    if ((t.x == ex && t.y == ey) || t.t >= N) return 1;
    for (int i = 0; i < 8; i++) {
      int tx = t.x + dx[i];
      int ty = t.y + dy[i];
      if (tx < 1 || tx > N || ty < 1 || ty > N) continue;
      if (chk(Node(tx, ty, t.t))) {
        q.push(Node(tx, ty, t.t + 1));
      }
    }
  }
  return 0;
}
int main() {
  for (int i = 1; i <= N; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= N; j++) {
      char ch = s[j - 1];
      if (ch == 'M') {
        sx = i;
        sy = j;
      } else if (ch == 'A') {
        ex = i;
        ey = j;
      } else if (ch == 'S') {
        status.push_back(make_pair(i, j));
      }
    }
  }
  printf("%s\n", bfs(sx, sy, ex, ey) ? "WIN" : "LOSE");
  return 0;
}
