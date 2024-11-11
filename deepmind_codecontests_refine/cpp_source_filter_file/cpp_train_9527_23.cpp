#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
long long gcd(long long a, long long b) { return (a ? gcd(b % a, a) : b); }
long long power(long long a, long long n) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
    }
    n >>= 1;
    a *= a;
  }
  return p;
}
char t[12][12][12];
int ans = 0, vis[12][12][12], k, m, n;
void dfs(int x, int y, int z) {
  ans++;
  vis[x][y][z] = 1;
  if (x - 1 >= 0 && !vis[x - 1][y][z] && t[x - 1][y][z] == '.')
    dfs(x - 1, y, z);
  if (x + 1 < k && !vis[x + 1][y][z] && t[x + 1][y][z] == '.') dfs(x + 1, y, z);
  if (y - 1 >= 0 && !vis[x][y - 1][z] && t[x][y - 1][z] == '.')
    dfs(x, y - 1, z);
  if (y + 1 < m && !vis[x][y + 1][z] && t[x][y + 1][z] == '.') dfs(x, y + 1, z);
  if (z - 1 >= 0 && !vis[x][y][z - 1] && t[x][y][z - 1] == '.')
    dfs(x, y, z - 1);
  if (z + 1 < n && !vis[x][y][z + 1] && t[x][y][z + 1] == '.') dfs(x, y, z + 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  int x, y;
  cin >> k >> n >> m;
  for (int(i) = 0; (i) < (k); (i)++) {
    for (int(j) = 0; (j) < (n); (j)++) {
      cin >> t[i][j];
    }
  }
  cin >> x >> y;
  if (t[0][x - 1][y - 1] == '.') dfs(0, x - 1, y - 1);
  cout << ans;
  return 0;
}
