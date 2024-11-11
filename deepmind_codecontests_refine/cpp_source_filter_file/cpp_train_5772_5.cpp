#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int A[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> A[i][j];
  }
  int x, y;
  vector<pair<int, int>> query;
  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    query.push_back({x - 1, y - 1});
  }
  vector<vector<int>> mapping(n + 1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (A[i][j] == 1) mapping[i].push_back(j);
    }
  }
  int ans[n], multi[n];
  memset(ans, 0, sizeof(ans));
  memset(multi, 0, sizeof(multi));
  for (int i = 0; i < k; i++) {
    ans[query[i].first]--;
    multi[query[i].second]++;
  }
  for (int i = 0; i < n; i++) {
    for (auto c : mapping[i]) {
      ans[i] += multi[c];
    }
    cout << ans[i] << " ";
  }
  return 0;
}
