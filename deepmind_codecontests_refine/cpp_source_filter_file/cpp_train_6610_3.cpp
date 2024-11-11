#include <bits/stdc++.h>
using namespace std;
const int N = 160, inf = 1e9 + 10;
int n, m;
bool a[N][N], b[N][N], lasb[N][N];
int f[N][N];
pair<int, pair<int, int> > edge[N];
int ans = inf;
bitset<N> ar[N], br[N];
void mult(const bool a[N][N], const bool b[N][N], bool c[N][N]) {
  for (int i = 1; i <= n; i++) {
    ar[i].reset();
    for (int j = 1; j <= n; j++) {
      ar[i][j] = a[i][j];
    }
  }
  for (int j = 1; j <= n; j++) {
    br[j].reset();
    for (int i = 1; i <= n; i++) {
      br[j][i] = b[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      c[i][j] = (ar[i] & br[j]).any();
    }
  }
}
void ksm(const bool a[N][N], int y, bool c[N][N]) {
  static bool f[N][N];
  memcpy(f, a, sizeof f);
  for (; y; y >>= 1) {
    if (y & 1) mult(c, f, c);
    mult(f, f, f);
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, d;
    scanf("%d %d %d", &u, &v, &d);
    edge[i] = make_pair(d, make_pair(u, v));
  }
  sort(edge + 1, edge + 1 + m);
  b[1][1] = 1;
  for (int e = 1; e <= m; e++) {
    ksm(a, edge[e].first - edge[e - 1].first, b);
    a[edge[e].second.first][edge[e].second.second] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
        if (a[i][j]) {
          f[i][j] = 1;
        } else
          f[i][j] = inf;
    }
    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++)
        if (i != k) {
          for (int j = 1; j <= n; j++)
            if (i != j && j != k) {
              f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
      if (b[1][i]) {
        ans = min(ans, edge[e].first + f[i][n]);
      }
  }
  if (ans == inf) {
    printf("Impossible\n");
  } else
    printf("%d\n", ans);
}
