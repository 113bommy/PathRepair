#include <bits/stdc++.h>
using namespace std;
mt19937 rnd;
const int N = 85, K = 15;
const int inf = 1e9 + 7;
int a[N][N];
int col[N];
int dist[K][N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  int ans = inf;
  for (int kk = 1; kk <= 200; kk++) {
    for (int i = 1; i <= n; i++) {
      col[i] = rnd() % 2 + 1;
    }
    dist[1][1] = inf;
    for (int i = 2; i <= n; i++) {
      if (col[i] == col[1]) {
        dist[1][i] = inf;
      } else {
        dist[1][i] = a[1][i];
      }
    }
    for (int t = 2; t <= k; t++) {
      for (int i = 1; i <= n; i++) {
        dist[t][i] = inf;
        for (int j = 1; j <= n; j++) {
          if (col[i] == col[j]) {
            continue;
          }
          dist[t][i] = min(dist[t][i], dist[t - 1][j] + a[j][i]);
        }
      }
    }
    ans = min(ans, dist[k][1]);
  }
  cout << ans << "\n";
  return 0;
}
