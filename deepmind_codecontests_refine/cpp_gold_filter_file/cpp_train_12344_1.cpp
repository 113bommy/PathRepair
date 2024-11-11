#include <bits/stdc++.h>
using namespace std;
struct sub {
  int dp[5][5];
  sub() {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        dp[i][j] = 200000;
      }
      dp[i][i] = 0;
    }
  }
  sub operator+(const sub &q) const {
    sub r;
    for (int i = 0; i < 5; i++) r.dp[i][i] = 200000;
    for (int i = 0; i < 5; i++) {
      for (int j = i; j < 5; j++) {
        for (int k = j; k < 5; k++) {
          r.dp[i][k] = min(r.dp[i][k], dp[i][j] + q.dp[j][k]);
        }
      }
    }
    return r;
  }
};
int n, q;
sub seg[1 << 19];
char s[200005];
void in(int l, int r, int k) {
  if (l == r) {
    int o = k - (1 << 18) + 1;
    if (o >= n) return;
    if (s[o] == '2') {
      seg[k].dp[0][1] = 0;
      seg[k].dp[0][0] = 1;
    } else if (s[o] == '0') {
      seg[k].dp[1][2] = 0;
      seg[k].dp[1][1] = 1;
    } else if (s[o] == '1') {
      seg[k].dp[2][3] = 0;
      seg[k].dp[2][2] = 1;
    } else if (s[o] == '7') {
      seg[k].dp[3][4] = 0;
      seg[k].dp[3][3] = 1;
    } else if (s[o] == '6') {
      seg[k].dp[3][3] = 1;
      seg[k].dp[4][4] = 1;
    }
  } else {
    in(l, (r + l - 1) / 2, k * 2 + 1);
    in((l + r + 1) / 2, r, k * 2 + 2);
    seg[k] = seg[k * 2 + 1] + seg[k * 2 + 2];
  }
}
sub que(int a, int b, int l, int r, int k) {
  if (b < l || r < a) {
    sub r;
    return r;
  }
  if (a <= l && r <= b) return seg[k];
  return que(a, b, l, (l + r - 1) / 2, k * 2 + 1) +
         que(a, b, (l + r + 1) / 2, r, k * 2 + 2);
}
int main(void) {
  cin >> n >> q >> s;
  in(0, (1 << 18) - 1, 0);
  for (int i = 0; i < q; i++) {
    int a, b;
    sub p;
    cin >> a >> b;
    a--;
    b--;
    p = que(a, b, 0, (1 << 18) - 1, 0);
    if (p.dp[0][4] == 200000)
      cout << -1 << endl;
    else
      cout << p.dp[0][4] << endl;
  }
}
