#include <bits/stdc++.h>
int p[(int)(2e5 + 123)];
int f[(int)(2e5 + 123)];
int b[(int)(2e5 + 123)];
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= n; i++) cin >> f[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  priority_queue<int, vector<int>, greater<int>> q[5][5];
  for (int i = 1; i <= n; i++) {
    q[f[i]][b[i]].push(p[i]);
  }
  int m;
  cin >> m;
  while (m--) {
    int c;
    cin >> c;
    int ans = INT_MAX;
    int f, b;
    for (int i = 1; i <= 3; i++) {
      if ((!q[c][i].empty()) && q[c][i].top() < ans) {
        ans = q[c][i].top();
        f = c;
        b = i;
      }
    }
    for (int i = 1; i <= 3; i++) {
      if ((!q[i][c].empty()) && q[i][c].top() < ans) {
        ans = q[i][c].top();
        f = i;
        b = c;
      }
    }
    if (ans == INT_MAX) {
      ans = -1;
    } else {
      q[f][b].pop();
    }
    cout << ans << " ";
  }
  return 0;
}
