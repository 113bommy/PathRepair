#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int> > nei[100005];
int from[100005], to[100005], cost[100005];
long long cnt[100005], yp[100005];
void dfs(int root, int parent) {
  cnt[root] = 1;
  for (int i = 0; i < nei[root].size(); i++) {
    if (nei[root][i].first != parent) {
      dfs(nei[root][i].first, root);
      cnt[root] += cnt[nei[root][i].first];
      yp[nei[root][i].second] =
          1ll * cnt[nei[root][i].first] * (n - cnt[nei[root][i].first]);
    }
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> from[i] >> to[i] >> cost[i];
    from[i]--;
    to[i]--;
    nei[from[i]].push_back(make_pair(to[i], i));
    nei[to[i]].push_back(make_pair(from[i], i));
  }
  dfs(0, -1);
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ans += yp[i] * cost[i];
  }
  double d = 6.0 / n / (n - 1);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    ans -= yp[a] * (cost[a] - b);
    cost[a] = b;
    cout << setprecision(10) << d * ans << endl;
  }
  return 0;
}
