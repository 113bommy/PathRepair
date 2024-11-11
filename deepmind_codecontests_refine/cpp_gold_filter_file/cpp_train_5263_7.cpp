#include <bits/stdc++.h>
const int a = 1 << 18;
using namespace std;
long long odp[a], n, k, res;
vector<int> v[a];
void dfs(int x, int pop) {
  for (int i = 0; i < v[x].size(); i++) {
    if (v[x][i] != pop)
      dfs(v[x][i], x), odp[x] += odp[v[x][i]],
          res += min(odp[v[x][i]], k - odp[v[x][i]]);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> k;
  k *= 2;
  for (int i = 0; i < k; i++) {
    int b;
    cin >> b;
    odp[b] = 1;
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1, 1);
  cout << res;
}
