#include <bits/stdc++.h>
using namespace std;
bool explored[101] = {};
bool arch[101][101] = {};
int colors[101] = {};
int n, m;
void dfs(int node) {
  explored[node] = true;
  for (int i = 1; i <= n; i++) {
    if (i == node || !arch[node][i]) continue;
    if (explored[i] && colors[node] == colors[i]) {
      colors[node] = -1;
      return;
    } else if (!explored[i]) {
      colors[i] = abs(colors[node] - 1);
      dfs(i);
    }
  }
}
int count_out() {
  int out = std::count(colors, colors + n, -1);
  out += (n - out) % 2;
  return out;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    arch[x][y] = arch[y][x] = true;
  }
  int count_cycles = 0;
  for (int i = 1; i <= n; i++) {
    if (!explored[i]) {
      dfs(i);
    }
  }
  cout << count_out() << endl;
  return 0;
}
