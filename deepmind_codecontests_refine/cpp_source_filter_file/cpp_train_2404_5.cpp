#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long gcd(long long p, long long q) { return q == 0 ? p : gcd(q, p % q); }
int to[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
long long n, m, k, ans, a[30][30];
map<long long, long long> ma[30][30];
void dfs(int x, int y, long long s) {
  if (x > n || y > m) return;
  if (x + y == (n + m) / 2) {
    ma[x][y][s]++;
    return;
  }
  dfs(x + 1, y, s ^ a[x + 1][y]);
  dfs(x, y + 1, s ^ a[x][y + 1]);
}
void DFS(int x, int y, long long s) {
  if (x < 1 || y < 1) return;
  if (x + y == (n + m) / 2) {
    ans += ma[x][y][k ^ s ^ a[x][y]];
    return;
  }
  DFS(x - 1, y, s ^ a[x - 1][y]);
  DFS(x, y - 1, s ^ a[x][y - 1]);
}
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  dfs(1, 1, a[1][1]);
  DFS(n, m, a[n][m]);
  cout << ans << endl;
  return 0;
}
