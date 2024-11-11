#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 1;
vector<int> g[maxn];
int sz[maxn];
long long sumr[maxn], sumt[maxn];
long long cntt[maxn][2], cntr[maxn][2];
long long ans = 0;
void dfs(int v, int p = 0) {
  sz[v] = 1;
  cntr[v][0] = 1;
  for (int x : g[v]) {
    if (x != p) {
      dfs(x, v);
      sz[v] += sz[x];
      cntr[v][0] += cntr[x][1];
      cntr[v][1] += cntr[x][0];
      sumr[v] += sumr[x] + sz[x];
    }
  }
  for (int x : g[v]) {
    if (x != p) {
      sumt[v] += (sumr[x] + sz[x]) * (sz[v] - sz[x] - 1);
      cntt[v][0] += cntr[x][0] * (cntr[v][1] - cntr[x][0]);
      cntt[v][0] += cntr[x][1] * (cntr[v][0] - cntr[x][1] - 1);
      cntt[v][1] += cntr[x][1] * (cntr[v][1] - cntr[x][0]);
      cntt[v][1] += cntr[x][0] * (cntr[v][0] - cntr[x][1] - 1);
    }
  }
  cntt[v][0] /= 2;
  cntt[v][1] /= 2;
  ans += sumr[v] + sumt[v];
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1);
  long long cur = 0;
  for (int i = 1; i <= n; i++) cur += cntr[i][1] + cntt[i][1];
  ans += cur;
  ans /= 2;
  cout << ans << endl;
}
