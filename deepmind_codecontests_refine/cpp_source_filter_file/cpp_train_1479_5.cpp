#include <bits/stdc++.h>
using namespace std;
vector<long long int> arr;
vector<long long int> adj[100005];
void dfs(long long int child, long long int par) {
  arr.push_back(child);
  for (auto i : adj[child]) {
    if (i == par) continue;
    dfs(i, child);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    long long int n;
    cin >> n;
    long long int color[3][n + 1];
    for (long long int i = 0; i < 3; i++) {
      for (long long int j = 1; j <= n; j++) cin >> color[i][j];
    }
    for (long long int i = 0; i < n - 1; i++) {
      long long int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    vector<long long int> one;
    for (long long int i = 1; i <= n; i++) {
      if (adj[i].size() > 2) {
        cout << -1 << endl;
        return 0;
      } else if (adj[i].size() == 1)
        one.push_back(i);
    }
    dfs(one[0], 0);
    long long int order[3] = {0, 0, 0};
    long long int ans = INT_MAX;
    for (long long int i = 0; i < 3; i++) {
      for (long long int j = 0; j < 3; j++) {
        for (long long int k = 0; k < 3; k++) {
          if (i != j && j != k && i != k) {
            long long int temp = 0;
            for (long long int l = 0; l < n; l++) {
              if (l % 3 == 0) {
                temp += color[i][arr[l]];
              } else if (l % 3 == 1) {
                temp += color[j][arr[l]];
              } else
                temp += color[k][arr[l]];
            }
            if (temp < ans) {
              ans = temp;
              order[0] = i;
              order[1] = j;
              order[2] = k;
            }
          }
        }
      }
    }
    long long int ans1[n + 1];
    ans1[arr[0]] = order[0];
    ans1[arr[1]] = order[1];
    ans1[arr[2]] = order[2];
    for (long long int i = 3; i < n; i++) {
      ans1[arr[i]] = ans1[arr[i - 3]];
    }
    cout << ans << endl;
    for (long long int i = 1; i <= n; i++) cout << ans1[i] + 1 << " ";
    cout << endl;
  }
  return 0;
}
