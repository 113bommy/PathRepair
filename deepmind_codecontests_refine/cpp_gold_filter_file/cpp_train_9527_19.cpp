#include <bits/stdc++.h>
using namespace std;
char p[11][11][11];
int n, m, k, t = 0;
bool test(int a, int b, int c) {
  return p[a][b][c] == '#' || a >= k || a < 0 || b >= n || b < 0 || c >= m ||
         c < 0;
}
void dfs(int a, int b, int c) {
  if (test(a, b, c)) return;
  p[a][b][c] = '#';
  t++;
  dfs(a + 1, b, c);
  dfs(a - 1, b, c);
  dfs(a, b + 1, c);
  dfs(a, b - 1, c);
  dfs(a, b, c + 1);
  dfs(a, b, c - 1);
}
int main() {
  cin >> k >> n >> m;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      cin >> p[i][j];
    }
  }
  int x, y;
  cin >> x >> y;
  dfs(0, x - 1, y - 1);
  cout << t;
  return 0;
}
