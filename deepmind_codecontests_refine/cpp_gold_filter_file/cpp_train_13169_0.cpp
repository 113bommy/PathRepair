#include <bits/stdc++.h>
using namespace std;
const int T = 30;
bool isBan[20];
int adj[T][20][20];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
void constructAdj(int n, int m) {
  int id = 0, i, j, k, ni, nj;
  int g = n * m;
  for (i = 0; i < g; ++i) {
    for (j = 0; j < g; ++j) {
      adj[0][i][j] = 0;
    }
  }
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      if (isBan[i * m + j]) {
        continue;
      }
      id = i * m + j;
      adj[0][id][id] = 1;
      for (k = 0; k < 4; ++k) {
        ni = i + dx[k], nj = j + dy[k];
        if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
          if (!isBan[ni * m + nj]) {
            adj[0][ni * m + nj][id] = 1;
          }
        }
      }
    }
  }
}
const int mod = 1e9 + 7;
int add(int x, int y) { return ((x + y) % mod + mod) % mod; }
int mul(int x, int y) { return (long long)x * y % mod; }
void mul(int r[20][20], int x[20][20], int y[20][20], int tot) {
  int i, j, k;
  for (i = 0; i < tot; ++i) {
    for (j = 0; j < tot; ++j) {
      r[i][j] = 0;
    }
  }
  for (i = 0; i < tot; ++i) {
    for (j = 0; j < tot; ++j) {
      for (k = 0; k < tot; ++k) {
        r[i][j] = add(r[i][j], mul(x[i][k], y[k][j]));
      }
    }
  }
}
int num[2][20];
void getNew(int bit, int ad[20][20], int tot) {
  int nbit = bit ^ 1;
  memset(num[nbit], 0, sizeof(num[nbit]));
  for (int i = 0; i < tot; ++i) {
    for (int j = 0; j < tot; ++j) {
      num[nbit][j] = add(num[nbit][j], mul(num[bit][i], ad[i][j]));
    }
  }
}
void solve() {
  int n, m, q;
  scanf("%d %d %d ", &n, &m, &q);
  int curTime = 1;
  num[0][0] = 1;
  constructAdj(n, m);
  int bit = 0;
  for (int i = 0; i < q; ++i) {
    int type, x, y, t;
    scanf(" %d %d %d %d ", &type, &x, &y, &t);
    --x, --y;
    int id = x * m + y;
    int dt = t - curTime;
    for (int ind = 1, t = 2; t <= dt; ++ind, t *= 2) {
      memset(adj[ind], 0, sizeof(adj[ind]));
      mul(adj[ind], adj[ind - 1], adj[ind - 1], n * m);
    }
    for (int ind = 0; ind < 30; ++ind) {
      if (dt & (1 << ind)) {
        getNew(bit, adj[ind], n * m);
        bit ^= 1;
      }
    }
    curTime = t;
    if (type == 1) {
      printf("%d\n", num[bit][id]);
    } else if (type == 2) {
      isBan[id] = 1;
      constructAdj(n, m);
      num[bit][id] = 0;
    } else {
      assert(type == 3);
      isBan[id] = 0;
      constructAdj(n, m);
    }
  }
}
int main() {
  solve();
  return 0;
}
