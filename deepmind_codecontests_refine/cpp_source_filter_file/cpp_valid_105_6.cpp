#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3e3;
uint16_t a[N], lst[N], nxt[N], cnxt[20], dp[N][N + 1];
int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i], --a[i];
    }
    memset(lst, 0, n * sizeof *lst);
    for (int i = 0; i < n; ++i) {
      ++lst[a[i]];
    }
    int w = -1, r = 0, purged = 0;
    while (r < n) {
      if (w >= 0 && a[w] == a[r]) {
        if (--lst[a[r++]] == 1) {
          --w;
          ++purged;
        }
      } else if (lst[a[r]] == 1) {
        ++r;
        ++purged;
      } else {
        a[++w] = a[r++];
      }
    }
    memset(lst, -1, n * sizeof *lst);
    n = w + 1;
    memset(nxt, 127, n * sizeof *nxt);
    for (int i = 0; i < n; ++i) {
      if (lst[a[i]] != (uint16_t)-1) {
        nxt[lst[a[i]]] = i;
      }
      lst[a[i]] = i;
    }
    for (int i = n - 1; i > -1; --i) {
      auto* cnxte = cnxt;
      for (int z = nxt[i]; z < n; z = nxt[z]) {
        *cnxte++ = z;
      }
      *cnxte = n;
      cnxte = cnxt;
      for (int j = i + 1; j <= n; ++j) {
        int t = dp[i + 1][j] - 1;
        for (const auto* z = cnxt; z < cnxte; ++z) {
          t = max(t, dp[i + 1][*z] + dp[*z][j]);
        }
        dp[i][j] = t + 1;
        if (a[j] == a[i]) {
          ++cnxte;
        }
      }
    }
    cout << (n ? n - dp[0][n] : 0) - 1 + purged << '\n';
  }
}
