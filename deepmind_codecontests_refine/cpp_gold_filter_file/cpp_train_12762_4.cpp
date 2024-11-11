#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int p[n + 5], BC[n + 5], FC[n + 5];
  for (int i = 0; i < n; ++i) cin >> p[i];
  for (int i = 0; i < n; ++i) cin >> BC[i];
  for (int i = 0; i < n; ++i) cin >> FC[i];
  priority_queue<int> pq[4][4];
  for (int i = 0; i < n; ++i) {
    if (FC[i] > BC[i]) swap(FC[i], BC[i]);
    pq[FC[i]][BC[i]].push(-p[i]);
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    int w = -1;
    int ans = 1e9 + 5;
    for (int j = 1; j <= 3; ++j) {
      int y = x;
      int z = j;
      if (y > z) swap(z, y);
      if (!pq[y][z].empty() && -pq[y][z].top() < ans) {
        ans = -pq[y][z].top();
        w = (y == x) ? z : y;
      }
    }
    if (w == -1) {
      cout << w << " ";
      continue;
    }
    if (x > w) swap(x, w);
    pq[x][w].pop();
    cout << ans << " ";
  }
  return 0;
}
