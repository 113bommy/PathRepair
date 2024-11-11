#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
const int INF = 1e9;
int atk[N];
int c[N];
int g[N];
int f[2 * N][N];
int s[N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> atk[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i <= n + m; i++) {
    cin >> g[i];
  }
  reverse(atk + 1, atk + n + 1);
  reverse(c + 1, c + n + 1);
  for (int i = 1; i <= n + m; i++) {
    for (int j = 1; j <= n; j++) f[i][j] = -INF;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int cnt = 1;
    for (int j = n; j >= 1; j--) {
      if (f[atk[i]][j - 1] == -INF) continue;
      f[atk[i]][j] = max(f[atk[i]][j], f[atk[i]][j - 1] + g[atk[i]] - c[i]);
    }
    for (int j = atk[i], k = n; j < n + m; j++, k >>= 1) {
      for (int s = 0; s <= k; s++) {
        f[j + 1][s >> 1] = max(f[j + 1][s >> 1], f[j][s] + (s >> 1) * g[j + 1]);
      }
    }
  }
  cout << f[n + m][0] << endl;
}
