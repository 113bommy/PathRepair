#include <bits/stdc++.h>
using namespace std;
int n, ax, ay, bx, by, cx, cy, vis[1001][1001];
void dfs(int first, int second) {
  if (first < 1 or first > n or second < 1 or second > n or
      vis[first][second] or first == ax || second == ay ||
      abs(first - ax) == abs(second - ay))
    return;
  vis[first][second] = 1;
  if (first == cx and second == cy) {
    cout << "YES" << '\n';
    exit(0);
  }
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      if (i == 0 and j == 0) continue;
      dfs(first + i, second + j);
    }
  }
}
void solve() {
  cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
  dfs(bx, by);
  cout << "NO" << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
