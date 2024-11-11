#include <bits/stdc++.h>
using namespace std;
int main() {
  const int inf = 1e9;
  int n, m;
  cin >> n >> m;
  vector<vector<int>> to(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    to.at(a - 1).push_back(b - 1);
  }
  int shortest = inf;
  for (int i = 0; i < n; i++) {
    vector<bool> seen(n);
    queue<pair<int, int>> q;
    q.emplace(i, 0);
    while (!q.empty()) {
      int present = q.front().first, d = q.front().second;
      q.pop();
      seen.at(present) = d;
      for (int next : to.at(present)) {
        if (seen.at(next)) {
          if (next == i) {
            shortest = min(shortest, d + 1);
          }
          continue;
        }
        q.emplace(next, d + 1);
      }
    }
  }
  if (shortest == inf) {
    cout << -1 << endl;
    return 0;
  }
  cout << 0 << endl;
}
