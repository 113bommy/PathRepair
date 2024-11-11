#include <bits/stdc++.h>
using namespace std;
void func(void) {
  freopen("input.c", "r", stdin);
  freopen("output.c", "w", stdout);
}
const int N = 2e5 + 100;
vector<long long> a[N];
int vis[N];
int edge, m;
long long cnt, maxi;
long long tim[N][2];
void dfs(int x, int edgeNo, long long cnt, int valid, int index) {
  vis[x] = 1;
  if (valid) {
    tim[x][index] = cnt;
  }
  maxi = max(maxi, cnt);
  if (x == m) {
    edge = edgeNo;
  }
  for (int i = 0; i < a[x].size(); i++) {
    long long y = a[x][i];
    if (!vis[y]) {
      dfs(y, edgeNo, cnt + 1, valid, index);
    }
  }
}
int main() {
  long long n, q, i, j = 0, temp, t, k, ans = 0, sum = 0, x, y, cnt = 0, fg = 0,
                     mx = 0, mx1 = 0, mn = 8000000000000000000,
                     mn1 = 8000000000000000000;
  cin >> n >> m;
  for (int i = 0; i < n - 1; i++) {
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  for (int i = 0; i < a[1].size(); i++) {
    vis[1] = 1;
    int yy = a[1][i];
    dfs(yy, i, 0, 0, 0);
  }
  memset(vis, 0, sizeof(vis));
  vis[1] = 1;
  dfs(a[1][edge], edge, 1, 1, 0);
  memset(vis, 0, sizeof(vis));
  vis[1] = 1;
  for (int i = 0; i < a[m].size(); i++) {
    vis[1] = 1;
    vis[m] = 1;
    int yy = a[m][i];
    dfs(yy, i, 1, 1, 1);
  }
  ans = 0;
  for (int i = 2; i <= n; i++) {
    if (tim[i][0] > tim[i][1]) {
      ans = max(ans, tim[i][0]);
    }
  }
  cout << 2 * ans << endl;
  return 0;
}
