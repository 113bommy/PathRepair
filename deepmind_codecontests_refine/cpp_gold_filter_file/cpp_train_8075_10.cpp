#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 22;
int n;
long long f[N][M][2], a[N], sl[N];
vector<int> v[N];
long long ans = 0;
void dfs(int x, int tr) {
  sl[x] = 1;
  ans += a[x];
  for (int i = 0; i < M; i++) {
    f[x][i][(a[x] >> i) & 1]++;
  }
  for (auto u : v[x])
    if (u != tr) {
      dfs(u, x);
      sl[x] += sl[u];
      for (int i = 0; i < M; i++) {
        ans += (1 << i) * (f[x][i][0] * f[u][i][1] + f[x][i][1] * f[u][i][0]);
        f[x][i][((a[x] >> i) & 1) ^ 0] += f[u][i][0];
        f[x][i][((a[x] >> i) & 1) ^ 1] += f[u][i][1];
      }
    }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1, 0);
  cout << ans;
  return 0;
}
