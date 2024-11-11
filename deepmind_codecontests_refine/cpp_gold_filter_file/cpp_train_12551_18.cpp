#include <bits/stdc++.h>
using namespace std;
const int siz = 350;
long long f[105][60];
int bas = 25;
long long g[60];
vector<long long> v[105];
int n, m;
void add(long long &x, long long y) {
  x = x + y;
  x %= 1000000007;
}
void dfs(int x, int p) {
  f[x][bas + 1] = 1;
  f[x][bas - m] = 1;
  for (int i = 0; i < v[x].size(); i++) {
    int t = v[x][i];
    if (t == p) continue;
    dfs(t, x);
    memset(g, 0, sizeof(g));
    for (int j = bas - m; j <= bas + m; j++) {
      for (int k = bas - m; k <= bas + m; k++) {
        long long ct = f[x][j] * f[t][k] % 1000000007;
        if (!ct) continue;
        int a = j - bas, b = k - bas;
        if (a <= 0 and b <= 0) {
          add(g[min(a, b + 1) + bas], ct);
        }
        if (a > 0 and b > 0) {
          add(g[max(a, b + 1) + bas], ct);
        }
        if (a <= 0 and b > 0) {
          if (-a >= b)
            add(g[a + bas], ct);
          else
            add(g[b + 1 + bas], ct);
        }
        if (a > 0 and b <= 0) {
          if (a > -b)
            add(g[a + bas], ct);
          else
            add(g[b + 1 + bas], ct);
        }
      }
    }
    memcpy(f[x], g, sizeof(g));
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1, 0);
  long long ans = 0;
  for (int i = bas - m; i <= bas; i++) add(ans, f[1][i]);
  cout << ans;
  return 0;
}
