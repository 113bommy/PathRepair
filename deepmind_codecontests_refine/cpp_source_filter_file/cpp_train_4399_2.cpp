#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, t;
  cin >> n >> m >> t;
  vector<string> arr(n);
  for (long long i = 0; i < n; i++) cin >> arr[i];
  vector<vector<long long> > vis(n, vector<long long>(m, LLONG_MAX));
  queue<pair<long long, long long> > q;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if ((j + 1 < m && arr[i][j + 1] == arr[i][j]) ||
          (j - 1 >= 0 && arr[i][j - 1] == arr[i][j]) ||
          (i + 1 < n && arr[i + 1][j] == arr[i][j]) ||
          (j - 1 >= 0 && arr[i][j - 1] == arr[i][j])) {
        vis[i][j] = 0;
        q.push({i, j});
      }
    }
  }
  while (!q.empty()) {
    auto c = q.front();
    q.pop();
    long long i = c.first, j = c.second;
    if (i + 1 < n && vis[i + 1][j] == LLONG_MAX) {
      vis[i + 1][j] = vis[i][j] + 1;
      q.push({i + 1, j});
    }
    if (j + 1 < m && vis[i][j + 1] == LLONG_MAX) {
      vis[i][j + 1] = vis[i][j] + 1;
      q.push({i, j + 1});
    }
    if (i - 1 >= 0 && vis[i - 1][j] == LLONG_MAX) {
      vis[i - 1][j] = vis[i][j] + 1;
      q.push({i - 1, j});
    }
    if (j - 1 >= 0 && vis[i][j - 1] == LLONG_MAX) {
      vis[i][j - 1] = vis[i][j] + 1;
      q.push({i, j - 1});
    }
  }
  long long i, j, k, v;
  while (t--) {
    cin >> i >> j >> k;
    i--;
    j--;
    v = arr[i][j] - '0';
    if (vis[i][j] >= k)
      cout << v << "\n";
    else if (vis[i][j] % 2 == k % 2)
      cout << v << "\n";
    else
      cout << !v << "\n";
  }
}
