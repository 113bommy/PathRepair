#include <bits/stdc++.h>
using namespace std;
int n, m;
int solve() {
  if (m == 1) {
    return -1;
  } else if (m == 2) {
    if (n == 1) return 1;
    if (n == 2) return 5;
    if (n == 3) return 11;
    return -1;
  } else if (m == 3) {
    if (n == 1) return 1;
    if (n == 2) return 3;
    if (n == 3) return 5;
    if (n == 4) return 9;
    if (n == 5) return 11;
    return -1;
  } else if (m & 1) {
    m >>= 1;
    if (n <= m) return 1;
    if (n <= 2 * m) return 3;
    if (n <= 3 * m - 1) return 5;
    if (n <= 4 * m - 1) return 7;
    return (n - 4) / (m / 2 - 1) * 2 + 1;
  } else {
    return (n - 2) / (m / 2 - 1) * 2 + 1;
  }
}
bool vis[111][111][2];
struct Node {
  int w, s, side;
  Node() {}
  Node(int a, int b, int c) : w(a), s(b), side(c) {}
};
queue<Node> que;
int bfs(int n, int m) {
  int tep = 0;
  memset(vis, false, sizeof(vis));
  while (!que.empty()) que.pop();
  que.push(Node(n, n, 0));
  while (!que.empty()) {
    int sz = que.size();
    while (sz--) {
      int w = que.front().w;
      int s = que.front().s;
      int side = que.front().side;
      que.pop();
      if (vis[w][s][side]) continue;
      vis[w][s][side] = true;
      if (w == 0 && s == 0 && side == 1) return tep;
      if (side == 0) {
        for (int x = 1; x <= m; x++) {
          for (int ww = 0; ww <= x; ww++) {
            int ss = x - ww;
            if (ww > w) continue;
            if (ss > s) continue;
            if (ww > ss && ss != 0) continue;
            if (w - ww > s - ss && s - ss != 0) continue;
            if (n - w + ww > n - s + ss && n - s + ss != 0) continue;
            que.push(Node(w - ww, s - ss, 1));
          }
        }
      } else {
        for (int x = 1; x <= m; x++) {
          for (int ww = 0; ww <= x; ww++) {
            int ss = x - ww;
            if (ww > n - w) continue;
            if (ss > n - s) continue;
            if (ww > ss && ss != 0) continue;
            if (w + ww > s + ss && s + ss != 0) continue;
            if (n - w - ww > n - s - ss && n - s - ss != 0) continue;
            que.push(Node(w + ww, s + ss, 0));
          }
        }
      }
    }
    tep++;
  }
  return -1;
}
int main() {
  cin >> n >> m;
  cout << solve() << endl;
  return 0;
}
