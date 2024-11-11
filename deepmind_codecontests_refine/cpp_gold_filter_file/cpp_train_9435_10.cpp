#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int p[100010];
int n, m;
bool check(int a, int b) {
  int x1 = a / m;
  int y1 = a % m;
  int x2 = b / m;
  int y2 = b % m;
  for (int i = 0; i < 4; i++)
    if (x1 + dx[i] == x2 && y1 + dy[i] == y2) return 1;
  return 0;
}
bool dfs(int pos) {
  if (pos == n * m) return 1;
  int x = pos / m;
  int y = pos % m;
  for (int i = pos; i < n * m; i++) {
    swap(p[pos], p[i]);
    if ((x && check(p[pos], p[(x - 1) * m + y])) ||
        (y && check(p[pos], p[x * m + y - 1])))
      continue;
    if (dfs(pos + 1)) return 1;
    swap(p[pos], p[i]);
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n * m; i++) p[i] = i;
  if (dfs(0)) {
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cout << p[i * m + j] + 1 << " ";
      cout << endl;
    }
  } else
    cout << "NO";
}
