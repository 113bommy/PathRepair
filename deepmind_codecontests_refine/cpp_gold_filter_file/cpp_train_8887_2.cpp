#include <bits/stdc++.h>
using namespace std;
const int nax = 504;
int n, m;
int x[nax], y[nax], rods[nax], dist[nax], ans[nax];
bool vis[nax];
bool ok(int start) {
  for (int i = 0; i < nax; i++) {
    vis[i] = false;
    ans[i] = -1;
  }
  for (int i = start; i <= n; i += 2) {
    bool possible = false;
    for (int j = 1; j <= m; j++) {
      if (!vis[j] && dist[i] == rods[j]) {
        vis[j] = true;
        ans[i] = j;
        possible = true;
        break;
      }
    }
    if (!possible) {
      return false;
    }
  }
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  x[0] = x[n];
  y[0] = y[n];
  x[n + 1] = x[1];
  y[n + 1] = y[1];
  for (int i = 1; i <= m; i++) {
    cin >> rods[i];
  }
  for (int i = 1; i <= n; i++) {
    dist[i] = abs(x[i] - x[i - 1]) + abs(x[i] - x[i + 1]) +
              abs(y[i] - y[i - 1]) + abs(y[i] - y[i + 1]);
  }
  bool possible = ok(1);
  if (!possible) {
    possible |= ok(2);
  }
  if (!possible) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
