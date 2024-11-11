#include <bits/stdc++.h>
using namespace std;
int n, m;
int ans;
int a[400050];
int back[400050];
vector<int> edge[400050];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v;
    edge[v].push_back(u);
  }
  for (auto iter : edge[a[n]]) back[iter]++;
  for (int i = n - 1; i >= 1; i--) {
    if (back[a[i]] == n - i - ans)
      ans++;
    else {
      for (auto iter : edge[i]) back[iter]++;
    }
  }
  cout << ans << endl;
  return 0;
}
