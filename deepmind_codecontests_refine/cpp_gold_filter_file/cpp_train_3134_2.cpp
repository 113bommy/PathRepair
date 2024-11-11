#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int M = 5.1e6 + 5;
const int B = 10;
int n, q;
int h[M];
int go[B + 1][N];
int prod[128], cnt[128];
vector<int> dv[N];
int best[8][M];
int main() {
  for (int i = 2; i * i < M; i++) {
    if (!h[i]) {
      for (int j = i; j < M; j += i) h[j] = i;
    }
  }
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    while (h[x]) {
      int y = h[x], c = 0;
      while (x % y == 0) {
        x /= y;
        c ^= 1;
      }
      if (c) dv[i].push_back(y);
    }
    if (x > 1) dv[i].push_back(x);
    assert(dv[i].size() <= 7);
  }
  for (int need = 0; need <= B; need++) {
    go[need][n + 1] = n + 1;
    memset(best, 0, sizeof(best));
    for (int i = n; i >= 1; i--) {
      go[need][i] = go[need][i + 1];
      prod[0] = 1;
      cnt[0] = dv[i].size();
      for (int mask = 0; mask < (1 << dv[i].size()); mask++) {
        if (mask) {
          int lb = mask & -mask;
          int k = 31 - __builtin_clz(lb);
          prod[mask] = prod[mask ^ lb] * dv[i][k];
          cnt[mask] = cnt[mask ^ lb] - 1;
        }
        if (cnt[mask] <= need and need - cnt[mask] <= 7 and
            best[need - cnt[mask]][prod[mask]]) {
          go[need][i] = min(go[need][i], best[need - cnt[mask]][prod[mask]]);
        }
        best[cnt[mask]][prod[mask]] = i;
      }
    }
  }
  for (int i = 1; i <= q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    for (int i = 0; i <= B + 1; i++) {
      if (i > B or go[i][l] <= r) {
        printf("%d\n", i);
        break;
      }
    }
  }
  return 0;
}
