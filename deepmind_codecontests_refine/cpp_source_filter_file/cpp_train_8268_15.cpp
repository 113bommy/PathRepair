#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
using ll = long long;
const ll mod = 1e9 + 7;
const int maxn = 1010;
int n, m, q;
int dp[4][maxn][maxn];
int g[maxn][maxn];
void build(int op, int i) {
  int start, end, inc;
  if (op == 0) {
    start = 1;
    end = m + 1;
    inc = 1;
  }
  if (op == 1) {
    start = m;
    end = 0;
    inc = -1;
  }
  if (op == 2) {
    start = 0;
    end = n + 1;
    inc = 1;
  }
  if (op == 3) {
    start = n;
    end = 0;
    inc = -1;
  }
  for (int j = start, bloc = 0; j != end; j += inc) {
    bloc++;
    if (op < 2) {
      if (!g[i][j]) bloc = 0;
      dp[op][i][j] = bloc;
    } else {
      if (!g[j][i]) bloc = 0;
      dp[op][j][i] = bloc;
    }
  }
}
int qry(int op, int x, int y) {
  int res = 0;
  int M = dp[op][x][y];
  if (op < 2) {
    int u = x;
    int d = x;
    while (M > 0) {
      while (dp[op][u][y] == M) u--;
      while (dp[op][d][y] == M) d++;
      res = max(res, (d - u - 1) * M);
      M--;
    }
    return res;
  } else {
    int l = y;
    int r = y;
    while (M > 0) {
      while (dp[op][x][l] == M) l--;
      while (dp[op][x][r] == M) r++;
      res = max(res, (r - l - 1) * M);
      M--;
    }
    return res;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> g[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    build(0, i);
    build(1, i);
  }
  for (int j = 1; j <= m; j++) {
    build(2, j);
    build(3, j);
  }
  while (q--) {
    int typ;
    int x, y;
    cin >> typ;
    cin >> x >> y;
    if (typ == 1) {
      g[x][y] ^= 1;
      build(0, x);
      build(1, x);
      build(2, y);
      build(3, y);
    }
    if (typ == 2) {
      int res = 0;
      for (int o = 0; o < 4; o++) {
        res = max(res, qry(o, x, y));
      }
      cout << res << "\n";
    }
  }
  return 0;
}
