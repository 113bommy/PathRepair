#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 2e5 + 10;
vector<int> edge[N];
LL sum[2], num[2], ans;
void up(int d) { ans += (d * num[d & 1] + sum[d & 1]) / 2; }
int dfs(int x, int fa, int d) {
  int sz = 1;
  LL k = 0;
  up(d);
  up(d + 1);
  sum[d & 1] += d;
  num[d & 1]++;
  for (int y : edge[x])
    if (y != fa) {
      int s = dfs(y, x, d + 1);
      k += sz * s;
      sz += s;
    }
  ans -= d * k;
  return sz;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(1, 0, 0);
  cout << ans << endl;
}
