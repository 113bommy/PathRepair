#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q;
const int INF = 0x3f3f3f3f;
char s[N];
struct Node {
  int dp[5][5];
  void update(int x) {
    memset(dp, 0x3f, sizeof(dp));
    if (x == -1) return;
    for (int i = 0; i <= 4; i++) dp[i][i] = 0;
    if (x == 2) {
      dp[0][0] = 1;
      dp[0][1] = 0;
      return;
    }
    if (x == 0) {
      dp[1][1] = 1;
      dp[1][2] = 0;
      return;
    }
    if (x == 1) {
      dp[2][2] = 1;
      dp[2][3] = 0;
      return;
    }
    if (x == 7) {
      dp[3][3] = 1;
      dp[3][4] = 0;
      return;
    }
    if (x == 6) {
      dp[3][3] = 1;
      dp[4][4] = 0;
      return;
    }
  }
} t[N << 2];
Node push_up(Node l, Node r) {
  Node now;
  now.update(-1);
  for (int i = 0; i <= 4; i++) {
    for (int j = 0; j <= 4; j++) {
      for (int k = 0; k <= 4; k++) {
        now.dp[i][j] = min(now.dp[i][j], l.dp[i][k] + r.dp[k][j]);
      }
    }
  }
  return now;
}
void build(int o, int l, int r) {
  if (l == r) {
    int x = s[l] - '0';
    t[o].update(x);
    return;
  }
  int mid = (l + r) >> 1;
  build(o << 1, l, mid);
  build(o << 1 | 1, mid + 1, r);
  t[o] = push_up(t[o << 1], t[o << 1 | 1]);
}
int L, R;
Node query(int o, int l, int r) {
  if (L <= l && r <= R) {
    return t[o];
  }
  int mid = (l + r) >> 1;
  if (R <= mid)
    return query(o << 1, l, mid);
  else if (L >= mid + 1)
    return query(o << 1 | 1, mid + 1, r);
  return push_up(query(o << 1, l, mid), query(o << 1 | 1, mid + 1, r));
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> q;
  cin >> s + 1;
  build(1, 1, n);
  while (q--) {
    cin >> L >> R;
    Node ans = query(1, 1, n);
    int res = ans.dp[0][4];
    if (ans.dp[0][4] == INF)
      res = -1;
    else
      res -= 2;
    cout << res << "\n";
  }
}
