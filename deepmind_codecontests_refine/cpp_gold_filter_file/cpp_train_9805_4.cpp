#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  return (!b) ? a : gcd(b, a % b);
}
int n, m;
list<int> adj[8];
int vis[8];
int gr[8][8];
void solve() {
  cin >> n >> m;
  if (n <= 6 || m == 0) {
    cout << m;
    return;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    gr[x][y] = 1;
    gr[y][x] = 1;
  }
  int ans = m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int re = 0;
      for (int k = 1; k <= n; k++) {
        if (gr[i][k] && gr[j][k]) {
          re += 1;
        }
      }
      ans = min(ans, re);
    }
  }
  cout << m - ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (fopen("input.txt", "r")) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  int t = 1;
  while (t--) {
    solve();
  }
}
