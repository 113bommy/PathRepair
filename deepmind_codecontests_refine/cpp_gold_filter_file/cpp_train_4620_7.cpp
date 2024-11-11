#include <bits/stdc++.h>
using namespace std;
const long long MOD = 777777777;
const long long INFL = 1000000000LL * 1000000000LL + 1000LL;
const int INF = 1000000000 + 1000;
struct Node {
  long long dp[4][4];
  bool pusty;
  Node() {
    for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= 3; j++) {
        dp[i][j] = 0;
      }
    }
    pusty = true;
  }
  Node(int x) {
    for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= 3; j++) {
        dp[i][j] = 0;
      }
    }
    if (x == 0) {
      for (int i = 1; i <= 3; i++) {
        dp[i][i] = 1;
      }
    } else {
      dp[x][x] = 1;
    }
    pusty = false;
  }
  void wypisz() const {
    if (!pusty) {
      printf("nie ");
    }
    printf("pusty\n");
    for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= 3; j++) {
        if (dp[i][j] > 0) {
          printf("%d %d   %lld\n", i, j, dp[i][j]);
        }
      }
    }
  }
  long long get_res() {
    long long r = 0;
    for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= 3; j++) {
        r += dp[i][j];
      }
    }
    r %= MOD;
    return r;
  }
};
int dobry[4][4];
Node sklej(const Node& x, const Node& y) {
  if (x.pusty) {
    return y;
  }
  if (y.pusty) {
    return x;
  }
  Node res;
  for (int a = 1; a <= 3; a++) {
    for (int b = 1; b <= 3; b++) {
      res.dp[a][b] = 0;
      for (int c = 1; c <= 3; c++) {
        for (int d = 1; d <= 3; d++) {
          if (dobry[c][d]) {
            res.dp[a][b] += x.dp[a][c] * y.dp[d][b];
          }
        }
      }
      res.dp[a][b] %= MOD;
    }
  }
  res.pusty = false;
  return res;
}
struct Tree {
  static const int BASE = (1 << 17);
  Node tree[BASE * 2];
  void zmien(int pos, int co) {
    tree[pos + BASE] = Node(co);
    int ak = (pos + BASE) / 2;
    while (ak > 0) {
      tree[ak] = sklej(tree[ak * 2], tree[ak * 2 + 1]);
      ak /= 2;
    }
  }
  void init(int n) {
    for (int i = 1; i <= n; i++) {
      tree[BASE + i] = Node(0);
    }
    for (int i = BASE - 1; i > 0; i--) {
      tree[i] = sklej(tree[i * 2], tree[i * 2 + 1]);
    }
  }
};
Tree tree;
int n, m, pos, co;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      scanf("%d", &dobry[i][j]);
    }
  }
  tree.init(n);
  while (m--) {
    scanf("%d %d", &pos, &co);
    tree.zmien(pos, co);
    printf("%lld\n", tree.tree[1].get_res());
  }
}
